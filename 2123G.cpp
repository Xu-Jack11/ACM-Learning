#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

// 对一个 a[i] 在给定 g 下的「单点转移函数」：
// f(x) = 新的 prev，若无法通过则返回 INF
struct Trans {
    ll g, m;
    ll ai, r, cb_end, cA_end;
    void init(ll _ai, ll _g, ll _m) {
        ai = _ai; g = _g; m = _m;
        r = ai % g;
        cb_end = ai - g;
        cA_end = ai + ((m - 1 - ai) / g) * g;
    }
    ll apply(ll x) const {
        if (x > cA_end) return INF;
        if (x <= cb_end) {
            ll base = r;
            if (x <= base) return base;
            return base + ((x - base + g - 1) / g) * g;
        }
        if (x <= ai) return ai;
        // ai < x <= cA_end
        return ai + ((x - ai + g - 1) / g) * g;
    }
};

// 线段树：在每个节点预存「区间合成转移函数」
// 节点合成：f_node(x) = f_right(f_left(x))
struct SegTree {
    int n;
    ll g, m;
    vector<Trans> tr;       // 叶节点的单点函数
    vector<pair<ll,ll>> seg; // 节点保存 (lo, hi)：即起始 x=lo 时合成到段尾的值 hi，若 lo=0 且 hi<INF 则通
    SegTree(int _n, ll _g, ll _m, const vector<ll>& a)
        : n(_n), g(_g), m(_m), tr(4*n), seg(4*n) {
        build(1,0,n-1,a);
    }
    void pull(int o) {
        auto &L = seg[o<<1], &R = seg[o<<1|1];
        // 先 L 再 R 合成
        ll new_lo = 0, new_hi;
        // L.lo = 0, L.hi
        if (L.second >= INF) {
            new_hi = INF;
        } else {
            ll mid = L.second;
            ll right_h = Trans{}, vv;
            // R.apply(mid)
            Trans tmp = tr[o<<1|1]; // dummy
            // 调用 R 节点转移：从 mid 出发
            // 我们只需要 mid -> hi
            // 用 R.seg 保存的 (0->rseg_hi)，先让 x'=R.apply(mid)，无法直接从 seg 区间，还得实际apply
            vv = apply_seg(o<<1|1, mid);
            new_hi = vv;
        }
        seg[o] = {0, new_hi};
    }
    // build leaf
    void build(int o,int l,int r,const vector<ll>& a) {
        if(l==r) {
            tr[o].init(a[l], g, m);
            seg[o] = {0, tr[o].apply(0)};
        } else {
            int md=(l+r)/2;
            build(o<<1,l,md,a);
            build(o<<1|1,md+1,r,a);
            // 合成子节点函数
            // 把左 seg[o<<1]: (0->hl), 右 leafapply(mid)
            // 为了通用，这里直接保存合成结果(0->最终)
            // 简化：对于每个节点我们只查询起始0
            ll hl = seg[o<<1].second;
            if(hl>=INF) seg[o]={0,INF};
            else {
                ll hr = apply_seg(o<<1|1, hl);
                seg[o]={0,hr};
            }
        }
    }
    ll apply_seg(int o, ll x) {
        // 如果节点正好在这一段：若 x>cA_end(叶) or seg[o].second<INF
        if(seg[o].first==0 && seg[o].second<INF && x==0) return seg[o].second;
        // 否则走到叶部
        return apply_leaf(1,0,n-1,o,x);
    }
    ll apply_leaf(int o,int l,int r,int target, ll x) {
        if(l==r) return tr[o].apply(x);
        int md=(l+r)/2;
        if(target<=md) {
            ll x2 = apply_leaf(o<<1,l,md,target,x);
            if(x2>=INF) return INF;
            return apply_leaf(o<<1|1,md+1,r,target,x2);
        } else {
            ll x1 = apply_leaf(o<<1,l,md,target,x);
            if(x1>=INF) return INF;
            return apply_leaf(o<<1|1,md+1,r,target,x1);
        }
    }
    // 点更新
    void update(int o,int l,int r,int p,ll v) {
        if(l==r) {
            tr[o].init(v,g,m);
            seg[o] = {0, tr[o].apply(0)};
        } else {
            int md=(l+r)/2;
            if(p<=md) update(o<<1,l,md,p,v);
            else update(o<<1|1,md+1,r,p,v);
            ll hl = seg[o<<1].second;
            if(hl>=INF) seg[o]={0,INF};
            else {
                ll hr = apply_seg(o<<1|1, hl);
                seg[o]={0,hr};
            }
        }
    }
    bool query() {
        return seg[1].second < INF;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--){
        int n,q; ll m;
        cin>>n>>m>>q;
        vector<ll>a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        vector<tuple<int,int,ll>> ops;
        vector<ll> gs;
        vector<pair<int,ll>> Q2;
        ops.reserve(q);
        for(int i=0;i<q;i++){
            int ty; cin>>ty;
            if(ty==1){
                int p; ll x; 
                cin>>p>>x;
                ops.emplace_back(1,p-1,x);
            }else{
                ll k; cin>>k;
                ll g = gcd(k,m);
                ops.emplace_back(2,-1,g);
                gs.push_back(g);
            }
        }
        // 枚举所有 g
        sort(gs.begin(),gs.end());
        gs.erase(unique(gs.begin(),gs.end()),gs.end());
        int D = gs.size();
        vector<SegTree*> segs(D,nullptr);
        for(int i=0;i<D;i++){
            ll g = gs[i];
            if(g==1) continue;
            segs[i] = new SegTree(n,g,m,a);
        }
        // 执行
        for(auto &op:ops){
            if(get<0>(op)==1){
                int p = get<1>(op);
                ll x = get<2>(op);
                a[p]=x;
                for(int i=0;i<D;i++){
                    if(gs[i]==1) continue;
                    segs[i]->update(1,0,n-1,p,x);
                }
            }else{
                ll g = get<2>(op);
                if(g==1){
                    cout<<"YES\n";
                }else{
                    int idx = lower_bound(gs.begin(),gs.end(),g)-gs.begin();
                    cout<<(segs[idx]->query()?"YES\n":"NO\n");
                }
            }
        }
        // 释放
        for(auto p:segs) if(p) delete p;
    }
    return 0;
}
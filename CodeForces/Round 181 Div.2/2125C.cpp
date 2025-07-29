#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long L, R;
    cin >> L >> R;
    auto countGood = [&](long long x) {
        if (x <= 0) return 0LL;
        long long res = 0;
        vector<long long> ps = {2, 3, 5, 7};
        int m = ps.size();
        for (int mask = 0; mask < (1 << m); ++mask) {
            long long prod = 1;
            int bits = 0;
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    bits++;
                    prod *= ps[i];
                }
            }
            if (mask == 0) {
                res += x;
            } else {
                long long t = x / prod;
                if (bits % 2 == 1) res -= t;
                else res += t;
            }
        }
        return res;
    };
    long long ans = countGood(R) - countGood(L - 1);
    cout << ans << '\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

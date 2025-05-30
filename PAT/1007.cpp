#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,maxn=0;
    cin >> n;
    int x=0,y=n-1;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pre(n + 1);
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int sum = pre[j] - pre[i - 1];
            if(sum> maxn)
            {
                maxn = sum;
                x = i - 1;
                y = j - 1;
            }
            else if(sum==maxn&&sum==0)
            {
                x=i-1;
                y=j-1;
            }
        }
    }
    cout << maxn << " " << a[x] << " " << a[y] << '\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

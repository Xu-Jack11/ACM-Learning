#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin>>s;
    int tmp=count(s.begin(), s.end(), '1');
    if (tmp <= k || k * 2 > n)
        cout << "Alice\n";
    else
        cout << "Bob\n";
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
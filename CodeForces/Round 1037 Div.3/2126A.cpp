#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    cout<<*min_element(s.begin(),s.end())<<'\n';
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

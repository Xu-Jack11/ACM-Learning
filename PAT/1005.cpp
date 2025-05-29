#include <bits/stdc++.h>
using namespace std;
map<char,string> mp={
    {'1',"one"},
    {'2',"two"},
    {'3',"three"},
    {'4',"four"},
    {'5',"five"},
    {'6',"six"},
    {'7',"seven"},
    {'8',"eight"},
    {'9',"nine"},
    {'0',"zero"}
};
void solve()
{
    string s;
    cin>>s;
    int x=0;
    for(auto c:s)
    x+=(c-'0');
    s=to_string(x);
    for(int i=0;i<s.size();i++)
    {
        if(i)
        cout<<' ';
        cout<<mp[s[i]];
    }
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

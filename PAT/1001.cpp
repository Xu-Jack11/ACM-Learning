#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b;
    cin>>a>>b;
    string s=to_string(a+b);
    if(s[0]=='-') cout<<'-';
    else s= ' '+s;
    for(int i=1;i<s.size();i++)
    {
        if((s.size()-i)%3==0 && i!=1) cout<<',';
        cout<<s[i];
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

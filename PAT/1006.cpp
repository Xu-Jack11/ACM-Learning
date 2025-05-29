#include <bits/stdc++.h>
using namespace std;
int cal(int hh,int mm,int ss)
{
    return hh*3600+mm*60+ss;
}
void solve()
{
    int n;
    int optime=INT_MAX,cltime=0;
    string opname,clname;
    cin>>n;
    while(n--)
    {
        string name;
        cin>>name;
        int h,m,s,hh,mm,ss;
        scanf("%d:%d:%d %d:%d:%d", &h, &m, &s, &hh, &mm, &ss);
        if(cal(h,m,s)<optime)
        {
            optime=cal(h,m,s);
            opname=name;
        }
        if(cal(hh,mm,ss)>cltime)
        {
            cltime=cal(hh,mm,ss);
            clname=name;
        }
    }
    cout<<opname<<" "<<clname<<'\n';
}
int main()
{
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

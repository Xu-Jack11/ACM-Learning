#include <bits/stdc++.h>
using namespace std;

void solve()
{
    double ans = 0.65, a[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[j];
        }
        if (a[0] == *max_element(a, a + 3))
        {
            ans *= a[0];
            cout<<"W ";
        }
        else if (a[1] == *max_element(a, a + 3))
        {
            ans *= a[1];
            cout<<"T ";
        }
        else
        {
            ans *= a[2];
            cout<<"L ";
        }
    }
    cout<<fixed<<setprecision(2)<<(ans-1)*2;
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

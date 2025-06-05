#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,b;
    cin>>n>>b;
    vector<int> a;
    while(n)
    {
        a.push_back(n % b);
        n /= b;
    }
    bool ans = true;
    int i = 0, j = (int)a.size() - 1;
    while (i < j) {
        if (a[i] != a[j]) {
            ans = false;
            break;
        }
        ++i;
        --j;
    }
    reverse(begin(a),end(a));
    cout << (ans ? "Yes" : "No") << "\n";
    for(int i=0;i<a.size();i++)
    {
        if(i == a.size() - 1)
            cout << a[i] << "\n";
        else
        cout<<a[i]<<' ';
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

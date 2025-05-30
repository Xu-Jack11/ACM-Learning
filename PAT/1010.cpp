#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128= __int128_t;
i128 cal(vector<ll> &A, ll radix)
{
    i128 res = 0;
    for (i128 i = 0; i < A.size(); i++)
    {
        res = res * (i128)radix + A[i];
        if(res < 0)
        {
            return LONG_LONG_MAX;
        }
    }
    return res;
}
void solve()
{
    string a, b;
    ll tag, radix;
    cin >> a >> b >> tag >> radix;
    vector<ll> A, B;
    for (ll i = 0; i < a.size(); i++)
    {
        if (isdigit(a[i]))
            A.push_back(a[i] - '0');
        else
            A.push_back(a[i] - 'a' + 10);
    }
    for (ll i = 0; i < b.size(); i++)
    {
        if (isdigit(b[i]))
            B.push_back(b[i] - '0');
        else
            B.push_back(b[i] - 'a' + 10);
    }
    if (tag == 2)
        swap(A, B);
    i128 x = cal(A, radix);
    ll l = (*max_element(B.begin(), B.end())) + 1, r = x;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        i128 tmp = cal(B, mid);
        if (tmp < x)
            l = mid + 1;
        else
            r = mid;
    }
    if (cal(B, l) == x)
        cout << l;
    else
        cout << "Impossible";
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    ll tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

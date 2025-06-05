#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> A(n), C(n), M(n), E(n);
    unordered_map<int, array<int, 4>> mp;
    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id >> C[i] >> M[i] >> E[i];
        A[i] = (C[i] + M[i] + E[i]) / 3;
        mp[id] = {A[i], C[i], M[i], E[i]};
    }
    sort(A.begin(), A.end(), greater<int>());
    sort(C.begin(), C.end(), greater<int>());
    sort(M.begin(), M.end(), greater<int>());
    sort(E.begin(), E.end(), greater<int>());
    for (auto &[id, arr] : mp)
    {
        arr[0] = lower_bound(A.begin(), A.end(), arr[0], greater<int>()) - A.begin() + 1;
        arr[1] = lower_bound(C.begin(), C.end(), arr[1], greater<int>()) - C.begin() + 1;
        arr[2] = lower_bound(M.begin(), M.end(), arr[2], greater<int>()) - M.begin() + 1;
        arr[3] = lower_bound(E.begin(), E.end(), arr[3], greater<int>()) - E.begin() + 1;
    }
    for (int i = 0; i < m; i++)
    {
        int id;
        cin >> id;
        if (!mp.contains(id))
        {
            cout << "N/A\n";
        }
        else
        {
            auto &[a, c, m, e] = mp[id];
            if (a <= c && a <= m && a <= e)
                cout << a << " A\n";
            else if (c <= a && c <= m && c <= e)
                cout << c << " C\n";
            else if (m <= a && m <= c && m <= e)
                cout << m << " M\n";
            else
                cout << e << " E\n";
        }
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

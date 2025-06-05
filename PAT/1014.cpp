#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m, k;
    vector<int> query;
    vector<deque<pair<int, int>>> windows;
    Solution(int n, int m, int k) : query(k), windows(n), n(n), m(m), k(k) {};
    bool isfull()
    {
        for (auto &i : windows)
        {
            if (i.size() < m)
                return false;
        }
        return true;
    }
    int getque()
    {
        int ret = -1, mins = m;
        for (int i = 0; i < n; i++)
        {
            if (windows[i].size() < mins)
            {
                mins = windows[i].size();
                ret = i;
            }
        }
        return ret;
    }
    void proceed_full()
    {
        int mint = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (windows[i].front().second < mint)
            {
                mint = windows[i].front().second;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (windows[i].front().second == mint)
            {
                query[windows[i].front().first] = mint;
                windows[i].pop_front();
                windows[i][0].second += mint;
            }
        }
    }
    void add(int i, int t)
    {
        while (isfull())
        {
            proceed_full();
        }
        windows[getque()].push_back({i, t});
    }
    void proceed_remain()
    {
        for (auto &i : windows)
        {

            while (!i.empty())
            {
                int t = i.front().second;
                query[i.front().first] = t;
                i.pop_front();
                if (i.empty())
                    break;
                i[0].second += t;
            }
        }
    }
};
void solve()
{
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    if (m == 1)
    {
        vector<int> query(k),windows(n);
        for (int i = 0; i < k; i++)
        {
            int t;
            cin >> t;
            query[i] = (*min_element(windows.begin(), windows.end())+=t);
        }
        while (q--)
        {
            int x;
            cin >> x;
            --x;
            if (query[x] > 540)
            {
                cout << "Sorry\n";
            }
            else
            {
                printf("%02d:%02d\n", 8 + query[x] / 60, query[x] % 60);
            }
        }
        return;
    }
    Solution ob(n, m, k);
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        ob.add(i, t);
    }
    ob.proceed_remain();
    while (q--)
    {
        int x;
        cin >> x;
        --x;
        if (ob.query[x] > 540)
        {
            cout << "Sorry\n";
        }
        else
        {
            printf("%02d:%02d\n", 8 + ob.query[x] / 60, ob.query[x] % 60);
        }
    }
}
signed main()
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

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> low = {
        "tret","jan","feb","mar","apr","may","jun",
        "jly","aug","sep","oct","nov","dec"
    };
    vector<string> high = {
        "","tam","hel","maa","huh","tou","kes",
        "hei","elo","syy","lok","mer","jou"
    };
    unordered_map<string,int> mp;
    for (int i = 0; i < 13; i++) {
        mp[low[i]] = i;
        if (i > 0) mp[high[i]] = i*13;
    }

    while (N--) {
        string s;
        getline(cin, s);
        if (s.empty()) { N++; continue; }

        // 地球数 -> 火星数
        if (isdigit(s[0])) {
            int x = stoi(s);
            int h = x / 13, l = x % 13;
            if (h && l)
                cout << high[h] << ' ' << low[l] << "\n";
            else if (h)
                cout << high[h] << "\n";
            else
                cout << low[l] << "\n";
        }
        // 火星数 -> 地球数
        else {
            int ans = 0;
            stringstream ss(s);
            string w;
            while (ss >> w) {
                ans += mp[w];
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
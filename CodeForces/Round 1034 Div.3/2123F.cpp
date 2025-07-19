#include <bits/stdc++.h>
using namespace std;
// Precompute all primes up to MAXN for permutation construction
const int MAXN = 100000;
vector<int> primes;
void init_primes() {
    vector<bool> isPrime(MAXN+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            if ((long long)i * i <= MAXN) {
                for (int j = i * i; j <= MAXN; j += i)
                    isPrime[j] = false;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<bool> used(n+1, false);
    vector<int> p(n+1, 0);
    // Build permutation by cycling unused multiples of each prime in descending order
    for (auto it = upper_bound(primes.begin(), primes.end(), n); it != primes.begin(); ) {
        --it;
        int prime = *it;
        vector<int> nodes;
        for (int k = prime; k <= n; k += prime) {
            if (!used[k]) nodes.push_back(k);
        }
        int sz = nodes.size();
        if (sz >= 2) {
            for (int i = 0; i < sz; ++i) {
                int u = nodes[i];
                int v = nodes[(i+1) % sz];
                p[u] = v;
                used[u] = true;
            }
        }
    }
    // Assign fixed points for any unassigned positions
    p[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!used[i]) p[i] = i;
    }
    for (int i = 1; i <= n; ++i) cout << p[i] << " ";
    cout << '\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    init_primes();
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}

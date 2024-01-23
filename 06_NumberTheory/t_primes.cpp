#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

const int MX = 1e7;
bool isPrime[MX];

void sieve() { // O(n log log n)
    fill(isPrime, isPrime + MX, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < MX; i++) {
        if (isPrime[i]) {
            for (int k = i * i; k < MX; k += i) {
                isPrime[k] = false;
            }
        }
    }
}

void solve() {
    Long x;
    cin >> x;
    Long sq = sqrt(x);

    if (sq * sq == x && isPrime[sq]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}

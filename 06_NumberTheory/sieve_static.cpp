#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

const int MX = 1e7;
bool isPrime[MX];

void sieve() { // O(n log log n)
    fill(isPrime, isPrime + MX, true);
    isPrime[0] = isPrime[1] = false;

    for (Long i = 2; i < MX; i++) {
        if (isPrime[i]) {
            for (Long k = i * i; k < MX; k += i) {
                isPrime[k] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (isPrime[i]) cout << i << " ";
    }

    cout << "\n";

    return 0;
}

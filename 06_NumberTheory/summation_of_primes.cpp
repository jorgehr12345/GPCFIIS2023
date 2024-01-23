#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

const int MX = 1e6 + 1;
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

Long sumPrimes[MX];

int main() { // O(MX + T)
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    sumPrimes[0] = 0;
    for (int i = 1; i < MX; i++) { // O(MX)
        if (isPrime[i]) {
            sumPrimes[i] = sumPrimes[i - 1] + i;
        } else {
            sumPrimes[i] = sumPrimes[i - 1];
        }
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        cout << sumPrimes[n] << "\n";
    }

    return 0;
}

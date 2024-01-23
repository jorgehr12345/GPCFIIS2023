#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

vector<bool> sieve(int n) { // O(n log log n)
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (Long i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (Long k = i * i; k <= n; k += i) {
                isPrime[k] = false;
            }
        }
    }

    return isPrime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<bool> isPrime = sieve(n);

    for (int i = 1; i <= n; i++) {
        if (isPrime[i]) cout << i << " ";
    }

    cout << "\n";

    return 0;
}
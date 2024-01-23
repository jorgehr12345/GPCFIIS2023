#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

const int MX = 1e7;
bool isPrime[MX];
int fact[MX];

// fact[7] = 7
// fact[9] = 3
// fact[12] = 2 o = 3

void sieve() { // O(n log log n)
    fill(isPrime, isPrime + MX, true);
    for (int i = 2; i < MX; i++) fact[i] = i;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < MX; i++) {
        if (isPrime[i]) {
            for (int k = i * i; k < MX; k += i) {
                isPrime[k] = false;
                fact[k] = i;
            }
        }
    }
}

struct Factor {
    int base, exp;
};

vector<Factor> factorize(int x) { // O(log x)
    vector<Factor> factors = {};
    while (x > 1) {
        int e = 0;
        int f = fact[x];
        while (x % f == 0) {
            x /= f;
            e++;
        }
        factors.push_back(Factor(f, e));
    }
    return factors;
}

vector<Factor> factorizeBrute(Long x) { // O(sqrt (x))
    vector<Factor> factors = {};
    Long f = 2;
    while (f * f <= x) {
        int e = 0;
        while (x % f == 0) {
            x /= f;
            e++;
        }
        if (e > 0) {
            factors.push_back(Factor(f, e));
        }
        f++;
    }

    if (x > 1) {
        factors.push_back(Factor(x, 1));
    }
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int n;
    cin >> n;

    auto factors = factorize(n);

    bool first = true;
    for (auto factor : factors) {
        if (first) first = false;
        else cout << " * ";

        cout << factor.base << "^" << factor.exp;
    }

    cout << "\n";

    return 0;
}

#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

const int MX = 1e5;
bool isPrime[MX];
int fact[MX];

void sieve() { // O(n log log n)
    fill(isPrime, isPrime + MX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MX; i++) fact[i] = i;

    for (int i = 2; i * i < MX; i++) {
        if (isPrime[i]) {
            for (int k = i * i; k < MX; k += i) {
                isPrime[k] = false;
                fact[k] = i;
            }
        }
    }
}

Long sumDivisorsBrute(int n) { // O(n)
    Long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) sum += i;
    }
    return sum;
}

Long sumDivisorsSqrt(int n) { // O(sqrt(n))
    Long sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int d = n / i;

            // puede ser que el i == d
            sum += i;
            if (i != d) sum += d;
        }
    }
    return sum;
}

Long sumDivisorsSieve(int x) { // O(log x)
    Long sum = 1;
    while (x > 1) {
        int e = 0;
        int p = fact[x];

        Long num = 1;
        while (x % p == 0) {
            x /= p;
            e++;
            num *= p;
        }
        // num = p^e
        num = (num)*p - 1;
        Long den = p - 1;

        sum *= num / den;
    }
    return sum;
}

void solve(int n) {
    string s = to_string(n);
    int spaces = 5 - (int)s.size();
    assert(s.size() <= 5);
    for (int k = 0; k < spaces; k++) cout << " ";
    cout << s << "  ";

    Long sum = sumDivisorsSieve(n) - n;
    if (sum < n) {
        cout << "DEFICIENT\n";
    } else if (sum == n) {
        cout << "PERFECT\n";
    } else {
        cout << "ABUNDANT\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    cout << "PERFECTION OUTPUT\n";
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        solve(n);
    }
    cout << "END OF OUTPUT\n";

    return 0;
}

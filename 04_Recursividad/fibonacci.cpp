#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

// # Nodos = # Estados = O(2^n)
// Complejidad del algoritmo: # Estados * complejidad de cada estado
// Complejidad de fibonacci = O(2^n) * O(1) = O(2^n)

int f(int n) { // O(2^n)
    if (n == 0) return 0;
    if (n == 1) return 1;
    return f(n - 1) + f(n - 2);
}

int g(int n) { // O(n * 2^n)
    if (n == 0) return 0;
    if (n == 1) return 1;
    int s = 0;
    for (int k = 0; k < n; k++) {
        s += k;
    }
    return s * f(n - 1) + f(n - 2);
}

int iterativeFibo(int n) { // O(n)
    vector<int> fibo(n);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    return fibo[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << f(n) << "\n";

    return 0;
}

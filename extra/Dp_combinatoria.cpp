#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 2e5 + 2, MX2 = 1e3 + 2, MOD = 1e9 + 7, INF = 1e18;

ll valores[1002][1002];
ll combinatoria(ll valor1, ll valor2, ll mod) {
    if (valor2 == 0) {
        return 1;
    }
    if (valores[valor1][valor2] != 0) {
        return valores[valor1][valor2];
    }
    if (valor1 == valor2) {
        return valores[valor1][valor2] = 1;
    }
    if (valor2 == 1) {
        return valores[valor1][valor2] = valor1;
    }
    return valores[valor1][valor2] = ((combinatoria(valor1 - 1, valor2 - 1, mod) % mod) +
                                      (combinatoria(valor1 - 1, valor2, mod) % mod)) %
                                     mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << ((combinatoria(46, 41, MOD) % MOD) * (combinatoria(88, 14, MOD) % MOD)) % MOD
         << endl;
    cout << combinatoria(46, 41, MOD) << endl;
    cout << combinatoria(88, 14, MOD) << endl;

    return 0;
}

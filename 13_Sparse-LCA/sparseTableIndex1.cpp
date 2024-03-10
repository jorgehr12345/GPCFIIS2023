#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define POT(x) ((x) * (x))
const ll MX2 = 2e3 + 2, MX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double INF_DOUBLE = 1e18 / 1.0;
const double EPS = 1e-8;
const double PI = acos(-1.0);

const ll logarit = 32 - __builtin_clz(MX);
ll valores[MX][logarit + 1];
ll operacion(ll a, ll b) {
    return __gcd(a, b);
}
void sparseTableIndex1(vector<ll> &sparse) {
    ll n = sparse.size();
    for (ll i = 1; i <= n; i++) {
        valores[i][0] = sparse[i - 1];
    }
    for (ll i = 1; i <= logarit; i++) {
        for (ll j = 1; j <= n; j++) {
            if (j + (1 << i - 1) <= n) { // VALOR MAXIMO DE LA CANTIDAD DE ELEMENTOS
                valores[j][i] = operacion(valores[j][i - 1], valores[j + (1 << i - 1)][i - 1]);
            } else {
                valores[j][i] = valores[j][i - 1];
            }
        }
    }
}
ll query(ll l, ll r) {
    ll tamanio = r - l + 1;
    ll logarit2 = 31 - (__builtin_clz(tamanio));
    return operacion(valores[l][logarit2], valores[r - (1 << logarit2) + 1][logarit2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> vec;
    while (n--) {
        ll l;
        cin >> l;
        vec.pb(l);
    }
    sparseTableIndex1(vec);
    cout << query(2, 5) << " asdasdas " << endl;
    return 0;
}

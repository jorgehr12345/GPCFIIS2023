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
const ll MX = 1e6 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

ll n;
vector<ll> adj[MX];
ll conteo = 1;
bool val[MX];

ll padre[MX], entrada[MX], salida[MX], prof[MX];
void dfslca(ll ini, ll pap, ll profundidad) { // nodos
    entrada[ini] = conteo;
    prof[ini] = profundidad;
    conteo++;
    val[ini] = true;
    if (ini == 1) {
        padre[ini] = ini;
    } else {
        padre[ini] = pap;
    }
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (val[adj[ini][i]] == false) {
            dfslca(adj[ini][i], ini, profundidad + 1);
        }
    }

    salida[ini] = conteo;
    conteo++;
}

ll ancestro[MX][21];
void precalcular(ll nodos) { // 20*nodos
    for (ll i = 1; i <= nodos; i++) {
        ancestro[i][0] = padre[i];
    }
    for (ll p = 1; p <= 20; p++) {
        for (ll j = 1; j <= nodos; j++) {
            ancestro[j][p] = ancestro[ancestro[j][p - 1]][p - 1];
        }
    }
}

bool esAncestro(ll primer, ll segundo) { // si es ancestro el nodo "primer" del nodo "segundo"
    return entrada[primer] <= entrada[segundo] && salida[primer] >= salida[segundo];
}

ll lca(ll primer, ll segundo) {
    if (esAncestro(primer, segundo)) {
        return primer;
    }
    for (ll i = 20; i >= 0; i--) {
        if (!esAncestro(ancestro[primer][i], segundo)) {
            primer = ancestro[primer][i];
        }
    }
    return padre[primer];
}

void limpiar(ll nodos) {
    for (ll i = 1; i <= nodos; i++) {
        adj[i].clear();
        val[i] = false;
    }
    conteo = 1;
}

int main() {
    ll n, as;
    cin >> n;
    as = n - 1;
    while (as--) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfslca(1, 1, 1);
    precalcular(n);
    // cout<<lca(17,18)<<endl;
    ll m;
    cin >> m;
    while (m--) {
        ll a, b;
        cin >> a >> b;
        cout << lca(a, b) << " asdsadasd " << endl;
    }
    limpiar(n);
    return 0;
}
/*
18
1 2
1 3
2 4
2 5
3 6
3 7
4 8
5 9
6 10
6 11
7 12
7 13
10 14
10 15
12 16
13 17
13 18
*/
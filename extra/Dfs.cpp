#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
typedef long double ld;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 2e5 + 5, MX2 = 1024 * 1024 + 2, MX3 = 5e2 + 2;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

vector<ll> adj[MX];
ll hijos[MX], padres[MX], profundidad[MX];
ll entrada[MX], salida[MX];
ll cont = 1;
void dfs(ll nodoActual, ll padre, ll prof) {
    profundidad[nodoActual] = prof;
    hijos[nodoActual] = 1;
    padres[nodoActual] = padre;

    entrada[nodoActual] = cont;
    cont++;

    for (ll i = 0; i < adj[nodoActual].size(); i++) {
        if (adj[nodoActual][i] != padre) {
            dfs(adj[nodoActual][i], nodoActual, prof + 1);
            hijos[nodoActual] += hijos[adj[nodoActual][i]];
        }
    }

    salida[nodoActual] = cont;
    cont++;
}

int main() {
    inic;
    inic2;

    ll n;
    cin >> n;
    Rep1(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0, 1);
    Rep1(i, n) {
        cout << "Entrada de i: " << i << " : " << entrada[i] << endl;
        cout << "Salida de i: " << i << " : " << salida[i] << endl;
    }

    ll q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        if (entrada[a] <= entrada[b] && salida[a] >= salida[b]) {
            cout << b << " está dentro de : " << a << endl;
        }
    }

    return 0;
}
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
queue<ll> qq;
bool val[MX];
ll profundidad[MX], padre[MX];

ll cont = 1;
void bfs(ll root) {
    qq.push(root);
    profundidad[root] = 1;

    padre[root] = root;
    val[root] = true;

    while (!qq.empty()) {
        ll valorActual = qq.front();
        qq.pop();
        cont++;

        for (ll i = 0; i < adj[valorActual].size(); i++) {
            if (val[adj[valorActual][i]] == false) {
                profundidad[adj[valorActual][i]] = profundidad[valorActual] + 1;
                padre[adj[valorActual][i]] = valorActual;
                qq.push(adj[valorActual][i]);
                val[adj[valorActual][i]] = true;
            }
        }
    }
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
    bfs(1);
    Rep1(i, n) {
        cout << "La profunidad de i: " << i << " es: " << profundidad[i] << endl;
    }
    Rep1(i, n) {
        cout << "El padre i: " << i << " es: " << padre[i] << endl;
    }
    return 0;
}
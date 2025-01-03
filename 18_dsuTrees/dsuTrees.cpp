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
const ll MX = 2e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

vector<ll> adj[MX];
ll resp[MX];

ll tamanio[MX], lider[MX];
ll find_lider(ll nodo) {
    if (lider[nodo] == nodo) {
        return nodo;
    }
    lider[nodo] = find_lider(lider[nodo]);
    return lider[nodo];
}
void join(ll nodo_a, ll nodo_b) {
    nodo_a = find_lider(nodo_a);
    nodo_b = find_lider(nodo_b);
    if (nodo_a != nodo_b) {
        if (tamanio[nodo_a] > tamanio[nodo_b]) {
            tamanio[nodo_a] += tamanio[nodo_b];
            lider[nodo_b] = nodo_a;
        } else {
            tamanio[nodo_b] += tamanio[nodo_a];
            lider[nodo_a] = nodo_b;
        }
    }
}

ll rp[MX];
multiset<ll> ses[MX];
void dfs(ll ini, ll pap) {
    ll tamMay = -1, nodoMay = ini;
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (adj[ini][i] != pap) {
            dfs(adj[ini][i], ini);
            if (tamMay < tamanio[find_lider(adj[ini][i])]) {
                tamMay = tamanio[find_lider(adj[ini][i])];
                nodoMay = adj[ini][i];
            }
        }
    }
    ll lid = find_lider(nodoMay);
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (adj[ini][i] != pap && adj[ini][i] != nodoMay) {
            ll asd = find_lider(adj[ini][i]);
            join(asd, lid);
            // for (set<ll>::iterator it = ses[asd].begin(); it != ses[asd].end(); it++) {
            //     ses[lid].insert(*it);
            // }
        }
    }
    join(ini, lid);
    // ses[find_lider(ini)].insert(color[ini]);
    // resp[ini] = ses[find_lider(ini)].size();
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
    fill(tamanio, tamanio + n + 1, 1);
    iota(lider, lider + n + 1, 0);
    dfs(1, 1);
    ll q;
    cin >> q;
    while (q--) {
        ll a;
        cin >> a;
    }
    return 0;
}
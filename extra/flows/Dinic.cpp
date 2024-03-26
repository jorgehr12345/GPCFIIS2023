#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 1e4 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

struct edge {
    ll valor = 0, flujo = 0, capacidad = 0, posAncestro = 0;
    edge(ll valor, ll capacidad, ll posAncestro)
        : valor(valor), flujo(0), capacidad(capacidad), posAncestro(posAncestro) {}
};

ll nivel[MX], nextEdge[MX], padre[MX];
vector<edge> adj[MX];
vector<ll> resp[MX], resp2[MX];

struct dinic {
    ll dfs(ll ini, ll sumidero, ll flujoTotal, ll pap) {
        if (ini == sumidero) {
            return flujoTotal;
        }
        for (ll i = nextEdge[ini]; i < adj[ini].size(); i++) {
            ll disponible = adj[ini][i].capacidad - adj[ini][i].flujo;
            if (disponible == 0 || nivel[adj[ini][i].valor] != nivel[ini] + 1) {
                nextEdge[ini]++;
                continue;
            }
            ll flujoMin = dfs(adj[ini][i].valor, sumidero, min(flujoTotal, disponible), ini);
            if (flujoMin > 0) {
                adj[ini][i].flujo += flujoMin;
                adj[adj[ini][i].valor][adj[ini][i].posAncestro].flujo -= flujoMin;
                return flujoMin;
            }
            nextEdge[ini]++;
        }
        return 0;
    }

    bool bfs(ll s, ll t, ll n) {
        fill(nivel, nivel + n + 1, -1);
        queue<ll> q({s});
        nivel[s] = 0;
        while (!q.empty()) {
            ll u = q.front();
            nextEdge[u] = 0;
            q.pop();
            if (u == t) {
                return true;
            }
            for (edge e : adj[u]) {
                int v = e.valor;
                ll disponible = e.capacidad - e.flujo;
                if (nivel[v] == -1 && disponible > 0) {
                    nivel[v] = nivel[u] + 1;
                    q.push(v);
                }
            }
        }
        return false;
    }

    ll maxFlow(ll s, ll t, ll n) {
        ll ans = 0;
        while (bfs(s, t, n)) {
            while (ll inc = dfs(s, t, INF, -1)) {
                ans += inc;
            }
        }
        return ans;
    }
};

bool pp = false;
ll tot = 1;
void respuesta(ll ini, ll n) {
    resp[tot].pb(ini);
    if (ini == n) {
        pp = true;
        tot++;
        return;
    } else {
        for (ll i = 0; i < adj[ini].size(); i++) {
            if ((adj[ini][i].flujo == 1 && pp == false)) {
                adj[ini][i].flujo = 0;
                respuesta(adj[ini][i].valor, n);
            }
        }
        if (pp == false) {
            resp[tot].pop_back();
        }
    }
}

void addEdge(ll origen, ll destino, ll capacidad, bool unidireccional = false) {
    adj[origen].pb({destino, capacidad, adj[destino].size()});
    adj[destino].pb({origen, capacidad * !bool(unidireccional), adj[origen].size() - 1});
}

void clear(int n) {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
}

int main() {
    inic;
    inic2;
    ll n, m;
    cin >> n >> m;
    Rep1(i, m) {
        ll a, b, w;
        cin >> a >> b >> w;
        addEdge(a, b, w);
    }
    dinic nuevo;
    ll rp = nuevo.maxFlow(1, n, n);
    cout << rp << endl;

    return 0;
}
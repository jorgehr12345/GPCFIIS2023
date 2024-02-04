#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const ll MX = 2e5 + 2;

map<ll, ll> ma;
map<pair<ll, ll>, ll> mapa;
set<ll> se;

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
        if (tamanio[nodo_a] >= tamanio[nodo_b]) {
            tamanio[nodo_a] += tamanio[nodo_b];
            lider[nodo_b] = nodo_a;
        } else {
            tamanio[nodo_b] += tamanio[nodo_a];
            lider[nodo_a] = nodo_b;
        }
    }
}

ll color[MX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    fill(tamanio, tamanio + n + 1, 1);
    iota(lider, lider + n + 1, 0);

    return 0;
}

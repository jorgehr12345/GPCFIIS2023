#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

const int MX = 20;
const int INF = 1e9;

int w[MX];
int v[MX];
int n;

int maximumValue(int pos, int capacity) {
    /*
        Retorna el maximo valor que puedo obtener, utilizando los objetos
        del rango [pos, n - 1] (pos indexed-0), sabiendo que me queda una
        capacidad igual a `capacity`.
    */
    if (capacity < 0) return -INF;
    if (pos == n) return 0;

    // tomarlo -> v[pos] + maximumValue(pos + 1, capacity - w[pos])
    // no tomarlo -> maximumValue(pos + 1, capacity)

    return max(v[pos] + maximumValue(pos + 1, capacity - w[pos]),
               maximumValue(pos + 1, capacity));
}

int maximumValueV2(int pos, int capacity) {
    /*
        Retorna el maximo valor que puedo obtener, utilizando los objetos
        del rango [pos, n - 1] (pos indexed-0), sabiendo que me queda una
        capacidad igual a `capacity`.
    */
    if (pos == n) return 0;

    // tomarlo -> v[pos] + maximumValue(pos + 1, capacity - w[pos])
    // no tomarlo -> maximumValue(pos + 1, capacity)

    if (w[pos] > capacity) {
        return maximumValue(pos + 1, capacity);
    } else {
        return max(v[pos] + maximumValue(pos + 1, capacity - w[pos]),
                   maximumValue(pos + 1, capacity));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int W;
    cin >> n >> W;

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    cout << maximumValue(0, W) << "\n";

    return 0;
}

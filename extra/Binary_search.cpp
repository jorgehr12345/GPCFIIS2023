#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;
using Long = long long;
const Long mod = 1e9 + 7;

int arre[102];
bool f(Long pos) {
    if (arre[pos] >= 300) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arre[i];
    }
    // INICIO BINARY SEARCH
    Long ini = 1, fin = n;
    while (ini <= fin) {
        Long med = (ini + fin) / 2;
        if (f(med) == true) {
            fin = med;
        } else {
            ini = med + 1;
        }
    }
    if (f(ini) == true) {
        cout << "Posicion de 1er valor mayor o igual a 300: " << ini << endl;
    } else {
        cout << "No hay rpta" << endl;
    }
    // FIN BINARY SEARCH

    vector<Long> vec;
    set<Long> se;
    for (int i = 1; i <= n; i++) {
        Long l;
        cin >> l;
        vec.push_back(l);
        se.insert(l);
    }

    sort(vec.begin(), vec.end());
    vector<Long>::iterator it2 = lower_bound(vec.begin(), vec.end(), 30);
    set<Long>::iterator it3 = se.lower_bound(30);
    if (it3 == se.end()) {
        cout << "No existe valor mayor a 30" << endl;
    } else {
        cout << "Valor mayor o igual a 30: " << *it3 << endl;
    }

    return 0;
}
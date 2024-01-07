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

int main() {
    inic;
    inic2;
    // VECTOR
    vector<ll> vec;
    vec.push_back(20); // O(1)
    vec.push_back(30);
    vec.push_back(15);
    cout << "Segundo elemento: " << vec[1] << endl; // O(1)
    cout << "Recorro: " << endl;
    for (ll i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl; // O(1)
    }
    // SET
    set<ll> se;
    se.insert(20); // O(log(n))
    se.insert(30);
    se.insert(10);
    se.insert(15);
    se.insert(20);
    for (set<ll>::iterator it = se.begin(); it != se.end(); it++) {
        cout << *it << endl; // O(1)
    }
    set<ll>::iterator it2 = se.begin();
    cout << "Primer elemento: " << *it2 << endl;
    it2++;
    cout << "Segundo elemento: " << *it2 << endl;
    // MAP
    map<string, ll> ma;
    ma["hola"] = 20; // O(log(n))
    ma["mundo"] = 15;
    ma["a"] = 20;
    for (map<string, ll>::iterator it = ma.begin(); it != ma.end(); it++) {
        cout << it->first << " " << it->second << endl; // O(1)
    }
    cout << "Valor de mundo: " << ma["mundo"] << endl;
    // QUEUE - cola
    queue<ll> qq;
    qq.push(20); // O(1)
    qq.push(30);
    qq.push(15);
    qq.pop(); // ELIMINO EL PRIMER ELEMENTO DE LA COLA (20) O(1)
    // STACK - pila
    stack<ll> st;
    st.push(20);
    st.push(30);
    st.push(15);
    qq.pop(); // ELIMINO EL PRIMER ELEMENTO DE LA PILA (15) O(1)
    return 0;
}

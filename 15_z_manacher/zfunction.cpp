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
const ll MX = 3e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;

vector<int> zFunction(string &s) { // O(n)
    int n = s.size();
    vector<int> Z(n, 0);
    Z[0] = n;
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++) {
        // cout << "Estoy en i: " << i << endl;
        if (i <= r) {
            Z[i] = min(Z[i - l], r - i + 1);
        }
        // cout << "z[i] inicial para i: " << Z[i] << endl;
        while (i + Z[i] < n && s[i + Z[i]] == s[Z[i]]) {
            // cout << "Para i: " << i << " aumento z[i] en 1 de: " << Z[i] << endl;
            Z[i]++;
        }
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
            // cout << "Modifico l a: " << l << endl;
            // cout << "Modifico r a: " << r << endl;
        }
    }
    return Z;
}

int main() {
    inic;
    inic2;
    string s;
    cin >> s;
    vector<int> vec = zFunction(s);
    for (ll i = 0; i < vec.size(); i++) {
        cout << vec[i] << " asd " << endl;
    }

    return 0;
}

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

vector<vector<int>> manacher(string s) {
    vector<int> d1(s.size());
    for (int i = 0, l = 0, r = -1; i < s.size(); i++) {
        ll k = -1;
        if (i > r) {
            k = 1;
        } else {
            k = min(d1[l + r - i], r - i + 1);
        }
        while (0 <= i - k && i + k < s.size() && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(s.size());
    for (int i = 0, l = 0, r = -1; i < s.size(); i++) {
        ll k = -1;
        if (i > r) {
            k = 0;
        } else {
            k = min(d2[l + r - i + 1], r - i + 1);
        }
        while (0 <= i - k - 1 && i + k < s.size() && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    return {d1, d2};
}

int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> rps = manacher(s);
        ll mayor = -1, posMenor = INF;
        for (ll j = 0; j < rps[0].size(); j++) {
            ll cant = (rps[0][j] - 1);
            if (j + cant + 1 == s.size()) {
                if (posMenor > j - cant - 1) {
                    posMenor = j - cant - 1;
                }
            }
        }
        for (ll j = 0; j < rps[1].size(); j++) {
            if (rps[1][j] > 0) {
                ll cantDer = rps[1][j] - 1;
                if (j + cantDer + 1 == s.size()) {
                    if (posMenor > j - rps[1][j] - 1) {
                        posMenor = j - rps[1][j] - 1;
                    }
                }
            }
        }
        for (ll i = 0; i < s.size(); i++) {
            cout << s[i];
        }
        for (ll i = posMenor; i >= 0; i--) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}

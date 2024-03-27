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

string s, p;
ll cont = 0;
vector<ll> prefix_function(string a) { // O(n)
    ll n = a.size();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++) {
        ll j = pi[i - 1];
        while (j > 0 && a[i] != a[j]) {
            j = pi[j - 1];
        }
        if (a[i] == a[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

vector<ll> kmp() { // O(|p| + |s|)
    string w = p + '#' + s;
    vector<ll> border_func = prefix_function(w);
    vector<ll> ans;
    for (ll i = 0; i < border_func.size(); i++) {
        if (border_func[i] == p.size()) {
            ans.pb(i - 2 * p.size() + 1);
        }
    }
    return ans;
}

int main() {
    inic;
    inic2;
    cin >> p >> s; // Está p dentro de s
    s += s;
    vector<ll> vec = kmp();
    if (vec.size() > 0) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

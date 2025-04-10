#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef int ll;
typedef long double ld;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 1e5 + 5, MX2 = 3e5 + 2;
const ll MOD = 998244353;
// const ll INF = 1e18;
// const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

ll mex(vector<ll> recorrer) {
    sort(recorrer.begin(), recorrer.end());
    recorrer.erase(unique(recorrer.begin(), recorrer.end()), recorrer.end());
    for (ll i = 0; i < recorrer.size(); i++) {
        if (i != recorrer[i]) {
            return i;
        }
    }
    return recorrer.size();
}
ll dp[500];
bool usado[500];
ll g(ll num) {
    if (usado[num] == true) {
        return dp[num];
    }
    usado[num] = true;
    if (num == 1) {
        return dp[1] = 1;
    }
    vector<ll> vec;
    for (ll i = 1; i <= num; i++) {
        if (__gcd(i, num) == 1) {
            vec.pb(g(num - i));
        }
    }
    return dp[num] = mex(vec);
}

int main() {
    inic;
    inic2;
    Rep1(i, 100) {
        cout << "Para i: " << i << " : " << g(i) << endl;
    }
    return 0;
}
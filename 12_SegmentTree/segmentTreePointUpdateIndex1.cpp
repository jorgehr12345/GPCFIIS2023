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
ll operador(ll x, ll y) {
    // return max(x, y);
    return x + y;
}

struct SegmentTree {
    ll t[2 * MX];
    int n;

    void clear(int n) {
        for (int i = 1; i <= 2 * n; i++) {
            t[i] = 0;
        }
        this->n = n;
    }

    void build(vector<ll> &a, ll id, ll tl, ll tr) { // O(n)
        if (tl == tr) {
            t[id] = a[tl - 1];
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            build(a, left, tl, tm);
            build(a, right, tm + 1, tr);
            t[id] = operador(t[left], t[right]);
        }
    }

    void build(vector<ll> &a) {
        n = a.size();
        build(a, 1, 1, n);
    }

    ll query(ll l, ll r, ll id, ll tl, ll tr) { // O(logn)
        // if (tr < l || tl > r || l>R) return 0; //Dependiendo lo que te pidan
        if (l <= tl && tr <= r) return t[id];
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        if (r < tm + 1) return query(l, r, left, tl, tm);
        else if (tm < l) return query(l, r, right, tm + 1, tr);
        else return operador(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
    }

    ll query(ll l, ll r) {
        assert(n > 0);
        return query(l, r, 1, 1, n);
    }

    void update(ll pos, ll val, ll id, ll tl, ll tr) { // O(logn)
        if (tl == tr) {
            t[id] += val;
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            if (pos <= tm) update(pos, val, left, tl, tm);
            else update(pos, val, right, tm + 1, tr);
            t[id] = operador(t[left], t[right]);
        }
    }

    void update(ll pos, ll val) {
        assert(n > 0);
        update(pos, val, 1, 1, n);
    }
} st;

int main() {
    ll t, k;
    cin >> t;
    ll as = t;
    while (as--) {
        char c;
        cin >> c;
        if (c == 'C') {
            ll p;
            cin >> p;
            ll as2 = p;
            while (p--) {
                ll l;
                cin >> l;
            }
        }
    }

    return 0;
}
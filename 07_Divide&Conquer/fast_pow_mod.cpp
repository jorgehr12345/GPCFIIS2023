#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

Long fastPow(Long a, Long n, Long c) { // O(log n)
    if (n == 0) return 1;
    Long partial = fastPow(a, n / 2, c);
    Long ans = (partial * partial) % c;
    if (n % 2 == 1) ans = (ans * a) % c;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Long a, n, c;
    cin >> a >> n >> c;
    cout << fastPow(a, n, c) << "\n";

    return 0;
}

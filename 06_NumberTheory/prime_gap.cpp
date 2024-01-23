#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

bool isPrime(Long n) { // O(sqrt(n))
    if (n <= 1) return false;
    for (Long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Long l, r;
    cin >> l >> r;

    Long ans = -1;
    for (int i = l; i <= r; i++) {
        if (isPrime(i)) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}

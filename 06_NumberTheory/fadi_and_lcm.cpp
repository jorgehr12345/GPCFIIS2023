#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Long X;
    cin >> X;

    // a <= b
    Long bestA = 1;

    for (Long a = 1; a * a <= X; a++) {
        if (X % a != 0) continue;
        Long b = X / a;

        if (gcd(a, b) == 1) {
            bestA = a;
        }
    }

    Long bestB = X / bestA;

    cout << bestA << " " << bestB << "\n";

    return 0;
}

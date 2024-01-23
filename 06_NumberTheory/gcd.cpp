#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

int gcdRecursive(int a, int b) { // O(log b)
    if (b == 0) return a;
    return gcdRecursive(b, a % b);
}

int gcdIterative(int a, int b) { // O(log b)
    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int LCM(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Long a, b;
    cin >> a >> b;
    cout << gcdRecursive(a, b) << " " << gcdIterative(a, b) << "\n";

    Long g = gcd(a, b);
    Long l = lcm(a, b);

    return 0;
}

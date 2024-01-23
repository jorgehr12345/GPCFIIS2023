#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

void f(int n, int source, int target, int aux) { // O(2^n)
    /*
    Move n disks from source to target using aux as auxiliar stick
    */
    if (n == 0) {
        return;
    }

    f(n - 1, source, aux, target);
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    f(n - 1, aux, target, source);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    f(n, 1, 3, 2);

    return 0;
}

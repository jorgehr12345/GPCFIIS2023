#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

int getBit(Long mask, int i) { // O(1)
    return (mask >> i) & 1;
}

void turnOn(Long &mask, int i) { // O(1)
    mask |= (1LL << i);
}

void turnOff(Long &mask, int i) { // O(1)
    mask &= (~(1LL << i));
}

void changeBit(Long &mask, int i) { // O(1)
    mask ^= (1LL << i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {8, 10, 11};
    int n = v.size();

    // 2^n = (1 << n)
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (getBit(mask, i) == 1) {
                subset.push_back(v[i]);
            }
        }
        cout << "{";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }

    cout << "count bits on(5) = " << __builtin_popcount(5) << "\n";

    int m = 10;
    cout << popcount((unsigned int)m) << "\n";
    return 0;
}

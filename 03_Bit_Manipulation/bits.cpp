#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a = -3;
    int b = -5;
    int c = a & b;

    cout << "c (decimal) = " << c << "\n";
    cout << "a = " << bitset<32>(a) << "\n";
    cout << "b = " << bitset<32>(b) << "\n";
    cout << "c = " << bitset<32>(c) << "\n";

    int d = 5;
    // 5 * 2 ^ 3 = 40

    int e = (d << 3);
    cout << "e = " << e << "\n";

    int x = 13;
    cout << "13 >> 2 = " << (x >> 2) << "\n";

    int p = 1;
    int expo = 40;

    // p * 2^expo
    cout << (p << expo) << "\n"; // overflow

    Long expoLong = 40;
    cout << (p << expoLong) << "\n"; // overflow

    Long pLong = 1;
    cout << (pLong << expo) << "\n";     // nice
    cout << (pLong << expoLong) << "\n"; // nice
    return 0;
}

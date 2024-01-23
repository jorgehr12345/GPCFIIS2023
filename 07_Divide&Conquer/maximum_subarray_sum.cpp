#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

const int MX = 1e5;
Long A[MX];

Long maxCrossingSubarraySum(int l, int mid, int r) { // O(n)
    // Two arrays A[l...mid] and A[mid + 1...r]
    Long maxSuffix = A[mid];
    Long acum = 0;
    for (int i = mid; i >= l; i--) {
        acum += A[i];
        maxSuffix = max(maxSuffix, acum);
    }
    Long maxPrefix = A[mid + 1];
    acum = 0;
    for (int i = mid + 1; i <= r; i++) {
        acum += A[i];
        maxPrefix = max(maxPrefix, acum);
    }
    return maxPrefix + maxSuffix;
}

Long maxSubarraySum(int l, int r) { // O(n log n)
    if (l == r) return A[l];
    int mid = (l + r) / 2;
    Long leftSum = maxSubarraySum(l, mid);
    Long rightSum = maxSubarraySum(mid + 1, r);
    Long cross = maxCrossingSubarraySum(l, mid, r);
    return max({leftSum, rightSum, cross});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}

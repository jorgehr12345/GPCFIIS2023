#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

const int MX = 1e5;
Long A[MX];

struct SubArraySums {
    Long maxSubarraySum;
    Long maxPrefixSum;
    Long maxSuffixSum;
    Long sum;

    SubArraySums() {}

    SubArraySums(Long x) {
        maxSubarraySum = maxPrefixSum = maxSuffixSum = sum = x;
    }
};

SubArraySums combine(SubArraySums left, SubArraySums right) { // O(1)
    SubArraySums ans;
    ans.sum = left.sum + right.sum;
    ans.maxPrefixSum = max(left.maxPrefixSum, left.sum + right.maxPrefixSum);
    ans.maxSuffixSum = max(right.maxSuffixSum, right.sum + left.maxSuffixSum);
    ans.maxSubarraySum = max(
        {left.maxSubarraySum, right.maxSubarraySum, left.maxSuffixSum + right.maxPrefixSum});
    return ans;
}

SubArraySums maxSubarraySum(int l, int r) { // O(n)
    if (l == r) return SubArraySums(A[l]);
    int mid = (l + r) / 2;
    SubArraySums leftData = maxSubarraySum(l, mid);
    SubArraySums rightData = maxSubarraySum(mid + 1, r);
    return combine(leftData, rightData);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}

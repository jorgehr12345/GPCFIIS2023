#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

vector<vector<int>> allPermutations;

bool isPermutation(vector<int> &permutation, int n) { // O(n)
    vector<bool> isPresent(n + 1, false);
    for (int x : permutation) {
        if (x > n && x < 1) return false;
        if (isPresent[x]) return false;
        isPresent[x] = true;
    }
    return true;
}

void generateAllPermutations(vector<int> &permutation, int n) { // O(n^(n + 1))
    if (permutation.size() == n) {
        if (isPermutation(permutation, n)) allPermutations.push_back(permutation);
        return;
    }
    for (int x = 1; x <= n; x++) {
        permutation.push_back(x); // make
        generateAllPermutations(permutation, n);
        permutation.pop_back(); // undo
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v = {};
    generateAllPermutations(v, n);

    for (auto permutation : allPermutations) {
        for (int x : permutation) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

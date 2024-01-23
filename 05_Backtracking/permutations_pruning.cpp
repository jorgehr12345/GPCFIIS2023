#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

vector<vector<int>> allPermutations;

const int MX = 20;
bool used[MX];

void make(vector<int> &permutation, int x) {
    permutation.push_back(x);
    used[x] = true;
}

void undo(vector<int> &permutation, int x) {
    permutation.pop_back();
    used[x] = false;
}

void generateAllPermutations(vector<int> &permutation, int n) { // O(n^2 * n!)
    if (permutation.size() == n) {
        allPermutations.push_back(permutation);
        return;
    }
    for (int x = 1; x <= n; x++) {
        if (used[x]) continue; // pruning
        make(permutation, x);
        generateAllPermutations(permutation, n);
        undo(permutation, x);
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

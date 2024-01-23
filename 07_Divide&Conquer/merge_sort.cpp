#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

vector<int> merge(vector<int> &L, vector<int> &R) { // O(L + R)
    vector<int> ans;
    int indL = 0;
    int indR = 0;
    int n = L.size() + R.size();
    for (int i = 0; i < n; i++) {
        if (indL == L.size()) {
            // we already finished with L
            ans.push_back(R[indR]);
            indR++;
        } else if (indR == R.size()) {
            // we already finished with R
            ans.push_back(L[indL]);
            indL++;
        } else {
            if (L[indL] <= R[indR]) {
                ans.push_back(L[indL]);
                indL++;
            } else {
                ans.push_back(R[indR]);
                indR++;
            }
        }
    }
    return ans;
}

void sort(vector<int> &v) {
    int n = v.size();
    if (n <= 1) return; // base case, already sorted

    // Divide
    vector<int> L, R;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) L.push_back(v[i]);
        else R.push_back(v[i]);
    }

    // Conquer
    sort(L);
    sort(R);

    // Combine
    v = merge(L, R); // O(n)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}

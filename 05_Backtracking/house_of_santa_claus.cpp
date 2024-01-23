#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

vector<vector<int>> solutions;
const int MX = 6;

vector<int> neighbours[MX];

bool used[MX][MX];

void generateSolutions(vector<int> &house) { // O(n^m)
    if (house.size() == 9) {
        solutions.push_back(house);
        return;
    }

    int node = house.back();

    for (int neighbour : neighbours[node]) {
        if (used[node][neighbour]) continue;

        // make
        house.push_back(neighbour);
        used[node][neighbour] = true;
        used[neighbour][node] = true;

        // recursion
        generateSolutions(house);

        // undo
        house.pop_back();
        used[node][neighbour] = false;
        used[neighbour][node] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    neighbours[1] = {2, 3, 5};
    neighbours[2] = {1, 3, 5};
    neighbours[3] = {1, 2, 4, 5};
    neighbours[4] = {3, 5};
    neighbours[5] = {1, 2, 3, 4};

    vector<int> house = {1};
    generateSolutions(house);

    // We can ignore the sort if the bactracking
    // produces the output already sorted
    // sort(solutions.begin(), solutions.end());

    for (auto solution : solutions) {
        for (int node : solution) {
            cout << node;
        }
        cout << "\n";
    }

    return 0;
}

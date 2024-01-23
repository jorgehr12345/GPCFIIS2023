#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

int n;

const int MX = 15;

int cnt;
bool usedColumn[MX];
bool usedMainDiagonal[2 * MX];
bool usedSecondaryDiagonal[2 * MX];
string board[MX];

int getMainDiagonal(int row, int col) {
    return row + col;
}

int getSecondaryDiagonal(int row, int col) {
    return row - col + n - 1;
}

void make(int row, int col, bool doSet) {
    int d1 = getMainDiagonal(row, col);
    int d2 = getSecondaryDiagonal(row, col);

    usedColumn[col] = doSet;
    usedMainDiagonal[d1] = doSet;
    usedSecondaryDiagonal[d2] = doSet;
}

void setQueens(int row) { // O(n^2 * n!)
    if (row == n) {
        cnt++;
        return;
    }
    for (int col = 0; col < n; col++) {
        int d1 = getMainDiagonal(row, col);
        int d2 = getSecondaryDiagonal(row, col);

        // pruning
        if (board[row][col] == '*' || usedColumn[col] || usedMainDiagonal[d1] ||
            usedSecondaryDiagonal[d2]) {
            continue;
        }

        make(row, col, true);
        setQueens(row + 1);
        make(row, col, false);
    }
}

void solve(int n) {
    cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    setQueens(0);

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;

        cout << "Case " << t << ": ";
        solve(n);
        t++;
    }

    return 0;
}

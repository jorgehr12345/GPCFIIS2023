#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;
using Board = vector<vector<bool>>;

int n;

const int MX = 10;
Board board;

vector<Board> boards;

bool usedColumn[MX];
bool usedMainDiagonal[2 * MX];
bool usedSecondaryDiagonal[2 * MX];

int getMainDiagonal(int row, int col) {
    return row + col;
}

int getSecondaryDiagonal(int row, int col) {
    return row - col + n - 1;
}

void make(int row, int col, bool doSet) {
    int d1 = getMainDiagonal(row, col);
    int d2 = getSecondaryDiagonal(row, col);
    board[row][col] = doSet;

    usedColumn[col] = doSet;
    usedMainDiagonal[d1] = doSet;
    usedSecondaryDiagonal[d2] = doSet;
}

void setQueens(int row) { // O(n^2 * n!)
    if (row == n) {
        boards.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        int d1 = getMainDiagonal(row, col);
        int d2 = getSecondaryDiagonal(row, col);

        // pruning
        if (usedColumn[col] || usedMainDiagonal[d1] || usedSecondaryDiagonal[d2]) continue;

        make(row, col, true);
        setQueens(row + 1);
        make(row, col, false);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    board = vector<vector<bool>>(n, vector<bool>(n, false));

    setQueens(0);

    for (Board board : boards) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col]) cout << "*";
                else cout << ".";
                cout << " ";
            }
            cout << "\n";
        }
        cout << "=========================================\n";
    }

    return 0;
}

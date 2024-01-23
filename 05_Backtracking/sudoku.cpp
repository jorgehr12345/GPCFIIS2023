#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

const int MX = 4;
int A[MX][MX];

bool inRow[MX][MX + 1];   // inRow[row][num] is true iff num is present in row
bool inCol[MX][MX + 1];   // inCol[col][num] is true iff num is present in col
bool inBlock[MX][MX + 1]; // inBlock[block][num] is true iff num is present in block

int getBlock(int row, int col) {
    return (row / 2) * 2 + (col / 2);
}

void assertData(int row, int col, int num, int block) {
    assert(row >= 0 && row < MX);
    assert(col >= 0 && col < MX);
    assert(num >= 1 && num <= MX);
    assert(block >= 0 && block < MX);
}

bool canPutNumber(int row, int col, int num) {
    int block = getBlock(row, col);
    assertData(row, col, num, block);

    if (inRow[row][num]) return false;
    if (inCol[col][num]) return false;
    if (inBlock[block][num]) return false;

    return true;
}

void putNumber(int row, int col, int num) {
    int block = getBlock(row, col);
    assertData(row, col, num, block);

    A[row][col] = num;
    inRow[row][num] = true;
    inCol[col][num] = true;
    inBlock[block][num] = true;
}

void removeNumber(int row, int col, int num) {
    int block = getBlock(row, col);
    assertData(row, col, num, block);

    A[row][col] = 0;
    inRow[row][num] = false;
    inCol[col][num] = false;
    inBlock[block][num] = false;
}

void printBoard() {
    for (int i = 0; i < MX; i++) {
        for (int j = 0; j < MX; j++) {
            cout << A[i][j];
            assert(A[i][j] != 0);
        }
        cout << "\n";
    }
}

void generate(int row, int col) { // O((n!)^n)
    if (row == MX) {
        // found a solution
        printBoard();
        return;
    }

    if (A[row][col] > 0) {
        // We already set the number in the input
        if (col + 1 < MX) generate(row, col + 1);
        else generate(row + 1, 0);
        return;
    }
    // Iterate through options
    for (int val = 1; val <= 4; val++) {
        if (!canPutNumber(row, col, val)) continue; // pruning

        putNumber(row, col, val);

        if (col + 1 < MX) generate(row, col + 1);
        else generate(row + 1, 0);

        removeNumber(row, col, val);
    }
}

void solve() {
    for (int i = 0; i < MX; i++) {
        string s;
        cin >> s;

        for (int k = 0; k < MX; k++) {
            if (s[k] == '*') {
                A[i][k] = 0;
            } else {
                A[i][k] = s[k] - '0';
                putNumber(i, k, A[i][k]);
            }
        }
    }
    generate(0, 0);
    for (int i = 0; i < MX; i++) {
        for (int k = 0; k < MX; k++) {
            if (A[i][k] != 0) {
                removeNumber(i, k, A[i][k]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":\n";
        solve();
    }

    return 0;
}

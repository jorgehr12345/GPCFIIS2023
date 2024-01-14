#include <bits/stdc++.h>
using namespace std;

int memo[100000];
int fibonacci(int n) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (memo[n] != 0) {
        return memo[n];
    }
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int memo2[1002][1002];
int combinatoria(int n, int k2) {
    if (n == k2) {
        return 1;
    }
    if (k2 == 1) {
        return n;
    }
    if (memo2[n][k2] != 0) {
        return memo2[n][k2];
    }
    memo2[n][k2] = combinatoria(n - 1, k2 - 1) + combinatoria(n - 1, k2);
    return memo2[n][k2];
}

int arreglo[1002];
bool memo3[1002][1002];
bool uso[1002][1002];
bool cumple(int suma, int pos) {
    if (suma == 0) {
        return true;
    }
    if (uso[suma][pos] == true) {
        return memo3[suma][pos];
    }
    uso[suma][pos] = true;
    memo3[suma][pos] = cumple(suma - arreglo[pos], pos - 1);
    memo3[suma][pos] = memo3[suma][pos] | cumple(suma, pos - 1);
    return memo3[suma][pos];
}

int main() {
    cout << fibonacci(5) << endl;
    cout << combinatoria(10, 2) << endl;
    int fib[100001];
    for (int i = 1; i <= 100000; i++) {
        if (i == 1) {
            fib[i] = 1;
        } else {
            if (i == 2) {
                fib[i] = 1;
            } else {
                fib[i] = fib[i - 1] + fib[i - 2];
            }
        }
    }
}
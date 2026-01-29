#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    bool negative = false;
    long long N = n;   

    if (N < 0) {
        negative = true;
        N = -N;
    }

    double res = 1.0;

    while (N > 0) {
        if (N % 2 == 0) {
            x = x * x;
            N = N / 2;
        } else {
            res = res * x;
            N = N - 1;
        }
    }

    if (negative)
        return 1.0 / res;

    return res;
}

int main() {
    double x;
    int n;

    cin >> x >> n;

    cout << myPow(x, n);

    return 0;
}

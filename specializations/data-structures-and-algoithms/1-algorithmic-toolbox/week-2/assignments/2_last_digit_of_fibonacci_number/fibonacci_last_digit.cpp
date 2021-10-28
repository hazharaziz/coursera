using namespace std;
#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    int fibArr[n + 1];
    fibArr[0] = 0;
    if (n != 0) {
        fibArr[1] = 1;
    }
    if (n <= 1) {
        return fibArr[n] % 10;
    }
    else
    {
        for (int i = 2; i <= n; i++) {
            fibArr[i] = (fibArr[i - 1] + fibArr[i - 2]) % 10;
        }
        return fibArr[n];
    }
}


int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    cout << c << endl;
    return 0;
}

using namespace std;
#include <iostream>

long long pisanoPeriodLength(long long n, long long mod) {
    long long pre = 0;
    long long current = 1;
    long long periodLength = 0;
    long long temp;
    for (long long i = 0; i < mod * mod; i++) {
        temp = pre;
        pre = current;
        current = (temp + current) % mod;
        if ((pre == 0) && (current == 1)) {
            return i + 1;
        }
    }

    return periodLength;
}


long long get_fibonacci_huge_naive(long long n, long long m, long long periodLength) {
    
    long long fibModArr[periodLength];
    fibModArr[0] = 0;
    if (n != 0) {
        fibModArr[1] = 1;
    }
    for (int i = 2; i < periodLength; i++) {
        fibModArr[i] = (fibModArr[i - 1] + fibModArr[i - 2]) % m; 
    }

    return fibModArr[n % periodLength];
}

long long fibonacci_sum_squares_naive(long long n) {
    long long pisano1 = pisanoPeriodLength(n, 10);
    long long pisano2 = pisanoPeriodLength(n - 1, 10);
    long long lastFib = get_fibonacci_huge_naive(n, 10, pisano1);
    long long preLastFib = get_fibonacci_huge_naive(n - 1, 10, pisano2);
    return (lastFib * (preLastFib + lastFib)) % 10;
}



int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_squares_naive(n);
    return 0;
}

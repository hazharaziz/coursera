using namespace std;
#include <iostream>

long long sum(long long arr[], long long size) {
    long long sum = 0;
    for (long long i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

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


int fibonacci_sum_naive(long long n, long long m) {   
    long long fibModArr[n + 1];
    fibModArr[0] = 0;
    fibModArr[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibModArr[i] = (fibModArr[i - 1] + fibModArr[i - 2]) % m; 
    }

    return (sum(fibModArr, n + 1) % m);
}

int main() {
    long long n;
    cin >> n;
    long long periodLength = pisanoPeriodLength(n, 10);
    n = n % periodLength;
    cout << fibonacci_sum_naive(n, 10) << endl;
    return 0;
}

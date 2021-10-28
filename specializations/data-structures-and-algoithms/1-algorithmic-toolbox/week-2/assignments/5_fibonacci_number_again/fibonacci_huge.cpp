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

int main() {
    long long n, m;
    cin >> n >> m;
    long long periodLength = pisanoPeriodLength(n, m);
    n = n % periodLength;
    cout << get_fibonacci_huge_naive(n, m, periodLength) << endl;    

    return 0;
}

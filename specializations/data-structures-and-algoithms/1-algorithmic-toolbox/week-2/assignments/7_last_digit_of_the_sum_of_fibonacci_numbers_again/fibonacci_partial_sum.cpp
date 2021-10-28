using namespace std;
#include <iostream>
#include <vector>

long long sum(long long arr[], long long size) {
    long long sum = 0;
    for (long long i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

long long pisanoPeriodLength(long long mod) {
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

    return sum(fibModArr, n + 1) % m;
}

void swap(long long* a, long long* b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

long long solve(long long n) {
    long long pisanoPeriod = pisanoPeriodLength(10);
    n = n % pisanoPeriod;
    return fibonacci_sum_naive(n, 10);
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (from <= to) {
        swap(&from, &to);
    }

    long long greaterLastDigit = solve(from);
    long long smallerLastDigit = solve(to - 1);

    if (greaterLastDigit < smallerLastDigit) {
        return ((greaterLastDigit + 10) - smallerLastDigit) % 10;
    }
    return greaterLastDigit - smallerLastDigit;
}

int main() {
    long long from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum_naive(from, to) << endl;
    return 0;
}

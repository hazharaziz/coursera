using namespace std;
#include <iostream>

void swap(long long* a, long long* b) {
  long long temp = *a;
  *a = *b;
  *b = temp;
}

long gcd_naive(long long a, long long b) {
  if (a < b)
    swap(&a, &b);
  if (b == 0) 
    return a;
  else
    return gcd_naive(b, a % b);
}

long long int lcm_naive(long long a, long long b) {
  return (a * b) / gcd_naive(a, b);
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout << lcm_naive(a, b) << endl;
  return 0;
}

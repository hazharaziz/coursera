using namespace std;
#include <iostream>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int gcd_naive(int a, int b) {
  int gcd;

  if (a < b)
    swap(&a, &b);
  if (b == 0) 
    return a;
  else
    return gcd_naive(b, a % b);
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << gcd_naive(a, b) << endl;
  
  return 0;
}

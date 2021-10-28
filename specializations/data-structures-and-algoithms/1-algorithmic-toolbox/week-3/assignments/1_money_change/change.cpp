using namespace std;
#include <iostream>

int get_change(int m) {
  int n = 0;

  while (m > 0) {
    if (m >= 10) {
      m -= 10;
    }
    else if (m >= 5 && m < 10) {
      m -= 5;
    }
    else
    {
      m -= 1;
    }
    n++;
  }  

  return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << endl;
  return 0;
}

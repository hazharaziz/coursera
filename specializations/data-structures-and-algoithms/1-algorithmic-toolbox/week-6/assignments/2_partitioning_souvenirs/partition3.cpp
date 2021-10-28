using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

long long Sum(vector<long long> list) {
  long long sum = 0;
  for (long long i = 0; i < list.size(); i++) {
    sum += list[i];
  }
  return sum;
}

long long partition3(vector<long long> souvenirs)
{
  bool result = false;
  long long count = souvenirs.size();
  long long sum = Sum(souvenirs);
  if ((sum % 3 != 0) || (sum == 0) || count < 3) {
    result = false;
  }
  else
  {
    bool matrix[count + 1][sum / 3 + 1][sum / 3 + 1];
    for (long long i = 0; i <= count; i++)
      matrix[i][0][0] = true;
    for (long long i = 1; i <= sum / 3; i++)
      matrix[0][i][0] = true;
    for (long long i = 1; i <= sum / 3; i++)
      matrix[0][0][i] = true;

    for (long long i = 1; i <= count; i++) {
      for (long long j = 0; j <= sum / 3; j++) {
        for (long long k = 0; k <= sum / 3; k++) {
          bool booleans[4];
          if (souvenirs[i - 1] <= j && souvenirs[i - 1] <= k) {
            booleans[0] = matrix[i - 1][j - souvenirs[i - 1]][k] ||
              matrix[i - 1][j][k - souvenirs[i - 1]];
          }
          if (souvenirs[i - 1] <= j && souvenirs[i - 1] > k) {
            booleans[1] = matrix[i - 1][j - souvenirs[i - 1]][k];
          }
          if (souvenirs[i - 1] > j && souvenirs[i - 1] <= k) {
            booleans[2] = matrix[i - 1][j][k - souvenirs[i - 1]];
          }
          if (souvenirs[i - 1] > j && souvenirs[i - 1] > k) {
            booleans[3] = matrix[i - 1][j][k];
          }
          bool tempResult = false;
          for (bool x : booleans) {
            if (x == true) {
              tempResult = true;
            }
          }
          matrix[i][j][k] = tempResult ? true : false;
        }
      }
    }
    result = matrix[count][sum / 3][sum / 3];
  }
  
  return (result) ? 1 : 0;
}

int main()
{
  long long n;
  cin >> n;
  vector<long long> A(n);
  for (long long i = 0; i < A.size(); ++i)
  {
    cin >> A[i];
  }
  cout << partition3(A) << endl;
}
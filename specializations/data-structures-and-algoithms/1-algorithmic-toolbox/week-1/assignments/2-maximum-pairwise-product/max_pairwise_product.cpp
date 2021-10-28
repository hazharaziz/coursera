using namespace std;


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

long MaxPairwiseProduct(vector<long>& numbers) {
    int length = numbers.size();
    long index = 0;
    long maxProduct = LONG_MIN;

    for (int i = 1; i < length; i++) {
        if (numbers[i] > numbers[index]) {
            index = i;
        }
    }

    swap(numbers[index], numbers[length - 1]);

    index = 0;

    for (int i = 1; i < length - 1; i++) {
        if (numbers[i] > numbers[index]) {
            index = i;
        }
    }

    if (length >= 2) {
        swap(numbers[index], numbers[length - 2]);
    }

    maxProduct = (length >= 2) ? numbers[length - 1] * numbers[length - 2]
                               : numbers[0];
    return maxProduct;
}

int main() {
    long n;
    cin >> n;
    vector<long> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers);

    return 0;
}



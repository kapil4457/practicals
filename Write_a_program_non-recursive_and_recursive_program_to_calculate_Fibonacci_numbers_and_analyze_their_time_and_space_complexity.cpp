#include <iostream>

using namespace std;

int recursive_fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
    }
}

void non_recursive_fibonacci(int n) {
    int first = 0;
    int second = 1;
    cout << first << endl;
    cout << second << endl;
    while (n - 2 > 0) {
        int third = first + second;
        first = second;
        second = third;
        cout << third << endl;
        n--;
    }
}

int main() {
    int n = 10;
    for (int i = 0; i < n; i++) {
        cout << recursive_fibonacci(i) << endl;
    }

    non_recursive_fibonacci(n);

    return 0;
}
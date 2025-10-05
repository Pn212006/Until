#include <iostream>
#include <functional>
#include <cassert>
using namespace std;

int until(int x, function<int(int)> f, function<bool(int)> g) {
    while (!g(x)) {
        x = f(x);
    }
    return x;
}

int double_number(int n) { return n * 2; }
int add_five(int n) { return n + 5; }
int subtract_three(int n) { return n - 3; }

bool greater_than_100(int n) { return n > 100; }
bool less_than_zero(int n) { return n < 0; }

int main() {
    assert(until(1, double_number, greater_than_100) == 128);
    assert(until(3, add_five, [](int n){ return n % 10 == 8; }) == 8);
    assert(until(10, subtract_three, less_than_zero) == -2);
    assert(until(5, double_number, [](int n){ return n % 2 == 0; }) == 10);
    assert(until(1, add_five, [](int n){ return n > 20; }) == 21);

    cout << "All tests passed!" << endl;
    return 0;
}


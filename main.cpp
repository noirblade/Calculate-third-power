#include <iostream>
#include <cmath>
using namespace std;

const int n = 33;

int calcPower(int n, int max) {
    if (n <= 0) {
        return 0;
    }
    int min = calcPower(n - 1, max);

    for (int i = 2; i <= max; i++) {
        int y = i*i*i;
        if (n >= y) {
            int result = calcPower(n - y, max);
            if (min > result){
                min = result;
            }
        }
    }
    return min + 1;
}

int calcPowerNumbers(int n){

    int steps = 0;
    while (n > 0){
        int root = (int)cbrt(n);
        int third = root * root * root;
        cout << "Third " << third << endl;
        steps++;
        n = n - third;
    }
    return steps;
}

int calcPowerNumbersRecursive(int n, int steps){

    if (n <= 0){
        return steps;
    }

    int root = (int)cbrt(n);
    int third = root * root * root;
    steps += calcPowerNumbersRecursive(n-third, steps)+1;

    return steps;
}

int main() {
    // Cube root of n is maximum third power that we can reach.
    // Saw this on internet but it doesn't work. Maybe my mistake somewhere
    //cout << "Steps " << calcPower(n, (int)cbrt(n)) << endl;

    cout << "Steps " << calcPowerNumbers(n) << endl;
    cout << "Steps " << calcPowerNumbersRecursive(n, 0) << endl;

    return 0;
}
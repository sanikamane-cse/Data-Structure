#include <iostream>
using namespace std;

int main() {
    int a[5];      

    int i, sum = 0, mul = 1, max, min;

    
    cout << "Enter 5 elements:\n";
    for (i = 0; i < 5; i++) {
        cin >> a[i];
    }

    
    cout << "Array elements: ";
    for (i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }

    
    for (i = 0; i < 5; i++) {
        sum += a[i];
        mul *= a[i];
    }

    
    max = min = a[0];
    for (i = 1; i < 5; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    cout << "\nSum = " << sum;
    cout << "\nMultiplication = " << mul;
    cout << "\nMaximum = " << max;
    cout << "\nMinimum = " << min;

    return 0;
}

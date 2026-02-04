#include <iostream>
using namespace std;

// ✅ Linear Search Function
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// ✅ Binary Search Function (Array must be sorted)
int binarySearch(int arr[], int n, key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int arr[100], n, key, choice;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nEnter element to search: ";
    cin >> key;

    cout << "\n--- Searching Menu ---\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "Enter choice: ";
    cin >> choice;

    int result;

    switch (choice) {

    case 1:
        result = linearSearch(arr, n, key);
        if (result != -1)
            cout << "Element found at index " << result << " using Linear Search.\n";
        else
            cout << "Element not found.\n";
        break;

    case 2:
        cout << "\nNote: Array must be sorted for Binary Search!\n";
        result = binarySearch(arr, n, key);
        if (result != -1)
            cout << "Element found at index " << result << " using Binary Search.\n";
        else
            cout << "Element not found.\n";
        break;

    default:
        cout << "Invalid choice!";
    }

    return 0;
}

//Operations on data structure using array.

#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 5;   // initially 5 elements
    int choice, pos, val, key;
    int arr2[100], n2;

    // ✅ CREATE ARRAY
    cout << "Enter 5 elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (true) {
        cout << "\n\n------ MENU ------\n";
        cout << "1. Traverse Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Search Element\n";
        cout << "5. Update Element\n";
        cout << "6. Sort Array\n";
        cout << "7. Find Sum, Multiplication, Max, Min\n";
        cout << "8. Merge Another Array\n";
        cout << "9. Split Array\n";
        cout << "10. Destroy Array\n";
        cout << "11. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        // ✅ TRAVERSING
        case 1:
            cout << "Array Elements: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            break;

        // ✅ INSERTION
        case 2:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;

            for (int i = n; i > pos; i--)
                arr[i] = arr[i - 1];

            arr[pos] = val;
            n++;

            cout << "Element Inserted!";
            break;

        // ✅ DELETION
        case 3:
            cout << "Enter position to delete: ";
            cin >> pos;

            for (int i = pos; i < n - 1; i++)
                arr[i] = arr[i + 1];

            n--;

            cout << "Element Deleted!";
            break;

        // ✅ SEARCHING
        case 4:
            cout << "Enter element to search: ";
            cin >> key;

            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Element found at index " << i;
                    break;
                }
            }
            break;

        // ✅ UPDATION
        case 5:
            cout << "Enter position to update: ";
            cin >> pos;
            cout << "Enter new value: ";
            cin >> val;

            arr[pos] = val;
            cout << "Element Updated!";
            break;

        // ✅ SORTING (Selection Sort)
        case 6:
            for (int i = 0; i < n - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < n; j++) {
                    if (arr[j] < arr[minIndex])
                        minIndex = j;
                }
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }

            cout << "Array Sorted!";
            break;

        // ✅ SUM, MULTIPLICATION, MAX, MIN
        case 7: {
            int sum = 0, mul = 1;
            int max = arr[0], min = arr[0];

            for (int i = 0; i < n; i++) {
                sum += arr[i];
                mul *= arr[i];

                if (arr[i] > max) max = arr[i];
                if (arr[i] < min) min = arr[i];
            }

            cout << "Sum = " << sum << endl;
            cout << "Multiplication = " << mul << endl;
            cout << "Maximum = " << max << endl;
            cout << "Minimum = " << min << endl;
            break;
        }

        // ✅ MERGING
        case 8:
            cout << "Enter size of second array: ";
            cin >> n2;

            cout << "Enter elements:\n";
            for (int i = 0; i < n2; i++)
                cin >> arr2[i];

            for (int i = 0; i < n2; i++)
                arr[n + i] = arr2[i];

            n = n + n2;

            cout << "Arrays Merged Successfully!";
            break;

        // ✅ SPLITTING
        case 9: {
            int mid = n / 2;

            cout << "First Part: ";
            for (int i = 0; i < mid; i++)
                cout << arr[i] << " ";

            cout << "\nSecond Part: ";
            for (int i = mid; i < n; i++)
                cout << arr[i] << " ";
            break;
        }

        // ✅ DESTROY
        case 10:
            n = 0;
            cout << "Array Destroyed!";
            break;

        // ✅ EXIT
        case 11:
            cout << "Exiting Program...";
            return 0;

        default:
            cout << "Invalid Choice!";
        }
    }

    return 0;
}

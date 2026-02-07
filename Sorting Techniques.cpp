#include <iostream>
using namespace std;

int n;

// ---------- Bubble Sort ----------
void bubbleSort(int arr[]) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

// ---------- Selection Sort ----------
void selectionSort(int arr[]) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// ---------- Insertion Sort ----------
void insertionSort(int arr[]) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// ---------- Merge Sort ----------
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i=0; i<n1; i++)
        L[i] = arr[l+i];
    for(int j=0; j<n2; j++)
        R[j] = arr[m+1+j];

    int i=0, j=0, k=l;

    while(i<n1 && j<n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i<n1)
        arr[k++] = L[i++];

    while(j<n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// ---------- Quick Sort ----------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// ---------- Radix Sort ----------
int getMax(int arr[]) {
    int mx = arr[0];
    for(int i=1; i<n; i++)
        if(arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingSort(int arr[], int exp) {
    int output[n];
    int count[10] = {0};

    for(int i=0; i<n; i++)
        count[(arr[i]/exp)%10]++;

    for(int i=1; i<10; i++)
        count[i] += count[i-1];

    for(int i=n-1; i>=0; i--) {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0; i<n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[]) {
    int mx = getMax(arr);

    for(int exp=1; mx/exp>0; exp*=10)
        countingSort(arr, exp);
}

// ---------- Display ----------
void display(int arr[]) {
    cout << "\nSorted Array: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ---------- Main Program ----------
int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int choice;

    while(true) {

        cout << "\n========== SORTING MENU ==========\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Radix Sort\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int temp[n];
        for(int i=0; i<n; i++)
            temp[i] = arr[i];

        // ✅ Switch Case Menu
        switch(choice) {

            case 1:
                bubbleSort(temp);
                display(temp);
                break;

            case 2:
                selectionSort(temp);
                display(temp);
                break;

            case 3:
                insertionSort(temp);
                display(temp);
                break;

            case 4:
                mergeSort(temp, 0, n-1);
                display(temp);
                break;

            case 5:
                quickSort(temp, 0, n-1);
                display(temp);
                break;

            case 6:
                radixSort(temp);
                display(temp);
                break;

            case 7:
                cout << "Program Exit Successfully ✅\n";
                return 0;

            default:
                cout << "Invalid Choice ❌ Try Again!\n";
        }
    }
}

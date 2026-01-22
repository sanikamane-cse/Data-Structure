#include <iostream>
using namespace std;

int main() {
    int a[3][3], b[3][3];               
    int sum[3][3], sub[3][3], mult[3][3]; 
    int transA[3][3], transB[3][3];     
    int i, j, k, choice;

    
    cout << "Enter elements of Matrix A (3x3):\n";
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cin >> a[i][j];

    
    cout << "Enter elements of Matrix B (3x3):\n";
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cin >> b[i][j];

    
    cout << "\nMenu:\n";
    cout << "1. Display Matrices\n";
    cout << "2. Addition of Matrices\n";
    cout << "3. Subtraction of Matrices\n";
    cout << "4. Transpose of Matrices\n";
    cout << "5. Multiplication of Matrices\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            
            cout << "\nMatrix A:\n";
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++)
                    cout << a[i][j] << " ";
                cout << endl;
            }
            
            cout << "\nMatrix B:\n";
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++)
                    cout << b[i][j] << " ";
                cout << endl;
            }
            break;

        case 2:
           
            cout << "\nAddition of A + B:\n";
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    sum[i][j] = a[i][j] + b[i][j];
                    cout << sum[i][j] << " ";
                }
                cout << endl;
            }
            break;

        case 3:
            
            cout << "\nSubtraction of A - B:\n";
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    sub[i][j] = a[i][j] - b[i][j];
                    cout << sub[i][j] << " ";
                }
                cout << endl;
            }
            break;

        case 4:
           
            cout << "\nTranspose of Matrix A:\n";
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    transA[i][j] = a[j][i];
                    cout << transA[i][j] << " ";
                }
                cout << endl;
            }
            
            cout << "\nTranspose of Matrix B:\n";
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    transB[i][j] = b[j][i];
                    cout << transB[i][j] << " ";
                }
                cout << endl;
            }
            break;

        case 5:
           
            cout << "\nMultiplication of A * B:\n";
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    mult[i][j] = 0;
                    for (k = 0; k < 3; k++)
                        mult[i][j] += a[i][k] * b[k][j];
                    cout << mult[i][j] << " ";
                }
                cout << endl;
            }
            break;

        default:
            cout << "Invalid choice!";
    }

    return 0;
}

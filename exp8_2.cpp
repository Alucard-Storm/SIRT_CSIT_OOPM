// Write a program using dynamic memory allocation to perform 2x2 matrix addition and subtraction
#include<iostream>

using namespace std;

class Matrix {
    public:
    void insertMatrix(int** arr) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cin>>arr[i][j];
            }
        }
    }
    void printMatrix(int** arr) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout<<arr[i][j]<<"  ";
            }
            cout<<endl;
        }
    }

    void addMatrix(int** arr1, int** arr2) {
        int arr[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                arr[i][j] = arr1[i][j] + arr2[i][j];
                cout<<arr[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int rows = 2, cols = 2;

    // Dynamically allocating memory for 1st Matrix
    int **arr1;
    arr1 = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr1[i] = (int*)malloc(cols * sizeof(int));
    }

    // Dynamically allocating memory for 2nd Matrix
    int **arr2;
    arr2 = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr2[i] = (int*)malloc(cols * sizeof(int));
    }

    Matrix m;
    cout<<"Enter 4 values of 1st Matrix"<<endl;
    m.insertMatrix(arr1);
    cout<<"Enter 4 values of 2nd Matrix"<<endl;
    m.insertMatrix(arr2);
    cout<<"First matrix"<<endl;
    m.printMatrix(arr1);
    cout<<"Second matrix"<<endl;
    m.printMatrix(arr2);
    cout<<"\nAddition of both matrix"<<endl;
    m.addMatrix(arr1, arr2);

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(arr1[i]);
        free(arr2[i]);
    }
    free(arr1);
    free(arr2);
}
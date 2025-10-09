#include<iostream>
using namespace std;

void printMatrix(int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void addMatrix(int arr1[2][2], int arr2[2][2]) {
    int arr[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            arr[i][j] = arr1[i][j]+arr2[i][j];
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main() {
    int arr1[2][2] = {{1, 2}, {4, 5}};
    int arr2[2][2] = {{1, 2,}, {4, 5}};
    cout<<"First matrix"<<endl;
    printMatrix(arr1);
    cout<<"Second matrix"<<endl;
    printMatrix(arr2);
    cout<<"\nAddition of both matrix"<<endl;
    addMatrix(arr1, arr2);
}
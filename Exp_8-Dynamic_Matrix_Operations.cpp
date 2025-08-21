/*
 * Experiment 8: Dynamic Memory Allocation for 2x2 Matrix Operations
 * 
 * This program demonstrates dynamic memory allocation to perform
 * addition and subtraction operations on 2x2 matrices.
 */

#include <iostream>
using namespace std;

class Matrix {
private:
    int** matrix;  // Pointer to pointer for 2D array
    int rows;
    int cols;
    
public:
    // Constructor - allocates memory dynamically
    Matrix(int r = 2, int c = 2) {
        rows = r;
        cols = c;
        
        // Allocate memory for rows
        matrix = new int*[rows];
        
        // Allocate memory for each row
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
        
        // Initialize matrix with zeros
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
        
        cout << "Matrix " << rows << "x" << cols << " created with dynamic memory allocation." << endl;
    }
    
    // Copy constructor - deep copy
    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;
        
        // Allocate memory
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
        
        // Copy values
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    
    // Destructor - deallocates memory
    ~Matrix() {
        // Deallocate each row
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        // Deallocate array of pointers
        delete[] matrix;
        cout << "Matrix memory deallocated." << endl;
    }
    
    // Function to input matrix elements
    void inputMatrix() {
        cout << "Enter matrix elements (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
    }
    
    // Function to display matrix
    void displayMatrix() const {
        cout << "\nMatrix (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++) {
            cout << "| ";
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "|" << endl;
        }
    }
    
    // Function to add two matrices
    Matrix addMatrix(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Error: Matrices must have same dimensions for addition!" << endl;
            return Matrix(rows, cols);
        }
        
        Matrix result(rows, cols);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        
        return result;
    }
    
    // Function to subtract two matrices
    Matrix subtractMatrix(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Error: Matrices must have same dimensions for subtraction!" << endl;
            return Matrix(rows, cols);
        }
        
        Matrix result(rows, cols);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        
        return result;
    }
    
    // Assignment operator overloading
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {  // Avoid self-assignment
            // Deallocate existing memory
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            
            // Allocate new memory
            rows = other.rows;
            cols = other.cols;
            matrix = new int*[rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols];
            }
            
            // Copy values
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
        return *this;
    }
};

int main() {
    cout << "=== Dynamic Matrix Operations ===\n\n";
    
    // Create first matrix
    cout << "Creating first matrix:" << endl;
    Matrix matrix1(2, 2);
    matrix1.inputMatrix();
    matrix1.displayMatrix();
    
    // Create second matrix
    cout << "\nCreating second matrix:" << endl;
    Matrix matrix2(2, 2);
    matrix2.inputMatrix();
    matrix2.displayMatrix();
    
    // Perform matrix addition
    cout << "\n=== Matrix Addition ===" << endl;
    Matrix resultAdd = matrix1.addMatrix(matrix2);
    cout << "Result of addition:";
    resultAdd.displayMatrix();
    
    // Perform matrix subtraction
    cout << "\n=== Matrix Subtraction ===" << endl;
    Matrix resultSub = matrix1.subtractMatrix(matrix2);
    cout << "Result of subtraction:";
    resultSub.displayMatrix();
    
    // Demonstrate copy constructor
    cout << "\n=== Copy Constructor Demonstration ===" << endl;
    Matrix matrixCopy = matrix1;
    cout << "Copied matrix:";
    matrixCopy.displayMatrix();
    
    // Demonstrate assignment operator
    cout << "\n=== Assignment Operator Demonstration ===" << endl;
    Matrix matrixAssign(2, 2);
    matrixAssign = matrix2;
    cout << "Assigned matrix:";
    matrixAssign.displayMatrix();
    
    // Memory management demonstration
    cout << "\n=== Memory Management ===" << endl;
    cout << "All matrices will be automatically deallocated when they go out of scope." << endl;
    
    cout << "\n=== Program completed successfully ===" << endl;
    return 0;
}

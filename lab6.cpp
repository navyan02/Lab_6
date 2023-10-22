// EECS 348 Lab 6 
// Author: Navya Nittala 
#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;

// Function prototypes
void readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const std::string& filename);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    std::cout << "Navya Nittala" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int size;

    // Read matrices from file
    readMatrixFromFile(matrixA, matrixB, size, "matrix_input.txt");

    // Print matrices
    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, size);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, size);

    // Add matrices and print the result
    addMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(result, size);

    // Multiply matrices and print the result
    multiplyMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(result, size);

    // Subtract matrices and print the result
    subtractMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(result, size);

    return 0;
}

// Function to read matrix data from a file and store it in a 2D array
void readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        for (int i = 0; i < 2 * size; i++) {
            if (i < size) {
                for (int j = 0; j < size; j++) {
                    file >> matrixA[i][j];
                }
            } else {
                for (int j = 0; j < size; j++) {
                    file >> matrixB[i - size][j];
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }
}

// Function to display a matrix in a user-friendly format
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "  " << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices and store the result in a third matrix
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to subtract one matrix from another and store the result in a third matrix
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

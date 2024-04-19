#ifndef MATRIXLIB_H
#define MATRIXLIB_H

#include <vector>
#include <stdexcept>
#include <iostream>

/*
 * Creater: Chingyen Huang
 * Date   : 04/18/2024 
 */
class Chingyen_Matrix {
private:
    std::vector<std::vector<double>> data;

public:
    // Initialize Chingyen Metrix (rows * cols)
    Chingyen_Matrix(int rows, int cols) : data(rows, std::vector<double>(cols, 0.0)) {}

    // Let user can modify value and read data without using Chingyen_Matrix method.
    std::vector<double>& operator[](int i) {
        return data[i];
    }
    const std::vector<double>& operator[](int i) const {
        return data[i];
    }

    // Get the size of rows and cols in the matrix
    int getRows() const {
        return data.size();
    }
    int getCols() const {
        return data[0].size();
    }

    // Static function for matrix multiplication
    static Chingyen_Matrix multiply(const Chingyen_Matrix& a, const Chingyen_Matrix& b) {
        if (a.getCols() != b.getRows()) throw std::invalid_argument("Matrix dimensions mismatch for multiplication");

        Chingyen_Matrix result(a.getRows(), b.getCols());
        for (int i = 0; i < a.getRows(); ++i) {
            for (int j = 0; j < b.getCols(); ++j) {
                for (int k = 0; k < a.getCols(); ++k) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    // Static function for matrix transposition
    static Chingyen_Matrix transpose(const Chingyen_Matrix& m) {
        Chingyen_Matrix result(m.getCols(), m.getRows());
        for (int i = 0; i < m.getRows(); ++i) {
            for (int j = 0; j < m.getCols(); ++j) {
                result[j][i] = m[i][j];
            }
        }
        return result;
    }

    // Print matrix 
    void print() const {
        for (const auto& row : data) {
            for (double elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif // MATRIXLIB_H

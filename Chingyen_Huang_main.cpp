#include "Chingyen-Huang_MatrixLib.h"

int main() {
    Chingyen_Matrix A(2, 3);
    Chingyen_Matrix B(3, 2);

    // Create testing matrices A and B
    A[0][0] = 10; 
    A[0][1] = 20; 
    A[0][2] = 30;
    A[1][0] = 40; 
    A[1][1] = 50; 
    A[1][2] = 60;

    B[0][0] = 10; 
    B[0][1] = 20;
    B[1][0] = 30; 
    B[1][1] = 40;
    B[2][0] = 50; 
    B[2][1] = 60;

    // Check Matrix A
    std::cout << "Matrix A:" << std::endl;
    A.print();

    //Check Matrix B
    std::cout << "Matrix B:" << std::endl;
    B.print();

    // Check Chingyen_Matrix multiplication
    Chingyen_Matrix C = Chingyen_Matrix::multiply(A, B);
    std::cout << "Result of multiplication:" << std::endl;
    C.print();

    // Check Chingyen_Matrix transposition
    Chingyen_Matrix D = Chingyen_Matrix::transpose(A);
    std::cout << "Transpose of Matrix A:" << std::endl;
    D.print();

    return 0;
}
#include "matrix1.cpp"
int main(){

    // Create two instances of Matrix
    Matrix<int> matrix1(2,2); 
    Matrix<int> matrix2(2,2); 

    matrix1.fillRandom();
    matrix2.fillRandom();

    std::cout << "Matrix 1:\n" << matrix1 << '\n';
    std::cout << "Matrix 2:\n" << matrix2 << '\n';

    Matrix sum = matrix1 + matrix2;
    std::cout << "Sum of Matrix 1 and Matrix 2:\n" << sum << '\n';

    Matrix diff = matrix1 - matrix2;
    std::cout << "Difference of Matrix 1 and Matrix 2:\n" << diff << '\n';

    Matrix product = matrix1 * matrix2;
    std::cout << "Product of Matrix 1 and Matrix 2:\n" << product << '\n';

    bool isEqual = (matrix1 == matrix2);
    std::cout << "Are Matrix 1 and Matrix 2 equal? " << (isEqual ? "Yes" : "No") << '\n';

    return 0;
}
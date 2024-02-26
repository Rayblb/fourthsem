#include "matrix.hpp"
// Constructor
Matrix::Matrix(unsigned int m, unsigned int n) : m(m), n(n) {
    data = new int*[m];
    for (unsigned int i = 0; i < m; ++i)
        data[i] = new int[n];
}

// Destructor
Matrix::~Matrix() {
    for (unsigned int i = 0; i < m; ++i)
        delete[] data[i];
    delete[] data;
}

// Fill the matrix with random numbers
void Matrix::fillRandom() {
    for (unsigned int i = 0; i < m; ++i)
        for (unsigned int j = 0; j < n; ++j)
            data[i][j] = rand() % 10;
}

// Overload << operator
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.m; ++i) {
        for (unsigned int j = 0; j < matrix.n; ++j)
            os << matrix.data[i][j] << ' ';
        os << '\n';
    }
    return os;
}

// Overload += operator
Matrix& Matrix::operator+=(const Matrix& other) {
    if (m != other.m || n != other.n)
        throw std::invalid_argument("Matrices are not of the same size.");
    for (unsigned int i = 0; i < m; ++i)
        for (unsigned int j = 0; j < n; ++j)
            data[i][j] += other.data[i][j];
    return *this;
}

// Overload + operator
Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(*this); // Copy constructor
    result += other;
    return result;
}

// Overload -= operator
Matrix& Matrix::operator-=(const Matrix& other) {
    if (m != other.m || n != other.n)
        throw std::invalid_argument("Matrices are not of the same size.");
    for (unsigned int i = 0; i < m; ++i)
        for (unsigned int j = 0; j < n; ++j)
            data[i][j] -= other.data[i][j];
    return *this;
}

// Overload - operator
Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(*this); // Copy constructor
    result -= other;
    return result;
}

// Overload * operator
Matrix Matrix::operator*(const Matrix& other) const {
    if (n != other.m)
        throw std::invalid_argument("Matrices are not compatible for multiplication.");
    Matrix result(m, other.n);
    for (unsigned int i = 0; i < m; ++i)
        for (unsigned int j = 0; j < other.n; ++j)
            for (unsigned int k = 0; k < n; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

// Overload == operator
bool Matrix::operator==(const Matrix& other) const {
    if (m != other.m || n != other.n)
        return false;
    for (unsigned int i = 0; i < m; ++i)
        for (unsigned int j = 0; j < n; ++j)
            if (data[i][j] != other.data[i][j])
                return false;
    return true;
}

// Overload != operator
bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}
int main(){
    // Create two instances of Matrix
    Matrix matrix1(4, 4); 
    Matrix matrix2(4, 4); 

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
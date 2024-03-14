#include "matrix1.h"

template <class T>
// Constructor
Matrix<T>::Matrix(int m,  int n) : m(m), n(n) {
    data = new T*[m];
    for (T i = 0; i < m; ++i)
        data[i] = new T[n];
}

template <class T>
// Destructor
Matrix<T>:: ~Matrix() {
    for (T i = 0; i < m; ++i)
        delete[] data[i];
    delete[] data;
}

template <class T>
// Fill the matrix with random numbers
void Matrix<T>::fillRandom() {
    for (T i = 0; i < m; ++i)
        for (T j = 0; j < n; ++j)
            data[i][j] = rand() % 10;
}

template <class T>
// Overload << operator
std::ostream& operator<<(std::ostream& os, const Matrix<T> &matrix){
    for (T i = 0; i < matrix.m; ++i) {
        for (T j = 0; j < matrix.n; ++j)
            os << matrix.data[i][j] << ' ';
        os << '\n';
    }
    return os;
}

template <class T>
// Overload += operator
Matrix<T>& Matrix<T>::operator+=(const Matrix<T> &other) {
    if (m != other.m || n != other.n)
        throw std::invalid_argument("Matrices are not of the same size.");
    for (T i = 0; i < m; ++i)
        for (T j = 0; j < n; ++j)
            data[i][j] += other.data[i][j];
    return *this;
}

template <class T>
// Overload + operator
Matrix<T> Matrix<T>::operator+(const Matrix& other) const {
    Matrix result(*this); // Copy constructor
    result += other;
    return result;
}

template <class T>
// Overload -= operator
Matrix<T>& Matrix<T>::operator-=(const Matrix& other) {
    if (m != other.m || n != other.n)
        throw std::invalid_argument("Matrices are not of the same size.");
    for (T i = 0; i < m; ++i)
        for (T j = 0; j < n; ++j)
            data[i][j] -= other.data[i][j];
    return *this;
}

template <class T>
// Overload - operator
Matrix<T> Matrix<T>::operator-(const Matrix& other) const {
    Matrix result(*this); // Copy constructor
    result -= other;
    return result;
}

template <class T>
// Overload * operator
Matrix<T> Matrix<T>::operator*(const Matrix& other) const {
    if (n != other.m)
        throw std::invalid_argument("Matrices are not compatible for multiplication.");
    Matrix result(m, other.n);
    for (T i = 0; i < m; ++i)
        for (T j = 0; j < other.n; ++j)
            for (T k = 0; k < other.n; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

template <class T>
// Overload == operator
bool Matrix<T>::operator==(const Matrix& other) const {
    if (m != other.m || n != other.n)
        return false;
    for (T i = 0; i < m; ++i)
        for (T j = 0; j < n; ++j)
            if (data[i][j] != other.data[i][j])
                return false;
    return true;
}

template <class T>
// Overload != operator
bool Matrix<T>::operator!=(const Matrix<T>& other) const {
    return !(*this == other);
}

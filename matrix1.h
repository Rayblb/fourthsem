#include <iostream>
#include <cstdlib>

template < class T>
class Matrix{
private:
    int m, n;
    T** data;

public:
    Matrix<T>(int m,  int n);
    ~Matrix<T>();
    void fillRandom();
    template <class T>
    friend std::ostream& operator<< (std::ostream& os, const Matrix<T> &matrix);
    Matrix<T>& operator+=(const Matrix<T>& other);
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T>& operator-=(const Matrix<T>& other);
    Matrix<T> operator-(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    bool operator==(const Matrix<T>& other) const;
    bool operator!=(const Matrix<T>& other) const;
};

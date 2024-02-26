#include <iostream>
#include <cstdlib>

class Matrix {
private:
    unsigned int m, n;
    int** data;

public:
    Matrix(unsigned int m, unsigned int n);
    ~Matrix();
    void fillRandom();
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    Matrix& operator+=(const Matrix& other);
    Matrix operator+(const Matrix& other) const;
    Matrix& operator-=(const Matrix& other);
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;
};

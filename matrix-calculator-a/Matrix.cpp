#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Matrix.hpp"

using namespace std;

namespace zich{

    
    bool operator==(const Matrix& lhs, const Matrix& rhs){
        return true;
    }

    bool operator!=(const Matrix& lhs, const Matrix& rhs){
        return false;
    }

    bool operator>(const Matrix& lhs, const Matrix& rhs){
        return true;
    }

    bool operator<(const Matrix& lhs, const Matrix& rhs){
        return false;
    }

    bool operator>=(const Matrix& lhs, const Matrix& rhs){
        return true;
    }

    bool operator<=(const Matrix& lhs, const Matrix& rhs){
        return false;
    }



    Matrix operator+(const Matrix& lhs, const Matrix& rhs){
        return lhs;
    }

    Matrix operator-(const Matrix& lhs, const Matrix& rhs){
        return lhs;
    }

    Matrix operator-(Matrix& lhs){
        return lhs;
    }

    Matrix operator*(const Matrix& lhs, const Matrix& rhs){
        return lhs;
    }

    Matrix operator*(const Matrix& lhs, double rhs){
        return lhs;
    }

    Matrix operator*(double lhs, const Matrix& rhs){
        return rhs;
    }

    Matrix operator-(const Matrix& mat){
        return mat;
    }

    void operator +=(Matrix& lhs, const Matrix& rhs){
        return;
    }

    void operator -=(Matrix& lhs, const Matrix& rhs){
        return;
    }

    void operator *=(Matrix& lhs, const Matrix& rhs){
        return;
    }

    void operator *=(Matrix& lhs, double rhs){
        return;
    }

    void operator ++(Matrix& lhs){
        return;
    }

    void operator --(Matrix& lhs){
        return;
    }


    std::ostream& operator<<(ostream& os, const Matrix& rhs){
        return os;
    }

    istream& operator>>(istream& is, Matrix& rhs){
        return is;
    }




}
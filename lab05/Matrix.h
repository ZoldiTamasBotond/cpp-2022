
#ifndef LAB04_MATRIX_H
#define LAB04_MATRIX_H

#include <iostream>

using namespace std;

class Matrix {
public:
    // Default constructor
    Matrix( int mRows = 10, int mCols =10);
    // Copy constructor
    Matrix(const Matrix& what);
    // Move constructor
    Matrix( Matrix&& what );
    // Destructor
    ~Matrix();

    //fills the matrix with identical elements
    void fillMatrix(double value);
    //fills the matrix with random real numbers in the range [a, b)
    void randomMatrix(int a, int b); //fills
    //prints the matrix
    void printMatrix(ostream& os = cout) const;

    //checks whether this matrix is a square one
    bool isSquare() const;
    int getRows() const { return this->mRows;}
    int getCols() const { return this->mCols;}

    // operation is permitted on matrices having the same dimensions
    // otherwise throws an out_of_range exception!!
    friend Matrix operator+(const Matrix& x, const Matrix& y);
    // operation is permitted on matrices having proper dimensions
    // otherwise throws an out_of_range exception!!
    friend Matrix operator*(const Matrix& x, const Matrix& y);

    // extractor operator
    friend istream & operator>>(istream& is, Matrix& mat);
    // inserter operator
    friend ostream & operator<<(ostream& os, const Matrix& mat);

    // index operator
    double* operator[] (int index);
    // index operator that works on constant matrices!
    double* operator[] (int index) const;


    // Copy assignment
    // operation is permitted between matrices having the same dimensions
    // otherwise throws an exception (out_of_range)
    Matrix & operator=(const Matrix& mat){
        mRows=mat.mRows;
        mCols=mat.mCols;

        mElements = new double*[mRows];

        for(int i=0;i<mRows;++i){
            mElements[i]=new double[mCols];
        }
        for(int i=0;i<mRows;++i){
            for(int j=0;j<mCols;++j) {
                mElements[i][j] = mat.mElements[i][j];
            }
        }
    }

    // Move assignment
    Matrix & operator=(Matrix&& mat){
        mRows=mat.mRows;
        mCols=mat.mCols;

        mElements = new double*[mRows];

        for(int i=0;i<mRows;++i){
            mElements[i]=new double[mCols];
        }
        for(int i=0;i<mRows;++i){
            for(int j=0;j<mCols;++j) {
                mElements[i][j] = mat.mElements[i][j];
            }
        }
    }

private:
    double ** mElements;
    int mRows;
    int mCols;
};


#endif //LAB04_MATRIX_H

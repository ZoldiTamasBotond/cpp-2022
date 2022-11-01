//
// Created by komuves.david.mark on 10/18/2021.
//

#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

Matrix::Matrix(int a, int b) {
    mRows=a;
    mCols=b;

    mElements = new double*[mRows];

    for(int i=0;i<mRows;++i){
        mElements[i]=new double[mCols];
    }
}
Matrix::Matrix(const Matrix& what) {
    mRows=what.mRows;
    mCols=what.mCols;

    mElements = new double*[mRows];

    for(int i=0;i<mRows;++i){
        mElements[i]=new double[mCols];
    }

    for(int i=0;i<mRows;++i){
        for(int j=0;j<mCols;++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix( Matrix&& what) {
    what.mRows=mRows;
    what.mCols=mCols;

    what.mElements = new double*[mRows];

    for(int i=0;i<mRows;++i){
        what.mElements[i]=new double[mCols];
    }

    for(int i=0;i<mRows;++i){
        for(int j=0;j<mCols;++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::~Matrix() {
    for(int i=0;i<mRows;++i){
        delete [] mElements[i];
    }
    delete [] mElements;
}

void Matrix::fillMatrix(double value) {
    for(int i=0;i<mRows;++i){
        for(int j=0;j<mCols;++j){
            mElements[i][j]=value;
        }
    }
}

void Matrix::randomMatrix(int a, int b){
    for(int i=0;i<mRows;++i){
        for(int j=0;j<mCols;++j){
            mElements[i][j]= (rand()+a)%b;
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for(int i=0;i<mRows;++i){
        for(int j=0;j<mCols;++j){
            os<<setw(8)<<setprecision(2)<< mElements[i][j];
        }
        os<<endl;
    }
}

bool Matrix::isSquare() const {
    return mRows==mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    Matrix newM;
    newM.mRows=x.mRows;
    newM.mCols=y.mCols;

    if(x.mRows==y.mRows && x.mCols==y.mCols){
        for(int i=0;i<x.mRows;++i){
            for(int j=0;j<y.mCols;++j){
                newM.mElements[i][j]=x.mElements[i][j]+y.mElements[i][j];
            }
        }
        return newM;
    }

    throw out_of_range("--err: Different dimensions...");
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    Matrix newM;
    newM.mRows=x.mRows;
    newM.mCols=y.mCols;

    if(x.mRows==y.mCols){
        for(int i=0;i<x.mRows;++i){
            for(int j=0;j<y.mCols;++j){
            newM.mElements[i][j]=0;
                for(int k=0;k<y.mRows;++k){
                    newM.mElements[i][j]+=x.mElements[i][k]*y.mElements[k][j];
                }
            }
        }
        return newM;
    }

    throw out_of_range("--err: Incompatible dimensions...");
}

istream & operator>>(istream& is, Matrix& mat){
    for(int i=0;i<mat.mRows;++i){
        for(int j=0;j<mat.mCols;++j){
            is>>mat.mElements[i][j];
        }
    }

    return is;
}

ostream & operator<<(ostream& os, const Matrix& mat) {
    os<<"{";

    for(int i=0;i<mat.mRows;++i){
        for(int j=0;j<mat.mCols;++j){
            os<<mat.mElements[i][j]<<", ";
        }
        os<<"\n";
    }

    os<<"};";

    return os;
}
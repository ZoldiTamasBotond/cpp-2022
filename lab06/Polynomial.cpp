
#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
    capacity=degree+1;
    this->coefficients = new double [capacity];

    for(int i=0;i<capacity;++i){
        this->coefficients[i]=coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity=that.capacity;
    this->coefficients = new double [capacity];

    for(int i=0;i<capacity;++i){
        this->coefficients[i]=that.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that) {
    this->capacity=that.capacity;
    this->coefficients = new double [capacity];

    for(int i=0;i<capacity;++i){
        this->coefficients[i]=that.coefficients[i];
    }
}

Polynomial::~Polynomial() {
    this->capacity=0;
    delete [] this->coefficients;
}

int Polynomial::degree() const {
    return capacity-1;
}

double Polynomial::evaluate(double x) const {
    double result,temp;

    for(int i=0;i<capacity;++i){
        temp=1;
        for(int j=0;j<capacity-i;++j){
            temp=temp*x;
        }
        result = result + coefficients[i] * temp;
    }

    return result;
}

Polynomial Polynomial::derivative() const {
    return Polynomial(0, nullptr);
}

double Polynomial::operator[](int index) const {
    return 0;
}

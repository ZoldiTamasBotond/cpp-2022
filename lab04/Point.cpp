
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define MAX 2000

#include "Point.h"

using namespace std;

int Point::counter{0};

Point::Point(int x, int y) {
    if(x>=0 && x<=2000 && y>=0 && y<=2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
    this->counter++;
}

Point::Point(const Point& temp) {
    if(x>=0 && x<=2000 && y>=0 && y<=2000){
        this->x = temp.getX();
        this->y = temp.getY();
    }
    else{
        this->x = 0;
        this->y = 0;
    }
    this->counter++;
}

Point::~Point(){
    counter--;
}

int Point::getX() const {
    return x;
}

int Point::getCounter() {
    return counter;
}

int Point::getY() const {
    return y;
}

void Point::setX(int n) {
    x=n;
}

void Point::setY(int n) {
    y=n;
}

void Point::print() const{
    cout<<"\nPoint: "<<" ("<<this->getX()<<", "<<this->getY()<<")"<<endl;
}

double Point::distanceTo(const Point& b)const {
    double x,y;

    x = b.getX() - this->getX();
    x *= x;

    y = b.getY() - this->getY();
    y *= y;

    return sqrt(x + y);
}

int firstDefFunc(){
    vector<int> v;

    for(int i=0;i<10;++i){
        v.push_back(i*10); //push_back OR emplace_back to modify vector size and add elements
    }

    for(int i=0;i<10;++i){
        cout<<v[i]<<" ";
    }

    cout<<endl;
}

int secondDefFunc(){
    int x[100];
    int n = 10;
    cout<<"x = [";
    for(int i=0; i<n; ++i ){
        x[i] = rand() % MAX;
        cout<<x[i]<<" ";
    }
    cout << "]" <<endl;
    cout << "Smallest element from array x: " << *min_element(x, x+n) << endl;

    vector<int> v;
    v.reserve(100);
    cout<<"v = [";
    for(int i=0; i<n; ++i ){
        v.emplace_back( rand() % MAX );
        cout<<v[i]<<" ";
    }
    cout << "]" <<endl;
    cout << "Biggest element from vector v: " << *max_element(v.begin(),v.end()) << endl;

    return 0;
}

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "POINTSET.h"
#include "Point.h"

#define MAX 2000

using namespace std;

PointSet::PointSet(int n) {
    Point x;
    for(int i=0;i<n;++i){
        x.setX(rand () %2000);
        x.setY(rand () %2000);
        points.push_back(x);
    }
}

void PointSet::computeDistances() {
    int i,j;

    for(i=0;i<size;++i){
        for(j=0;j<size;j++){
            if(points[i].getX()!=points[j].getX() && points[i].getY()!=points[j].getY()){
                distances[i][j]=points[i].distanceTo(points[j]);
            }
        }
    }
}

double PointSet::maxDistance() const {
    double result=0;
    int j;

    for(int i=0;i<size;++i){
        for(j=0;j<size;++j){
            if(distances[i][j]>result){
                result=distances[i][j];
            }
        }
    }

    return result;
}

double PointSet::minDistance() const {
    double result=distances[1][2];
    int j;

    for(int i=0;i<size;++i){
        for(j=0;j<size;++j){
            if(distances[i][j]<result){
                result=distances[i][j];
            }
        }
    }

    return result;
}

int PointSet::numDistances() const {
    int j,counter=0;

    for(int i=0;i<size;++i){
        for(j=0;j<size;++j) {
            counter++;
        }
    }

    return counter;
}

void PointSet::printPoints() const {
    cout<<"\nPoints: {";
    for(int i=0;i<size;++i){
        cout<<"["<<points[i].getX()<<","<<points[i].getY()<<"]; ";
    }
    cout<<"};";
}

void PointSet::printDistances() const {
    int j;

    cout<<"\nDistances : {";
    for(int i=0;i<size;++i){
        for(j=0;j<size;++j) {
            cout << "[" << points[i].getX() << "," << points[i].getY() << "] - "<<"[" << points[j].getX() << "," << points[j].getY() << "] - "<<distances[i][j]<<"; ";
        }
    }
    cout<<"};";
}
bool compareFuncX(const Point& a , const Point& b){
    return (a.getX()<b.getX());
}

bool compareFuncY(const Point& a , const Point& b){
    return (a.getY()<b.getY());
}


void PointSet::sortPointsX() {
    sort(points.begin(),points.end(),compareFuncX);
}

void PointSet::sortPointsY() {
    sort(points.begin(),points.end(),compareFuncY);
}

void PointSet::sortDistances() {
    for(int i=0;i<size;++i) {
        sort(distances[i].begin(), distances[i].end());
    }
}

int PointSet::numDistinctDistances() {
    double occurrence[2828]={0};
    int counter=0,i,j,maxi=0;


    for(i=0;i<size;++i){
        for(j=0;j<size;++j) {
            occurrence[(int)distances[i][j]]++;
            if((int)distances[i][j]>maxi){
                maxi=(int)distances[i][j];
            }
        }
    }

    for(i=0;i<maxi;++i){
        if(occurrence[i]==1){
            counter++;
        }
    }

    return counter;
}

void PointSet::load(Point x) {
    points.push_back(x);
}

void PointSet::accessDistances() {
    distances.reserve(2000);
    for(int i=0;i<2000;++i){
        distances[i].reserve(2000);
    }

    computeDistances();
}

int pointsetMain(){
    int nrPoints,i,x,y;

    cout<<"\nNumber of points to generate: ";
    cin>>nrPoints;
    PointSet * ps = new PointSet(nrPoints);
    Point * temp;

    for(i=0;i<nrPoints;++i){
        x = rand() % MAX;
        y = rand() % MAX;
        temp = new Point(x,y);
        ps->load(*temp);
    }
    ps->printPoints();

    ps->accessDistances();

    cout<<"\nMaximum distance between two points: "<<ps->maxDistance();
    cout<<"\nMinimum distance between two points: "<<ps->minDistance();
    cout<<"\nNumber of distances: "<<ps->numDistances();
    ps->printPoints();
    ps->printDistances();
    ps->sortPointsX();
    cout<<"\n--Sorted after X coordinates";
    ps->printPoints();
    ps->sortPointsY();
    cout<<"\n--Sorted after Y coordinates";
    ps->printPoints();
    ps->sortDistances();
    cout<<"\n--Sorted distances";
    ps->printDistances();
    cout<<"\nNumber of distinct distances: "<<ps->numDistinctDistances();

    return 0;
}


#include <iostream>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Point.h"

using namespace std;

Point::Point(int x, int y, string name){
    if(x>=0 && x<=2000 && y>=0 && y<=2000){
        this->x = x;
        this->y = y;
        this->name = name;
    }
    else{
        this->x = 0;
        this->y = 0;
        this->name = "";
    }
}

int Point::getX() const {
    return x;
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
string Point::getName() const {
    return name;
}
void Point::print() const{
    cout<<"\nPoint: "<<this->getName()<<" ("<<this->getX()<<", "<<this->getY()<<")"<<endl;
}

double distance(const Point& a, const Point& b){
    double result=0,x,y;

    x = b.getX() - a.getX();
    x *= x;
    //cout<<"\nhe;"<<x;

    y = b.getY() - a.getY();
    y *= y;
    //cout<<"\nhe;"<<y;

    result = sqrt(x + y);

    return result;
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d){
    if(distance(a,b)==distance(b,c) && distance(a,b)==distance(c,d) && distance(a,b)==distance(d,a) && distance(a,c)==distance(b,d)){
        return true;
    }
    return false;
}

void testIsSquare(const char * filename){
    cout<<"\n\nStarting the testing of <"<<filename<<"> input file...\n";

    Point * a = new Point();
    Point * b = new Point();
    Point * c = new Point();
    Point * d = new Point();

    int checker=-1,counter=1;

    ifstream read;
    read.open(filename);

    while(!read.eof()){
        cout<<endl;
        read>>checker;
        a->setX(checker);

        read>>checker;
        a->setY(checker);

        read>>checker;
        b->setX(checker);

        read>>checker;
        b->setY(checker);

        read>>checker;
        c->setX(checker);

        read>>checker;
        c->setY(checker);

        read>>checker;
        d->setX(checker);

        read>>checker;
        d->setY(checker);
        if(isSquare(*a,*b,*c,*d)){
            cout<<counter<<": YES";
        }
        else{
            cout<<counter<<": NO";
        }
        counter++;
    }

    read.close();
}

Point* createArray(int numPoints){
    Point * arrayOfPoints;
    arrayOfPoints = new Point[numPoints];
    int a,b;

    for(int i=0;i<numPoints;++i){
        a = rand() % 2000;
        b = rand() % 2000;
        arrayOfPoints[i].setY(a);
        arrayOfPoints[i].setX(b);
    }

    return arrayOfPoints;
}

void printArray(Point* array, int numPoints){
    cout<<"\nContents of the array of points:";
    for(int i=0;i<numPoints;++i){
        cout<<"\n"<<i+1<<": ";array[i].print();
    }
    delete(array);
}

pair<Point,Point> closestPoints(Point* array, int numPoints){
    printArray(array,numPoints);

    pair<Point,Point> result;
    int j;
    double min=distance(array[0],array[1]),temp;

    result.first=array[0];
    result.second=array[1];

    for(int i=0;i<numPoints;++i){
        for(j=i+1;j<numPoints;++j){
            temp = distance(array[i],array[j]);
            //cout<<"\ncurrent comparison: "<<temp;
            if(temp<min){
                min=temp;
                result.first=array[i];
                result.second=array[j];
            }
        }
    }
    delete(array);
    return result;
}

pair<Point, Point> farthestPoints(Point* array, int numPoints){
    printArray(array,numPoints);

    pair<Point,Point> result;
    int j;
    double max=0,temp;

    result.first=array[0];
    result.second=array[1];

    for(int i=0;i<numPoints;++i){
        for(j=i+1;j<numPoints;++j){
            temp = distance(array[i],array[j]);
            cout<<"\ncurrent comparison: "<<temp;
            if(temp>max){
                max=temp;
                result.first=array[i];
                result.second=array[j];
            }
        }
    }

    delete(array);
    return result;
}
bool compareFunc(const Point& a , const Point& b){
    return (a.getX()<b.getX());
}

void sortPoints(Point* array, int numPoints){
    vector<Point> vector(array,array+numPoints);

    sort(vector.begin(),vector.end(),compareFunc);
}

void farthestPointsFromOrigin(Point* array, int numPoints){
    double * distanceArray,max;
    distanceArray = new double[numPoints+1];

    Point * Origin = new Point(0, 0);

    int i,j,counter=0,maxPointer;
    for(i=0;i<numPoints;++i){
        distanceArray[i]=distance(*Origin,array[i]);
    }

    cout<<"check";
    for(i=0;i<numPoints || counter<=10;++i){
        max=0;
        for(j=0;j<numPoints;++j){
            if(distanceArray[j]>max){
                max=distanceArray[j];
                maxPointer=j;
            }
        }
        cout<<endl<<counter<<": "<<distanceArray[maxPointer];array[maxPointer].print();
        distanceArray[maxPointer]=0;
        counter++;
    }

    delete(distanceArray);
    delete(array);
}

void deletePoints(Point* array,int numPoints){
    /*
    for(int i=0;i<numPoints;++i){
        delete(array[i]);
    }
     */
    delete(array);
}

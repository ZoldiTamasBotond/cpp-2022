//
// Created by komuves.david.mark on 9/27/2021.
//

#ifndef LAB02_POINT_H
#define LAB02_POINT_H

#include <iostream>

using namespace std;

class Point {
private:
    int x, y;
    string name;
public:
    Point(int x=0, int y=0, string name = {""} );
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);
    string getName() const;

    void print() const;
};

double distance(const Point&, const Point&);
bool isSquare(const Point&, const Point&, const Point&, const Point&);
void testIsSquare(const char *);
Point* createArray(int);
void printArray(Point*, int);
pair<Point,Point> closestPoints(Point*, int);
pair<Point, Point> farthestPoints(Point*, int);
bool compareFunc(const Point&, const Point&);
void sortPoints(Point*, int);
void farthestPointsFromOrigin(Point*, int);
void deletePoints(Point*,int);


#endif //LAB02_POINT_H

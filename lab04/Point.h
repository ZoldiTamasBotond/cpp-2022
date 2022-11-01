//
// Created by komuves.david.mark on 10/11/2021.
//

#ifndef LAB06_POINT_H
#define LAB06_POINT_H

class Point{
private:
    int x, y;
    static int counter;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);
    void print() const;
    double distanceTo(const Point& point)const ;
    Point(const Point&);
    ~Point();
    static int getCounter();
};


#endif //LAB06_POINT_H


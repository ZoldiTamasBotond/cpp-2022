//
// Created by komuves.david.mark on 10/11/2021.
//

#ifndef LAB03_POINTSET_H
#define LAB03_POINTSET_H

#include "Point.h"
#include <vector>

using namespace std;

class PointSet{
    vector<Point> points;
    int size;
    vector<vector<double>> distances;
    void computeDistances();
public:
    PointSet( int size = 100 );
    void load(Point);
    void accessDistances();

    double maxDistance() const;
    double minDistance() const;
    int numDistances() const;
    void printPoints() const;
    void printDistances() const;
    void sortPointsX();
    void sortPointsY();
    void sortDistances();
    int numDistinctDistances();
};

int pointsetMain();

#endif //LAB03_POINTSET_H

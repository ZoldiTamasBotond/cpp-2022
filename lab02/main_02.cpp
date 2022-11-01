#include <iostream>
#include <math.h>
#include "Point.h"

using namespace std;

int main(int argc, char** argv) {
    Point * p1 = new Point();
    Point * p2 = new Point();
    Point * pp1 = new Point();
    Point * pp2 = new Point();

    pair<Point,Point> temp;

    int x,y,choice=-1,numPoints;
    char * name;
    name = (char*)calloc(25,sizeof(char));
    if(name==NULL){
        cout<<"all. err";
        return -1;
    }

    while(choice<0 || choice>11){
        cout<<"\n\nAvailable exercises:\n";
        cout<<"\n1. Print a point;";
        cout<<"\n2. Distance between two points;";
        cout<<"\n3. Do four points form a square;";
        cout<<"\n4. Square tester - points.txt;";
        cout<<"\n5. Create an array with N random points;";
        cout<<"\n6. Print a parameter given array;";
        cout<<"\n7. Find the two closest points in an array of points;";
        cout<<"\n8. Find the two furthest points in an array of points;";
        cout<<"\n9. Sort an array of points;";
        cout<<"\n10. Furthest 10 points from Origin;";
        cout<<"\n11. Free an array of points;";
        cout<<"\n\n0. Exit...";
        cout<<"\n\nInput:";
        cin>>choice;
    }
    switch (choice) {
        case 0:
            return 0;
        case 1:
            cout << "\nX coordinates:";
            cin >> x;
            cout << "\nY coordinates:";
            cin >> y;
            cout << "\nName:";
            cin.getline(name, 25);
            cin.getline(name, 25);
            p1 = new Point(x, y, name);
            p1->print();
            break;
        case 2:
            cout << "\nFirst one:";
            cout << "\nX coordinates:";
            cin >> x;
            cout << "\nY coordinates:";
            cin >> y;
            cout << "\nName:";
            cin.getline(name, 25);
            cin.getline(name, 25);
            p1 = new Point(x, y, name);
            cout << "\nSecond one:";
            cout << "\nX coordinates:";
            cin >> x;
            cout << "\nY coordinates:";
            cin >> y;
            cout << "\nName:";
            cin.getline(name, 25);
            cin.getline(name, 25);
            p2 = new Point(x, y, name);
            cout << "\nDistance between '"<<p1->getName()<<"' and '"<<p2->getName()<<"' points: " << distance(*p1, *p2);
            break;
        case 3:
            cout << "\nFirst one:";
            cout << "\nX coordinates:";
            cin >> x;
            cout << "\nY coordinates:";
            cin >> y;
            cout << "\nName:";
            cin.getline(name, 25);
            cin.getline(name, 25);
            p1 = new Point(x, y, name);
            cout << "\nSecond one:";
            cout << "\nX coordinates:";
            cin >> x;
            cout << "\nY coordinates:";
            cin >> y;
            cout << "\nName:";
            cin.getline(name, 25);
            cin.getline(name, 25);
            p2 = new Point(x, y, name);
            cout << "\nThird one:";
            cout << "\nX coordinates:";
            cin >> x;
            cout << "\nY coordinates:";
            cin >> y;
            cout << "\nName:";
            cin.getline(name, 25);
            cin.getline(name, 25);
            pp1 = new Point(x, y, name);
            cout << "\nFourth one:";
            cout << "\nX coordinates:";
            cin >> x;
            cout << "\nY coordinates:";
            cin >> y;
            cout << "\nName:";
            cin.getline(name, 25);
            cin.getline(name, 25);
            pp2 = new Point(x, y, name);
            cout << "\nAbility to form a square: " << isSquare(*p1, *p2, *pp1, *pp2);
            break;
        case 4:
            testIsSquare("points.txt");
            break;
        case 5:
            cout<<"\n\nPlease give the number of randomly generated points: ";
            cin>>numPoints;
            p1 = createArray(numPoints);
            cout<<"\nTitle of the array: "<<p1;
            break;
        case 6:
            cout<<"\nThis function will be tested using a randomly generated array...\nPlease give the number of randomly generated points: ";
            cin>>numPoints;
            printArray(createArray(numPoints),numPoints);
            break;
        case 7:
            cout<<"\nThis function will be tested using a randomly generated array...";
            numPoints=0;
            while(numPoints<2){
                cout<<"\nPlease give the number of randomly generated points: ";
                cin>>numPoints;
            }
            temp=closestPoints(createArray(numPoints), numPoints);
            cout<<"\nThe two closest points: ";temp.first.print();temp.second.print();
            break;
        case 8:
            cout<<"\nThis function will be tested using a randomly generated array...";
            numPoints=0;
            while(numPoints<2){
                cout<<"\nPlease give the number of randomly generated points: ";
                cin>>numPoints;
            }
            temp=farthestPoints(createArray(numPoints), numPoints);
            cout<<"\nThe two farthest points: ";temp.first.print();temp.second.print();
            break;
        case 9:
            cout<<"\nThis function will be tested using a randomly generated array...";
            numPoints=0;
            while(numPoints<2){
                cout<<"\nPlease give the number of randomly generated points: ";
                cin>>numPoints;
            }
            p1 = new Point[numPoints];
            p1 = createArray(numPoints);
            sortPoints(p1,numPoints);
            printArray(p1,numPoints);
            break;
        case 10:
            numPoints=0;
            while(numPoints<10) {
                cout << "\nPlease give the number of points (minimum of 10): ";
                cin >> numPoints;
            }
            p1 = new Point[numPoints+1];
            for(int i=0;i<numPoints;++i){
                cout<<endl<<i+1;
                cout<<"\nX coordinate:";
                cin>>x;
                p1[i].setX(x);
                cout<<"\nY coordinate:";
                cin>>x;
                p1[i].setY(x);
            }
            farthestPointsFromOrigin(p1,numPoints);
            break;
        case 11:
            cout<<"\n\nPlease give the number of randomly generated points: ";
            cin>>numPoints;
            p1 = createArray(numPoints);
            deletePoints(p1,numPoints);
            break;
    }

    free(name);
    delete p1;
    delete p2;
    delete pp1;
    delete pp2;

    main(argc, argv);
    return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Point.h"
#include "POINTSET.h"

using namespace std;

int main() {
    int choice=-1;

    while(choice<0 || choice>3){
        cout<<"\n\nAvailable exercises:\n1 - First given vector test;\n2 - Second given vector test;\n3 - PointSet exercise collection;\n\n0 - Exit.\n\nInput:";
        cin>>choice;
    }

    switch (choice) {
        case 1:
            firstDefFunc();
            break;
        case 2:
            secondDefFunc();
            break;
        case 3:
            pointsetMain();
            break;
        case 0:
            return 0;
    }

    //main();

    return 0;



}

#include <iostream>
#include "functions.h"

using namespace std;

int main(){
    int choice=-1;
    string text;

    while(choice<0 || choice>9){
        cout << "\nWelcome! \nNote: The program will rerun after every function call, but the results can still be found in the output console.\n\nAvailable exercises:\n- Bit related - 1(Count bits from 1 to 128), 2(Set bits);\n\n- Array related - 3(Mean of an array), 4(Standard deviation of an array), 5(Two maximums from an array);\n\n- String related - 6(Add numerical arguments), 7(Count words of given text), 8(Code and decode), 9(Capitalize words).\n\n- Type '0' to EXIT...\n\nPlease input the exercise number:";
        cin >> choice;
    }

    switch (choice) {
        case 0:
            return 0;
        case 1:
            for(int i=0;i<128;++i){
                cout<<i<<" - "<<countBits(i)<<endl;
            }
            break;
        case 2:
            for (int i = 0; i < 35; ++i) {
                int n = 0;
                if(setBit(n, i)){
                    cout<<i<<" ---> " << n <<endl;
                }else{
                    cout<<"Impossible operation!" << endl;
                }
            }
            break;
        case 3:
            arrayMean();
            break;
        case 4:
            standardDev();
            break;
        case 5:
            maxSearch();
            break;
        case 6:
            first();
            break;
        case 7:
            text = "A kacsa a tavon uszkal.";
            countWords(text);
            break;
        case 8:
            third();
            break;
        case 9:
            fourth();
            break;
    }

    cout<< "\t- o -\n";
    main();

    return 0;
}

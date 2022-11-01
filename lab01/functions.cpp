//
// Created by Zoldi Tamas Botond on 2022-09-21.
//

#include "functions.h"
///bit exercises
//1
int countBits(int number){
    int counter=0;
    while(number){
        counter += number & 1;
        number >>= 1;
    }

    return counter;
}
//2
bool setBit(int& number, int order){
    if(order>31){
        return false;
    }
    else{
        number |= 1UL << order;
        return true;
    }
}
///Arrays
//3
int arrayMean(){
    cout<<"Number of elements: ";
    int numElements;
    double* array;
    cin >> numElements;
    if(numElements==0){
        return NAN;
    }

    array=(double*)calloc(numElements,sizeof(double));

    cout<<endl<<"Numbers: ";
    for(int i=0;i<numElements;++i){
        cin >> array[i];
    }

    cout << mean(array,numElements);

    free(array);

    return 0;
}

double mean(double* array, int numElements){
    double sum=0, num;
    num=numElements;
    for(int i=0;i<numElements;++i){
        sum = sum + array[i];
    }

    return sum/num;
}

//4.
int standardDev(){
    cout<<"Number of elements: ";
    int numElements;
    double* array;
    cin >> numElements;
    if(numElements==0){
        return NAN;
    }

    array=(double*)calloc(numElements,sizeof(double));

    cout<<endl<<"Numbers: ";
    for(int i=0;i<numElements;++i){
        cin >> array[i];
    }

    cout << stddev(array,numElements);

    free(array);

    return 0;
}

double stddev(double* array, int numElements){
    double currentMean, dev=0, temp;
    currentMean = mean(array,numElements);

    for(int i=0;i<numElements;++i){
        temp = array[i] - currentMean;
        dev = dev + temp*temp;
    }

    return dev/numElements;
}

//5
int maxSearch(){
    cout<<"Number of elements: ";
    int numElements;
    double* array;
    cin >> numElements;
    if(numElements==0){
        return NAN;
    }

    array=(double*)calloc(numElements,sizeof(double));

    cout<<endl<<"Numbers: ";
    for(int i=0;i<numElements;++i){
        cin >> array[i];
    }

    pair<double, double> result = max2(array, numElements);
    cout<<"First: "<<result.first<<" ; Second: "<<result.second;

    free(array);

    return 0;
}

pair<double , double> max2(double array[], int numElements){
    double first = 0, second =0;
    int count =0;
    std::pair<double, double> result;
    if(numElements == 0){
        result.first = nan("");
        result.second = nan("");
    }

    for(int i=0; i<numElements; ++i){
        if(array[i] > result.first) result.first = array[i];
    }
    for(int i=0; i<numElements; ++i){
        if(array[i] > result.second && array[i] != result.first) result.second = array[i];
        if(array[i] == result.first) ++count;
    }
    if(count > 1) result.second = result.first;
    return result;
}
///Strings
//6
int first(){
    string text("1 2 3  alma 4");
    istringstream iss(text);
    double number,sum=0;
    while(iss >> number){
        sum+=number;
    }

    cout<<"Sum for string: - '"<<text<<"' - is: "<<sum;

    return 0;
}
//7
int countWords(string text){
    istringstream stream(text);

    string word;

    int counter=0;

    while(stream >> word) {
        counter++;
    }

    cout <<"\nNumber of words in - '"<<text<<"' - is:"<< counter;
}

//8
int third(){
    char text[100];
    int choice=0;

    cout<<"Enter your sentence: ";

    cin.getline(text, 100);
    cin.getline(text, 100);

    while(choice<1 || choice>3){
        cout<<endl<<"Would you like to code(1), decode(2) or do both operations(3) for this sentence? : ";
        cin >> choice;
    }

    switch (choice) {
        case 1:
            code(text);
            break;
        case 2:
            decode(text);
            break;
        case 3:
            decode(code(text));
            break;
    }

    return 0;
}

string code(string text){
    int i=0;

    cout<<"\nCoded: ";

    while(text[i]!='\0'){
        if(text[i]==90 || text[i]==122){
            text[i]-=25;
        }
        else{
            if(text[i]!=32 && ((text[i]>64 && text[i]<91) || (text[i]>96 && text[i]<123))) {
                text[i] += 1;
            }
        }

        cout << text[i];
        i++;
    }

    return text;
}

string decode(string text){
    int i=0;

    cout<<"\nDecoded: ";

    while(text[i]!='\0'){
        if(text[i]==65 || text[i]==97){
            text[i]+=25;
        }
        else{
            if(text[i]!=32 && ((text[i]>64 && text[i]<91) || (text[i]>96 && text[i]<123))) {
                text[i] -= 1;
            }
        }

        cout << text[i];

        i++;
    }

    return text;
}

//9
int fourth(){
    char text[100];

    cout<<"Enter your sentence: ";

    cin.getline(text, 100);
    cin.getline(text, 100);

    cout<<capitalizeWords(text);
}

string capitalizeWords(string text){
    int i=0;

    if(text[0]>96 && text[0]<123){
        text[0]-=32;
    }

    i++;

    while(text[i]!='\0'){
        if((text[i-1]==' ') && (text[i]>96 && text[i]<123)){
            text[i]-=32;
        }
        else{
            if(text[i]>64 && text[i]<91){
                text[i]+=32;
            }
        }

        i++;
    }

    return text;
}
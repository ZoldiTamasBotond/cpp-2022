//
// Created by Zoldi Tamas Botond on 2022-09-21.
//

#ifndef LAB01_FUNCTIONS_H
#define LAB01_FUNCTIONS_H

#include <string>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
int countBits(int number);
bool setBit(int& number, int order);
///Arrays
//3
int arrayMean();
double mean(double* ,int );
//4
int standardDev();
double stddev(double*, int);
//5
int maxSearch();
pair<double, double> max2(double array[], int numElements);

///Strings
//6
int first();
//7
int countWords(string);
//8
int third();
string code(string);
string decode(string);
//9
int fourth();
string capitalizeWords(string);

#endif //LAB01_FUNCTIONS_H

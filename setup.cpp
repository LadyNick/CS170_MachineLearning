#include "setup.h"
#include <iostream>
using namespace std;

void setup(int &featurenums, int &choosetype){

    int type;
    bool chosen = false;

    cout << "Welcome to 862126786 Feature Selection Algorithm.";<<endl
    cout << "Enter the total # of features: ";
    cin >> featurenums;

    cout << "Enter Algorithm Type\n";
    cout << "[1]Forward Selection\n[2]Backward Elimination" <<endl;
    cin >> type;

    while(!chosen){
        if(type == 1){
            cout << "Use Forward Selection Algorithm"<<endl;
            chosen = true;
        }
        else if(type == 2){
            cout << "Use Backward Elimination Algorithm"<<endl;
            chosen = true;
        }
        else{
            cout << "Invalid Input, enter again: ";
            cin >> type;
        }
    }
    choosetype = type;
}
#include "algorithms.h"
#include "problem.h"
#include <iostream>
using namespace std;

int main(){
    int features, algorithm;
    double ranaccuracy;

    setup(features, algorithm);

    problem* myBoard = new problem(features, algorithm);
    problem* solution = new problem();

    srand(time(NULL));
    
    if(algorithm == 1){
        ranaccuracy = randomval();
        cout << "Using no features and \"random\" evaluation, accuracy is " << ranaccuracy << "%" << endl<<endl;
        cout << "Sraching..." << endl<<endl;
        solution = ForwardSelection(myBoard);
    }
    else if(algorithm == 2){
        ranaccuracy = randomval();
        cout << "Using all features() {";
        for(int i = 1; i <= features; i++){
                if(i == features){
                    cout << i;
                }
                else{
                    cout << i << ",";
                }
            }
        cout << "}   and \"random\" evaluation, accuracy is " << ranaccuracy << "%" << endl << endl;
        cout << "Searching..." << endl <<endl;
        solution = BackwardElimination(myBoard);
    }

    solution->solution();
    cout << endl << "currently this is going off of greedy so the answer may not appear the best" << endl;
    
}

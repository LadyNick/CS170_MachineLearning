#include "algorithms.h"
#include "problem.h"
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

//returns a randomvalue, since were starting with random accuracies for the subsets of features
double randomval(){
    double val = rand() % 1000;
    return val / 10;
}

//works out the forward selection algorithms
problem* ForwardSelection(problem* startstate){
    std::priority_queue<problem*, std::vector<problem*>, sortAccu> children;
    if(startstate->remainingSize() == 0){
        return startstate;
    }
    for(int i = 0; i < startstate->remainingSize(); i++){
        problem* child = startstate->generateForwardChild(i);
        child->print();
        children.push(child);
    }

    cout << endl<<endl;
    
    if(children.top()->remainingSize() != 0)
        children.top()->printbestset();

    return ForwardSelection(children.top());
}

//works out the backward selection algorithm
problem* BackwardElimination(problem* startstate){
    std::priority_queue<problem*, std::vector<problem*>, sortAccu> children;

    if(startstate->featsize() == 0){
        return startstate;
    }
    for(int i = 0; i < startstate->featsize(); ++i){
        problem* child = startstate->generateBackwardsChild(i);
        child->print();
        children.push(child);
    }

    cout << endl<<endl;

    if(children.top()->featsize() != 0){
        children.top()->printbestset();
    }

    return BackwardElimination(children.top());
}
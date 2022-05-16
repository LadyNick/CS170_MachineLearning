#ifndef __PROBLEM_H__
#define __PROBLEM_H__

#include "setup.h"
#include "algorithms.h"
#include <vector>
using namespace std;

class problem{
    private:
        //vector holding list of features
        vector<int> features;
        //features that havent been included yet 
        vector<int> remainingfeat;
        //holds parent node
        problem* parent;
        //holds accuracy for state/set of features
        double accuracy;
    public:
        problem();
        problem(int start, int choose);
        ~problem();

        problem* generateForwardChild(int index);
        problem* generateBackwardsChild(int index);

        void print();
        void printbestset();
        void solution();

        void addfeatures(int index, int select);
        double getAccuracy();
        vector<int> getVector();
        problem* getParent();
        int remainingSize();
        int featsize();
};

struct sortAccu{
    bool operator()(problem* const b1, problem* const b2){
        return b1->getAccuracy() < b2->getAccuracy();
    }
};

#endif
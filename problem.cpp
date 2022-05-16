#include "problem.h"
#include <iostream>


//returns the accuracy of using the set
double problem::getAccuracy(){
    return this->accuracy;
}

//returns parent node
problem* problem::getParent(){
    return this->parent;
}

//returns the # of features
int problem::featsize(){
    return (int)features.size();
}

//returns size of features not accounted for
int problem::remainingSize(){
    return (int)remainingfeat.size();
}

//constructor given no arguments
problem::problem(){
    features = {};
    accuracy = 0.00;
    remainingfeat = {};
    parent = NULL;
}

//constructor given arguments
problem::problem(int start, int choose){
    features = {};
    accuracy = 0.00;
    addfeatures(start, choose);
    parent = NULL;
}

//function that generates the next child when using the forward algorithm
problem* problem::generateForwardChild(int index){
    problem* forchild = new problem();
    forchild->features = getVector();
    forchild->features.push_back(remainingfeat.at(index));
    forchild->accuracy = randomval();
    
    vector<int> remtemp = this->remainingfeat;

    remtemp.erase(remtemp.begin() + index);

    forchild->remainingfeat = remtemp;
    forchild->parent = this;

    return temp;
}

//function that generates the next child when using the backward algorithm
problem* problem::generateBackwardsChild(int index){
    problem* backchild = new problem();
    vector<int> remtemp = getVector();
    remtemp.erase(remtemp.begin() + index);
    backchild->features = remtemp;
    backchild->accuracy = randomval();
    backchild->remainingfeat = this->remainingfeat;
    backchild->parent = this;

    return backchild;
}

//prints the accurracy using the feature subset
void problem::print(){
    cout << "Using features() {";

    for(int i = features.size() - 1; i >= 0; i--){
        if(i == 0){
            cout << features[i];
        }
        else{
            cout << features[i] << ",";
        }
    }

    cout << "} accuracy is " << accuracy << "%" << endl;
}

//returns feature vector
vector<int> problem::getVector(){
    return this->features;
}

void problem::printbestset(){
    cout << "Feature set {";
    
    for(int i = features.size() - 1; i >= 0; i--){
        if(i == 0){
            cout << features[i];
        }
        else{
            cout << features[i] << ",";
        }
    }

    cout << "} was best, accuracy is " << accuracy << "%" <<endl<<endl<<endl;    
}

//prints the subset with the overall best accuracy
void problem::solution(){
    cout << "The best feature subset is {";

    for(int i = features.size() - 1; i >= 0; i--){
        if(i == 0){
            cout << features[i];
        }
        else{
            cout << features[i] << ",";
        }
    }

    cout << "}, which has an accuracy of " << accuracy << "%"<<endl;

}

//this adds features to the subset when making a new set
void problem::addfeatures(int index, int select){
    for(unsigned i = 1; i <= index; i++){
        if(select == 1){
            remainingfeat.push_back(i);
        }
        else{
            features.push_back(i);
        }
    }
}


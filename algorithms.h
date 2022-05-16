#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__

#include "setup.h"

class problem;
#include "problem.h"
using namespace std;


double randomval();
problem* ForwardSelection(problem* startstate);
problem* BackwardElimination(problem* startstate);

#endif
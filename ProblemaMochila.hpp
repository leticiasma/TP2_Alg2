#ifndef PROBLEMAMOCHILA_H
#define PROBLEMAMOCHILA_H

#include<vector>
//#include <queue>
#include <iostream>
#include "Auxiliares.hpp"

using namespace std;

class ProblemaMochila{

	public:
		int numItens = -1;
		float pesoMax = -1;
		vector<pair<float,float>> paresValorPeso;
		//priority_queue<pair<int, int>> fila;

		float solBacktracking(unsigned int item, float W, float V);
		//float solBranchAndBound(unsigned int item, float W, float V);//, priority_queue<pair<int, int>> fila, float melhor);

		float knapsack(float W, int n);
		//ProblemaMochila();  //(ifstream& entrada);
};

#endif
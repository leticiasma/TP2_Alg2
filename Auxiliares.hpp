#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <queue>
using namespace std;

struct Item{
    float peso;
    float valor;
};
  
struct Node{
    int nivel; 
    float peso, profit, bound;
}; 

class Auxiliares{
	public:
		bool compValorRelativoPar(const pair<float,float> &a, const pair<float,float> &b);
		float bound(No u, int n, int W, vector<pair<float,float>> itens);	
};


#endif
#include<vector>
#include <iostream>

using namespace std;

class ProblemaMochila{

	public:
		int numItens = -1;
		float pesoMax = -1;
		vector<pair<float,float>> paresValorPeso;

		float solBacktracking(unsigned int item, float W, float V);
		float solBranchAndBound(unsigned int item, float W, float V, float melhor);

		//ProblemaMochila();  //(ifstream& entrada);
};
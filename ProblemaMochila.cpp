#include "ProblemaMochila.hpp"

float ProblemaMochila::solBacktracking(unsigned int item, float W, float V){

	if (item < this->paresValorPeso.size()){
		//cout<<"Entrou"<<endl;
		float valorCom = -1;
		float valorSem = -1;
		float novoW = W - this->paresValorPeso[item].second;

		//cout<<"Peso item atual "<<this->paresValorPeso[item].second<<endl;

		if (novoW >= 0){
			//cout<<"O item "<<item<<" pode ser adicionado!"<<endl;
			//itensAdicionados.push_back(item);

			valorCom = this->solBacktracking(item+1, novoW, V+this->paresValorPeso[item].first);
		}

		valorSem = this->solBacktracking(item+1, W, V);

		//cout<<"COM: "<<valorCom<<endl;
		//cout<<"SEM: "<<valorSem<<endl;
		if (valorCom > valorSem){
			return valorCom;
		}
		else{
			return valorSem;
		}
	}
	else{
		return V;
	}

}

/*float ProblemaMochila::solBranchAndBound(unsigned int item, float W, float V){//, priority_queue<pair<int, int>> fila, float melhor){

	float melhorProfit = 0;
	priority_queue<pair<float, float>> fila;


	float nivelU = -1;
	float pesoU = 0;
	float profitU = 0;

	float boundU = this->paresValorPeso[nivelU+1].first + W*(this->paresValorPeso[nivelU+2].first/this->paresValorPeso[nivelU+2].second);

	float pesoV = 0;
	float profitV = 0;

	float nivelV = 0;
	float boundV = 0;

	fila.push(make_pair (nivelV, boundV));

	pair<float, float> u = make_pair(-1,-1);
	pair<float, float> v = make_pair(-1,-1);

	while (!fila.empty()){
		u = fila.top();
		fila.pop();

		if (u.first == -1){
            v.first = 0;
		}

        if (u.first == this->paresValorPeso.size()-1){
            continue;
        }

        v.first = u.first + 1;

        pesoV = pesoU + this->paresValorPeso[v.first].second;
        profitV = profitU + this->paresValorPeso[v.first].first;
  
  		if (pesoV <= W && profitV > melhorProfit){
            melhorProfit = profitV;
  		}

  		boundV = this->paresValorPeso[u.first].first + (W-this->paresValorPeso[u.first].second)*(this->paresValorPeso[v.first].first/this->paresValorPeso[v.first].second);

		cout<<boundV<<endl;

		if (v.bound > melhorProfit)
            fila.push(v);

		
	}
    

	if (item < this->paresValorPeso.size()){

		float valorCom = -1;
		float valorSem = -1;
		float novoW = W - this->paresValorPeso[item].second;
		float valorRelativoProx = this->paresValorPeso[item+1].first/this->paresValorPeso[item+1].second;

		float estimativaCom = (V+this->paresValorPeso[item].first) + novoW*valorRelativoProx;
		float estimativaSem = V + W*valorRelativoProx;

		if (estimativaCom > estimativaSem){
			if (novoW >= 0){
				valorCom = this->solBranchAndBound(item+1, novoW, V+this->paresValorPeso[item].first);
			}
		valorSem = this->solBranchAndBound(item+1, W, V);

		if (valorCom > valorSem){
			return valorCom;
		}
		else{
			return valorSem;
		}
		}


	}
	else{
		return V;
	}

	return 0;

}*/

/*AAAAAAAAAAAAAstruct Item
{
    float weight;
    float value;
};
  
struct Node
{
    // profit --> Profit of nodes on path from root to this
    //            node (including this node)
    // bound ---> Upper bound of maximum profit in subtree
    //            of this node/
    int level;
    float weight, profit, bound;
};
  
// Comparison function to sort Item according to
// val/weight ratio
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
  
// Returns bound of profit in subtree rooted with u. arr
// This function mainly uses Greedy solution to find
// an upper bound on maximum profit.
int bound(Node u, int n, int W, vector<pair<float,float>> itens)
{
    // if weight overcomes the knapsack capacity, return
    // 0 as expected bound
    if (u.weight >= W)
        return 0;
  
    // initialize bound on profit by current profit
    float profit_bound = u.profit;
  
    // start including items from index 1 more to current
    // item index
    int j = u.level + 1;
    float totweight = u.weight;
  
    // checking index condition and knapsack capacity
    // condition
    while ((j < n) && (totweight + itens[j].second <= W))
    {
        totweight    += itens[j].second;
        profit_bound += itens[j].first; 
        j++;
    }
  
    // If k is not n, include last item partially for
    // upper bound on profit
    if (j < n)
        profit_bound += (W - totweight) * itens[j].first / itens[j].second;
  
    return profit_bound;
}BBBBBBB*/
  
// Returns maximum profit we can get with capacity W ACHHO QUE TEM Q SER FLOAT
float ProblemaMochila:: knapsack(float W, int n){

    // sorting Item on basis of value per unit
    // weight.
    	//sort(arr, arr + n, cmp);
  
    // make a queue for traversing the node

    Auxiliares aux;

    queue<No> Q;
    No u, v;
  
    // dummy node at starting
    u.nivel = -1;
    u.profit = u.peso = 0;
    Q.push(u);
  
    // One by one extract an item from decision tree
    // compute profit of all children of extracted item
    // and keep saving maxProfit
    float maxProfit = 0;
    while (!Q.empty())
    {
        // Dequeue a node
        u = Q.front();
        Q.pop();
  
        // If it is starting node, assign level 0
        if (u.nivel == -1)
            v.nivel = 0;
  
        // If there is nothing on next level
        if (u.nivel == n-1)
            continue;
  
        // Else if not last node, then increment level,
        // and compute profit of children nodes.
        v.nivel = u.nivel + 1;
  
        // Taking current level's item add current
        // level's weight and value to node u's
        // weight and value
        v.peso = u.peso + this->paresValorPeso[v.nivel].second;
        v.profit = u.profit + this->paresValorPeso[v.nivel].first;
  
        // If cumulated weight is less than W and
        // profit is greater than previous profit,
        // update maxprofit
        if (v.peso <= W && v.profit > maxProfit)
            maxProfit = v.profit;
  
        // Get the upper bound on profit to decide
        // whether to add v to Q or not.
        v.bound = aux.bound(v, n, W, this->paresValorPeso);
  
        // If bound value is greater than profit,
        // then only push into queue for further
        // consideration arr
        if (v.bound > maxProfit)
            Q.push(v);
  
        // Do the same thing,  but Without taking
        // the item in knapsack
        v.peso = u.peso;
        v.profit = u.profit;
        v.bound = aux.bound(v, n, W, this->paresValorPeso);
        if (v.bound > maxProfit)
            Q.push(v);
    }
  
    return maxProfit;
}
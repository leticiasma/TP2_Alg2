#include "Auxiliares.hpp"

bool Auxiliares::compValorRelativoPar(const pair<float,float> &a, const pair<float,float> &b){
    return (a.first/a.second > b.first/b.second);
}

/*bool AcompValorRelativoItem(Item a, Item b){
    return (float)a.valor/a.peso > (float)b.valor/b.peso;
}*/

float Auxiliares::bound(No u, int n, int W, vector<pair<float,float>> itens){

    if (u.peso > W){
    	return 0;
    } //>= pq?
  
    // initialize bound on profit by current profit
    float profitBound = u.profit;
  
    int j = u.nivel + 1;
    float totPeso = u.peso;
  
    while ((j < n) && (totPeso + itens[j].second <= W)){
        totPeso += itens[j].second;
        profitBound += itens[j].first; 
        j++;
    }
  
    // If k is not n, include last item partially for
    // upper bound on profit
    if (j < n)
        profitBound += (W - totPeso) * itens[j].first / itens[j].second;
  
    return profitBound;
}

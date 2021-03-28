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

float ProblemaMochila::solBranchAndBound(unsigned int item, float W, float V, float melhor){

	if (item < this->paresValorPeso.size()){

		float valorCom = -1;
		float valorSem = -1;
		float novoW = W - this->paresValorPeso[item].second;
		float valorRelativoProx = this->paresValorPeso[item+1].first/this->paresValorPeso[item+1].second;

		float estimativaCom = (V+this->paresValorPeso[item].first) + novoW*valorRelativoProx;
		float estimativaSem = V + W*valorRelativoProx;

		if (estimativaCom > estimativaSem){
			if (novoW >= 0){
				valorCom = this->solBacktracking(item+1, novoW, V+this->paresValorPeso[item].first);
			}
		valorSem = this->solBacktracking(item+1, W, V);

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

}
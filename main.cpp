#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "ProblemaMochila.hpp"
#include "Auxiliares.hpp"

using namespace std;

int main(int argc, const char* argv[]) {


    if (argc > 1){
        ofstream saidaBackt = ofstream("resultBacktracking.csv", ios::app);        
        ofstream saidaBranchB = ofstream("resultBranchBound.csv", ios::app);

        if (saidaBackt.is_open() && saidaBranchB.is_open()){

            for (int i=1; i<argc; i++){

                

                ifstream entrada = ifstream(argv[i]);

                if (entrada.is_open()){
                    ProblemaMochila p;

                    int n = -1;
                    float WMax = -1;
                    float vi = -1;
                    float wi = -1;

                    entrada>>n;
                    entrada>>WMax;

                    p.numItens = n;
                    p.pesoMax = WMax;

                    for (int i=0; i<n; i++){
                        entrada>>vi;
                        entrada>>wi;

                        p.paresValorPeso.push_back (make_pair (vi, wi));
                    }

                    Auxiliares aux;

                    sort(p.paresValorPeso.begin(), p.paresValorPeso.end(), aux.compValorRelativoPar);

                    auto start = chrono::high_resolution_clock::now();
                    float solucao = p.solBacktracking(0, p.pesoMax, 0.0);
                    auto stop = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
                    saidaBackt<<argv[i]<<";Leticia da Silva Macedo Alves;"<<duration.count()<<";"<<solucao<<endl;
                   
                    start = chrono::high_resolution_clock::now();
                    //float lucroRaiz = p.pesoMax * (p.paresValorPeso[0].first/p.paresValorPeso[0].second);
                    //solucao = p.solBranchAndBound(0, p.pesoMax, 0.0);//, p.fila, 0.0);
                    solucao = p.knapsack(p.pesoMax, p.numItens);
                    stop = chrono::high_resolution_clock::now();
                    duration = chrono::duration_cast<chrono::microseconds>(stop-start);
                    saidaBranchB<<argv[i]<<";Leticia da Silva Macedo Alves;"<<duration.count()<<";"<<solucao<<endl;

                    entrada.close();
                }
                else{
                    cout<<"Nao foi possivel abrir o arquivo "<<argv[i]<<"."<<endl;
                } 
            }
        
        saidaBackt.close();
        saidaBranchB.close();
        }
        else{
            cout<<"Nao foi possivel abrir os arquivos de saida."<<endl;
        }

    }
    else{
        cout<<"Nenhum arquivo de entrada informado!"<<endl;
        exit(1);
    }
    

    return 0;
}
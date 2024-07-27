#include <iostream>
#include <cstring>
#include <vector>
#include "Cinema.hpp"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


void imprime(vector<vector<string>> dados){
    for(int i=1; i<dados[i].size(); i++){
        for(int j=0; j<dados.size(); j++)
            cout << dados[i][0] << " ";
    }   
    cout << endl;
} 



void ordenaInsertion(vector<vector<string>> dados){
    for(int i=0; i<dados.size(); i++){
        int j = i-1;
        string aux = dados[i][1];
        while(j >= 0 && aux < dados[j][1]){
            dados[j+1][1] = dados[j][1];
            j--;
        }
        dados[j+1][1] = aux;
    }
    //imprime(dados);
}


int main(){
    ifstream arquivo("./Database/teste.txt");
    string linha;

    vector<vector<string>> dados;

    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            stringstream ss(linha);
            string item;
            vector<string> vetor;

            while(getline(ss, item, ',')){
                vetor.push_back(item);
            }
            dados.push_back(vetor);

        }

        cout << dados[0].size() << endl;

        //impressão da dados
        for(const auto& linha : dados){
            for(const auto& elemento : linha){
                cout << elemento << " ";
            }
            cout << endl;
        }

        ordenaInsertion(dados);

        for(const auto& linha : dados){
            for(const auto& elemento : linha){
                cout << elemento << " ";
            }
            cout << endl;
        }


    }

    return 0;
}   

/*

//impressão da dados
        for(const auto& linha : dados){
            for(const auto& elemento : linha){
                cout << elemento << " ";
            }
            cout << endl;
        }
        
        //imprime coluna 0
        for(const auto& linha : dados){
            if(0 < linha.size()){
                cout << linha[0] << endl;
            }
        }

        vector<vector<string>> matriz2;
        vector<int> colunas = {0, 5, 6, 7, 8};
        vector<string> cabecalho = {"Cinema_ID", "Filme_1", "Filme_2", "Filme_3", "Filme_4"};
        matriz2.push_back(cabecalho);

        for(const auto& linha : matriz){
            vector<string> novaLinha;
            for (int i : colunas) {
                if (i < linha.size()) {
                    novaLinha.push_back(linha[i]);
                }
            }
            matriz2.push_back(novaLinha);
        }

        matriz2.erase(matriz2.begin() + 1);
        
        for(const auto& linha : matriz2){
            for(const auto& elemento : linha){
                cout << elemento << " ";
            }
            cout << endl;
        }


*/
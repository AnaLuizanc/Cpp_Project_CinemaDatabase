#include <iostream>
#include <cstring>
#include <vector>
#include "Cinema.hpp"
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

int main(){
    ifstream arquivo("./Database/teste.txt");
    string linha;

    vector<vector<string>>matriz;

    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            stringstream ss(linha);
            string item;
            vector<string> vetor;

            while(getline(ss, item, ',')){
                vetor.push_back(item);
            }
            matriz.push_back(vetor);

        }
        
        //impressão da matriz
        for(const auto& linha : matriz){
            for(const auto& elemento : linha){
                cout << elemento << " ";
            }
            cout << endl;
        }

        //imprimir SilverScreen Cinema
        cout << matriz[3].at(1) << endl;
        
        //imprime coluna 0
        for(const auto& linha : matriz){
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
    }

    return 0;
}   
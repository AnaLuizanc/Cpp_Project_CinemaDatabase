#include <iostream>
#include <cstring>
#include <vector>
#include "Cinema.hpp"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void imprime(vector<vector<string>> lista){
    cout << endl;
    cout << "Número de linhas: " << lista.size() << endl;
    cout << "Número de colunas: " << lista[0].size() << endl;
    cout << endl;
    for(const auto& linha : lista){
            for(const auto& elemento : linha){
                cout << elemento << " ";
            }
            cout << endl;
        }
    cout << endl;
}

void imprimeUmaLinha(vector<vector<string>> lista, int valorLinha){
    cout << endl;
    vector<string> linha = lista[valorLinha];
    
    for(const auto& elemento: linha)
        cout << elemento << " ";
}

void swapLine(vector<vector<string>>& lista, int i, int j){
    vector<string> aux = lista[i];
    lista[i] = lista[j];
    lista[j] = aux;
}



void selectionSort(vector<vector<string>>& lista, int opc){
    //1 ordena por nome
    //2 ordena por valor

    if(opc == 1){
        for(int i = 1; i < lista.size(); i++){
            string aux = lista[i][1];
            int j = i - 1;
            while(j >= 1 && lista[j][1] > aux){
                swapLine(lista, j + 1, j);

                j--;
            }
            lista[j + 1][1] = aux;
        }
    }
    else if(opc == 2){
        for(int i = 1; i < lista.size(); i++){
            float value = stof(lista[i][4]);
            string aux = lista[i][4];

            int j = i - 1;

            while(j >= 1 && stof(lista[j][4]) > value){
                swapLine(lista, j + 1, j);
                j--;
            }

            lista[j + 1][4] = aux;
        }
    }

    else if(opc == 3){
        for(int i = 1; i < lista.size(); i++){
            string aux = lista[i][5];

            int j = i - 1;

            while(j >= 1 && lista[j][1] == "movie"){
                swapLine(lista, j + 1, j);
                j--;
            }

            lista[j + 1][1] = aux;
        }
    }
   
}

bool isRepeated(vector<vector<string>>& lista, string valueToCompare){
    for(int i = 1; i < lista.size(); i++){
        if(lista[i][1] == valueToCompare){
            return true;
        }
    }
    return false;
}

void oneCinema(vector<vector<string>>& lista){
    vector<vector<string>> noRepeatedCinemas;
    noRepeatedCinemas.push_back(lista[0]);

    for(int i = 1; i < lista.size(); i++){
        if(isRepeated(noRepeatedCinemas, lista[i][1]) == false){
            noRepeatedCinemas.push_back(lista[i]);
        }
    }

    imprime(noRepeatedCinemas);
}

void printJustMovies(vector<vector<string>> lista){
    vector<vector<string>> justMovies;
    justMovies.push_back(lista[0]);
    justMovies.push_back(lista[1]);
    cout << "AAAAAA";
    for(int i = 1; i < lista.size(); i++){
        if(lista[i][1] == "movie"){
            //justMovies.push_back(lista[i]);
            imprimeUmaLinha(lista, i);
        }
    }

    //imprime(justMovies);


}

int main(){
    ifstream arquivoCinema("./Database/cinemas.txt");
    ifstream arquivoFilme("./Database/movies.txt");
    string linha;

    vector<vector<string>>matrizCinema;
    vector<vector<string>>matrizFilme;

    if(arquivoCinema.is_open() && arquivoFilme.is_open()){
        while(getline(arquivoCinema, linha)){
            stringstream ss(linha);
            string item;
            vector<string> vetor;

            while(getline(ss, item, ',')){
                vetor.push_back(item);
            }
            matrizCinema.push_back(vetor);

        }

        while(getline(arquivoFilme, linha)){
            stringstream ss(linha);
            string item;
            vector<string> vetor;

            while(getline(ss, item, '\t')){
                vetor.push_back(item);
            }
            matrizFilme.push_back(vetor);

        }
        imprime(matrizFilme);


        
        //impressão da matriz
        /*for(const auto& linha : matriz){
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
        }*/
    }

*/
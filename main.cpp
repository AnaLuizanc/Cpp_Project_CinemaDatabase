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
    
    vector<vector<string>> matriz2;

    for(int i=0; i<5; i++){
        matriz2.push_back(matriz[i]);
        //strcpy(matriz[i][1], "Filme 1");
        //str
    }
    
    for(int i=0; i< 5; i++){
        for(int j=0; j<4; j++){
            cout << matriz2[i][j]; 
        }
        cout << endl;
    }


    

    }

    return 0;
}   
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
//#include <stack>

using namespace std;

#include "Cinema.hpp"
#include "Functions.cpp"


int main(){
    auto startRead = chrono::high_resolution_clock::now();
    ifstream arquivoCinema("cinemas.txt");
    ifstream arquivoMovies("movies.txt");
 
    vector <Cinema> C;
    vector <Movie> M;

    vector<string> linhaCinema;
    vector<string> linhaMovies;
    
    string linha;

    if(arquivoCinema.is_open() && arquivoMovies.is_open()){
        while(getline(arquivoCinema, linha)){
            linhaCinema.erase(linhaCinema.begin(), linhaCinema.end());
            stringstream ss(linha);
            string item;
            
            while(getline(ss, item, ','))
                linhaCinema.push_back(item);
            
            insertCinema(linhaCinema, C);
        }
        while(getline(arquivoMovies, linha)){
            linhaMovies.erase(linhaMovies.begin(), linhaMovies.end());
            stringstream ss(linha);
            string item;
            
            while(getline(ss, item, '\t'))
                linhaMovies.push_back(item);

            insertMovie(linhaMovies, M);
        }
    }

    auto endRead = chrono::high_resolution_clock::now();
    const chrono::duration<double> duration1 = endRead - startRead;
    cout << "Tempo de leitura dos arquivos de dados: " << duration1.count() << "s" << endl; 

    auto startSort = chrono::high_resolution_clock::now();
    
    //mergeSort(M, 0, M.size()-1);
    heapSort(M, M.size());
    
    auto endSort = chrono::high_resolution_clock::now();
    const chrono::duration<double> duration2 = endSort - startSort;
    cout << "Tempo de ordenação do arquivo de filmes: " << duration2.count() << "s" << endl;
    
    menu(M, C);

    return 0;
}
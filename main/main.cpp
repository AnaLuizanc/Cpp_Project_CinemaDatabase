#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <stack>

using namespace std;

#include "./headers/Cinema.hpp"
#include "Functions.cpp"


int main(){
    auto start = chrono::high_resolution_clock::now();
    ifstream arquivoCinema("../Database/cinemas.txt");
    ifstream arquivoMovies("../Database/movies.txt");
 
    vector <Cinema> C;

    Cinema titulo;

    vector<string> vetMovies;

    vector <Movie> M;

    vector<string> linhaCinema;
    vector<string> linhaMovies;
    
    string linha;


    if(arquivoCinema.is_open() && arquivoMovies.is_open()){
        while(getline(arquivoCinema, linha)){
            linhaCinema.erase(linhaCinema.begin(), linhaCinema.end());
            stringstream ss(linha);
            string item;
            while(getline(ss, item, ',')){
                linhaCinema.push_back(item);
            }

            insertCinema(linhaCinema, C);

            
        }
        while(getline(arquivoMovies, linha)){
            linhaMovies.erase(linhaMovies.begin(), linhaMovies.end());
            stringstream ss(linha);
            string item;
            while(getline(ss, item, '\t')){
                linhaMovies.push_back(item);
            }
            insertMovie(linhaMovies, M);
        }
    }

    mergeSort(M, 0, M.size()-1);

    auto end = chrono::high_resolution_clock::now();
    const chrono::duration<double> duration = end - start;
    cout << duration.count() << "s" << endl; 

    menu(M, C);

    return 0;
}
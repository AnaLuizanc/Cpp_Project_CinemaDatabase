#include <iostream>
#include <cstring>
#include <vector>
#include <string>

#include "./headers/Cinema.hpp"
#include "Functions.cpp"

using namespace std;

int main(){
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

    for(int i = 0; i < C.size(); i++)
        imprimeCinema(C[i], M);
}
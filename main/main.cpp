#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

#include "./headers/Cinema.hpp"
#include "Functions.cpp"

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

    //for(int i = 0; i < C.size(); i++)
        //imprimeCinema(C[i], M);

    //teste searchByYear OK
    //searchByYear(M, "1990");

    //teste searchByIsAdult OK
    //searchByIsAdult(M, "1");

    //teste searchByRangeYears OK
    //searchByRangeYears(M, 1990, 2000);

    //teste searchByRuntimeMinutes OK
    //searchByRuntimeMinutes(M,3,10);

    //teste searchByTitleType OK
    //searchByTitleType(M, "video,short");

    //teste searchByGenres OK
    //searchByGenres(M, "Music");

    //imprimeMovie(M[6]);

    return 0;
}
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <stack>

using namespace std;

#include "./headers/Cinema.hpp"
#include "Functions.cpp"

void filterApplier(string key, string values, vector<Movie>& m){
    if(key == "titleType")
        m = searchByTitleType(m, values);
    else if(key == "year")
        m = searchByYear(m, values);
}

vector<Movie> splitString(const string& input, vector<Movie> m){
    stringstream ss(input);
    string token;
    string key;
    string values;

    vector<Movie> filtered = m;
    

    while (getline(ss, token, '(')) {
        key = token;
        getline(ss, token, ')');

        stringstream value_ss(token);
        string value;
        while (getline(value_ss, value)) {
            values = value;
        }

        filterApplier(key, values, filtered);
        key.clear();
        values.clear();
        
    }

    return filtered;
}


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

    string query;

    cout << "Insira a query: ";
    cin >> query;

    cout << endl;

    vector<Movie> newFiltered = splitString(query, M);

    for(int i = 0; i < newFiltered.size(); i++)
        imprimeMovie(newFiltered[i]);

   
    return 0;
}
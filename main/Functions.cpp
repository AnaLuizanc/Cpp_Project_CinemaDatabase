#include "./headers/Movie.hpp"
#include "./headers/Cinema.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

vector<string> foo(string value){
    string linha = value;
    stringstream ss(linha);
    string item;
    vector<string> values;

    while(getline(ss, item, ','))
        values.push_back(item);

    return values;
}

//Realiza Selection Sort do vetor Cinema.

void selectionSort(vector<Cinema>& c){
    for(int i = 1; i < c.size(); i++){
        Cinema aux = c[i];
        int j = i - 1;

        while(j >= 0 && c[j].getName() > aux.getName()){
            aux = c[j+1];
            c[j + 1] = c[j];
            c[j] = aux;
            j--;
        }
        c[j + 1] = aux;
    }
}

//Função auxiliar do Merge Sort.

void merge(vector<Movie>& m, int left, int mid, int right){
    vector<Movie> aux(right-left+1);
    for(int i = left, k=0; i <= right; ++i, ++k)
        aux[k] = m[i];
    
    int i = 0, j = mid-left+1, k = left;

    while(i <= mid-left && j <= right-left){
        if(aux[i].getTconst() <= aux[j].getTconst())
            m[k++] = aux[i++];
        else
            m[k++] = aux[j++];
    }

    while(i <= mid-left)
        m[k++] = aux[i++];
}

//Realiza Merge Sort no vetor de Movies.

void mergeSort(vector<Movie>& m, int left, int right){
    if(left >= right)
        return;
    
    int mid = (left+right)/2;

    mergeSort(m, left, mid);
    mergeSort(m, mid+1, right);
    merge(m, left, mid, right);
}

//Realiza Busca Binária no vetor de Movies.

int binarySearch(vector<Movie>& m, string elemento){
    int inicio = 0;
    int fim = m.size() - 1;

    int anterior;

    while(inicio <= fim){
        int meio = inicio + (fim-inicio) / 2;
        if(meio == 0)
            break;
        if(m[meio].getTconst() == elemento){
            return meio;

        }
        else if(m[meio].getTconst() < elemento){
            inicio = meio+1;
            anterior = meio;
        }
        else{
            fim = meio-1;
            anterior = meio;
        }
    }   

    if(m[anterior].getTconst() < elemento)
        return anterior + 1;
    else
        return anterior;
}

//Realiza inserção de uma Vetor contendo dados de um filme no vetor de Movies.

void insertMovie(vector<string> coluna, vector<Movie>& Movies){
    Movie novo;

    novo.setTconst(coluna[0]);
    novo.setTitleType(coluna[1]);
    novo.setPrimaryTitle(coluna[2]);
    novo.setOriginalTitle(coluna[3]);
    novo.setIsAdult(coluna[4]);
    novo.setStartYear(coluna[5]);
    novo.setEndYear(coluna[6]);
    novo.setRuntimeMinutes(coluna[7]);

    vector<string> genres = foo(coluna[8]);
    
    novo.setGenres(genres);

    Movies.push_back(novo);
}

//Realiza impressão de um filme específico.

void imprimeMovie(Movie a){
    cout << a.getTconst() << " | ";
    cout << a.getTitleType() << " | ";
    cout << a.getPrimaryTitle() << " | ";
    cout << a.getOriginalTitle() << " | ";
    cout << a.getIsAdult() << " | ";
    cout << a.getStartYear() << " | ";
    cout << a.getEndYear() << " | ";
    cout << a.getRuntimeMinutes() << " | ";
    vector<string> genres = a.getGenres();
    for(int i = 0; i < genres.size(); i++)
        cout << genres[i] << " ";
    cout << endl;
}

//Realiza a busca por tipo de filme.

vector<Movie> searchByTitleType(vector<Movie> M, string value){
    vector<string> titleType = foo(value);
    vector<Movie> filtered;

    for(int i = 1; i < M.size(); i++){
        for(int j = 0; j<titleType.size(); j++){
            if(M[i].getTitleType() == titleType[j])
                filtered.push_back(M[i]);
        }
    }
    return filtered;
}

//Realiza a busca de filmes pelo gênero.

//&
//|

vector<Movie> searchByGenres(vector<Movie> M, string value){
    vector<string> genres = foo(value);
    vector<Movie> filtered;

    for(int i=1; i<M.size(); i++){
        vector<string> genresMovie = M[i].getGenres();
        bool equal = false;
        for(int j=0; j<genres.size(); j++){
            for(int k = 0; k < genresMovie.size(); k++){
                if(genres[j] == genresMovie[k])
                    equal = true;
            }
        }
        if(equal)
            filtered.push_back(M[i]);
    }
    return filtered;
}

//Realiza a busca de filmes adultos ou não.

vector<Movie> searchByIsAdult(vector<Movie> M, string isAdult){
    vector<Movie> filtered;
    for(int i = 1; i < M.size(); i++){
        if(isAdult == M[i].getIsAdult())
            filtered.push_back(M[i]);
    }
    return filtered;
}

//Realiza a busca por duração do filme.

vector<Movie> searchByRuntimeMinutes(vector<Movie> M, string value){
    vector<Movie> filtered;
    vector<string> values = foo(value);
    int startValue = stoi(values[0]);
    int endValue = stoi(values[1]);
    for(int i = 1; i < M.size(); i++){
        if(M[i].getRuntimeMinutes() != "\\N"){
            int runtime = stoi(M[i].getRuntimeMinutes());
            if(runtime >= startValue && runtime <= endValue)
                filtered.push_back(M[i]);
        }
    }
    return filtered;
}

//Realiza a busca por ano do filme.

vector<Movie> searchByYear(vector<Movie> M, string value){
    vector<Movie> filtered;
    for(int i=1; i < M.size(); i++){
        if(M[i].getStartYear() == value || M[i].getEndYear() == value)
            filtered.push_back(M[i]);
    }
    return filtered;
}

//Realiza a busca de filmes num determinado escopo de anos.

vector<Movie> searchByRangeYears(vector<Movie> M, string value){
    vector<Movie> filtered;
    vector<string> values = foo(value);
    int startValue = stoi(values[0]);
    int endValue = stoi(values[1]);
    for(int i=1; i < M.size(); i++){
        if(M[i].getEndYear() != "\\N"){
            int startYear = stoi(M[i].getStartYear());
            int endYear = stoi(M[i].getEndYear());
            if(startValue <= startYear && endValue >= endYear)
                filtered.push_back(M[i]);
        }
    }
    return filtered;
}

//Realiza inserção d eum vetor contendo um Cinema no vetor de Cinemas.

void insertCinema(vector<string> coluna, vector<Cinema>& Cinemas){
    Cinema novo;
    novo.setCinemaID(coluna[0]);
    novo.setName(coluna[1]);
    novo.setXCoordinate(coluna[2]);
    novo.setYCoordinate(coluna[3]);
    novo.setTicketPrice(coluna[4]);
    int contador = 5;
    vector<string> movies;
    while(contador < coluna.size())
        movies.push_back(coluna[contador++]);
    novo.setMovies(movies);
    Cinemas.push_back(novo);
}

//Imprime os respectivos títulos disponíveis em um determinado Cinema.

void showMoviesName(Cinema c, vector<Movie>& m){
    mergeSort(m, 0, m.size()-1);
    vector<string> tconst = c.getMovies();
    for(int i=0; i < tconst.size(); i++){
        int indice = binarySearch(m,tconst[i]);
        if(indice != -1)
            cout << m[indice].getPrimaryTitle() << endl;
    }
    cout << endl;    
}

//Imprime os dados de um determinado cinema.

void imprimeCinema(Cinema a, vector<Movie>& m){
    cout << a.getCinemaID() << " ";
    cout << a.getName() << " ";
    cout << a.getXCoordinate() << " ";
    cout << a.getYCoordinate() << " ";
    cout << a.getTicketPrice() << " ";
    vector<string> movies = a.getMovies();
    for(int i=0; i < movies.size(); i++)
        cout << movies[i] << " ";
    cout << endl;
    //showMoviesName(a,m);
}

//Realiza busca de cinemas que possuem filmes do(s) tipo(s) (titleType) especificado

void searchCinemaByTitleType(vector<Cinema> C, vector<Movie> M, string value){
    vector<string> titlesType = foo(value);

    for(int i=1; i<C.size(); i++){
        vector<string> tconst = C[i].getMovies();
        for(int t = 0; t<tconst.size(); t++){
            int index = binarySearch(M, tconst[t]);
            for(int j = 0; j<titlesType.size(); j++){
                if(M[index].getTitleType() == titlesType[j]){
                    imprimeCinema(C[i],M);
                }
            }
        }
    }
}

//Realiza busca de cinemas que possuem filmes do ano especificado.

void searchCinemaByYearMovie(vector<Cinema> C, vector<Movie> M, string year){
    for(int i=1; i<C.size(); i++){
        vector<string> tconst = C[i].getMovies();
        for(int t = 0; t<tconst.size(); t++){
            int index = binarySearch(M, tconst[t]);
            if(M[index].getStartYear() == year || M[index].getEndYear() == year)
                imprimeCinema(C[i],M);
        }
    }
}

//Realiza busca de cinemas que possuem filmes do período de anos especifcado.

void searchCinemaByRangeYearsMovie(vector<Cinema> C, vector<Movie> M, string value){
    vector<string> values = foo(value);
    int startValue = stoi(values[0]);
    int endValue = stoi(values[1]);
    for(int i=1; i<C.size(); i++){
        vector<string> tconst = C[i].getMovies();
        for(int t = 0; t<tconst.size(); t++){
            int index = binarySearch(M, tconst[t]);
            if(M[index].getEndYear() != "\\N"){
                int startYear = stoi(M[index].getStartYear());
                int endYear = stoi(M[index].getEndYear());
                if(startValue <= startYear && endValue >= endYear){
                        imprimeCinema(C[i],M);
                        imprimeMovie(M[index]);
                }
            }
        }
    }
}

//Realiza busca de cinemas que possuem filmes dentro do limite especificado.

void searchCinemaByRuntimeMinutesMovie(vector<Cinema> C, vector<Movie> M, int startValue, int endValue){
    for(int i=1; i<C.size(); i++){
        vector<string> tconst = C[i].getMovies();
        for(int t = 0; t<tconst.size(); t++){
            int index = binarySearch(M, tconst[t]);
            if(M[index].getRuntimeMinutes() != "\\N"){
                int runtime = stoi(M[index].getRuntimeMinutes());
                if(runtime >= startValue && runtime <= endValue)
                    imprimeCinema(C[i],M);
            }
        }
    }
}

//Realiza busca de cinemas que possuem filmes com o(s) gênero(s) especificado(s).

void searchCinemaByGenresMovie(vector<Cinema> C, vector<Movie> M, string value){
    vector<string> genres = foo(value);

    for(int i=1; i<C.size(); i++){
        vector<string> tconst = C[i].getMovies();
        for(int t = 0; t<tconst.size(); t++){
            int index = binarySearch(M, tconst[t]);
            if(M[index].getGenres() == genres)
                imprimeCinema(C[i],M);
        }
    }
}

//Realiza busca de cinemas dentro da distância máxima solicitada pelo usuário.

void searchByDistance(vector<Cinema> C, vector<Movie> M, double xAxis, double yAxis, double maxDistance){
    for(int i=1; i<C.size(); i++){
        double x = stod(C[i].getXCoordinate());
        double y = stod(C[i].getYCoordinate());
        double distance = sqrt(pow(x - xAxis, 2.0) + pow(y - yAxis, 2.0));
        if(distance <= maxDistance)
            imprimeCinema(C[i], M);
    }
}

void filterApplier(string key, string values, vector<Movie>& m){
    if(key == "TitleType")
        m = searchByTitleType(m, values);
    else if(key == "Year")
        m = searchByYear(m, values);
    else if(key == "RangeYears")
        m = searchByRangeYears(m, values);
    else if(key == "Minutes")
        m = searchByRuntimeMinutes(m, values);
    else if(key == "Genres")
        m = searchByGenres(m, values);
    else if(key == "Adult")
        m = searchByIsAdult(m, values);
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
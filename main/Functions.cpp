#include "./headers/Movie.hpp"
#include "./headers/Cinema.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>
#include <chrono>

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

void heapify(vector<Movie>& M, int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && M[left].getTconst() > M[largest].getTconst())
        largest = left;

    if(right < n && M[right].getTconst() > M[largest].getTconst())
        largest = right;

    if(largest != i){
        swap(M[i], M[largest]);
        heapify(M,n,largest);
    }
}

void heapSort(vector<Movie>& M, int n){
    for(int i = n/2 - 1; i>=0; i--)
        heapify(M, n, i);

    for(int i = n-1; i>0; i--){
        swap(M[0], M[i]);
        heapify(M, i, 0);
    }
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

bool collisionVerifier(vector<string> inserted, string value){
    bool result = false;
    for(int i = 0; i < inserted.size(); i++)
        if(value == inserted[i])
            result = true;
    return result;
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

vector<Movie> searchByGenresAnd(vector<Movie> M, string value){
    vector<string> genres = foo(value);
    vector<Movie> filtered;

    for(int i=1; i<M.size(); i++){
        vector<string> genresMovie = M[i].getGenres();
        if(genres.size() == genresMovie.size()){
            bool equal = true;
            for(int j=0; j<genresMovie.size(); j++){
                if(genres[j] != genresMovie[j])
                    equal = false;
            }
            if(equal)
                filtered.push_back(M[i]);
        }
    }
    return filtered;
}

vector<Movie> searchByGenresOr(vector<Movie> M, string value){
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

//Realiza inserção de um vetor contendo um Cinema no vetor de Cinemas.

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
    vector<string> tconst = c.getMovies();
    for(int i=0; i < tconst.size(); i++){
        int indice = binarySearch(m,tconst[i]);
        if(indice != -1)
            imprimeMovie(m[indice]);
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
    showMoviesName(a,m);
}

//Realiza busca de cinemas que possuem filmes do(s) tipo(s) (titleType) especificado.

vector<Cinema> searchCinemaByTitleType(vector<Cinema> C, vector<Movie> M, string value){
    vector<string> titlesType = foo(value);
    vector<string> inserted;
    vector<Cinema> filtered;
    for(int i=1; i<C.size(); i++){
        vector<string> tconst = C[i].getMovies();
        for(int t = 0; t<tconst.size(); t++){
            int index = binarySearch(M, tconst[t]);
            for(int j = 0; j<titlesType.size(); j++){
                if(M[index].getTitleType() == titlesType[j] && !collisionVerifier(inserted, C[i].getCinemaID())){
                    filtered.push_back(C[i]);
                    inserted.push_back(C[i].getCinemaID());
                }
            }
        }
       
    }
    return filtered;
}

//Realiza busca de cinemas que possuem filmes do ano especificado.

vector<Cinema> searchCinemaByYearMovie(vector<Cinema> C, vector<Movie> M, string year){
    vector<Cinema> filtered;
    vector<string> inserted;
    for(int i=1; i<C.size(); i++){
        vector<string> tconst = C[i].getMovies();  
        for(int t = 0; t<tconst.size(); t++){
            int index = binarySearch(M, tconst[t]);
            if((M[index].getStartYear() == year || M[index].getEndYear() == year) && !collisionVerifier(inserted, C[i].getCinemaID())){
                filtered.push_back(C[i]);
                inserted.push_back(C[i].getCinemaID());
            }       
        }
    }
    return filtered;
}

//Realiza busca de cinemas que possuem filmes do período de anos especifcado.

vector<Cinema> searchCinemaByRangeYearsMovie(vector<Cinema> C, vector<Movie> M, string value){
    vector<string> values = foo(value);
    vector<Cinema> filtered;
    vector<string> inserted;
    int startValue = stoi(values[0]);
    int endValue = stoi(values[1]);
    for(int i=1; i<C.size(); i++){
        vector<string> tconst = C[i].getMovies();
        for(int t = 0; t<tconst.size(); t++){
            int index = binarySearch(M, tconst[t]);
            if(M[index].getEndYear() != "\\N"){
                int startYear = stoi(M[index].getStartYear());
                int endYear = stoi(M[index].getEndYear());
                if(startValue <= startYear && endValue >= endYear && !collisionVerifier(inserted, C[i].getCinemaID())){
                    filtered.push_back(C[i]);
                    inserted.push_back(C[i].getCinemaID());
                }
            }
        }
    }
    return filtered;
}

//Realiza busca de cinemas que possuem filmes dentro do limite especificado.

vector<Cinema> searchCinemaByRuntimeMinutesMovie(vector<Cinema> C, vector<Movie> M, string value){
    vector<Cinema> filtered;
    vector<string> inserted;
    vector<string> values = foo(value);

    int startValue = stoi(values[0]);
    int endValue = stoi(values[1]);

    for(int i=1; i<C.size(); i++){
        vector<string> tconst = C[i].getMovies();
        for(int t = 0; t<tconst.size(); t++){
            int index = binarySearch(M, tconst[t]);
            if(M[index].getRuntimeMinutes() != "\\N"){
                int runtime = stoi(M[index].getRuntimeMinutes());
                if(runtime >= startValue && runtime <= endValue && !collisionVerifier(inserted, C[i].getCinemaID())){
                    filtered.push_back(C[i]);
                    inserted.push_back(C[i].getCinemaID());
                }
            }
        }
    }
    return filtered;
}

//Realiza busca de cinemas que possuem filmes com o(s) gênero(s) especificado(s).

vector<Cinema> searchCinemaByGenresAndMovie(vector<Cinema> C, vector<Movie> M, string value){ // &
    vector<string> genres = foo(value);
    vector<Cinema> filtered;
    vector<string> inserted;
    for(int i=1; i<C.size(); i++){
        vector<string> tconst = C[i].getMovies();
        for(int t = 0; t<tconst.size(); t++){
            int index = binarySearch(M, tconst[t]);
            if(M[index].getGenres() == genres && !collisionVerifier(inserted, C[i].getCinemaID())){
                filtered.push_back(C[i]);
                inserted.push_back(C[i].getCinemaID());
            }
        }
    }
    return filtered;
}

vector<Cinema> searchCinemaByGenresOrMovie(vector<Cinema> C, vector<Movie> M, string value){ // |
    vector<string> genres = foo(value);
    vector<Cinema> filtered;
    vector<string> inserted;
    for(int i=1; i<C.size(); i++){
        vector<string> tconst = C[i].getMovies();
        for(int t = 0; t<tconst.size(); t++){
            int index = binarySearch(M, tconst[t]);
            vector<string> genresMovie = M[index].getGenres();
            bool equal = false;
            for(int j=0; j<genresMovie.size(); j++){
                for(int k=0; k < genres.size(); k++){
                    if(genres[k] == genresMovie[j])
                        equal = true;
                }
            }
            if(equal && !collisionVerifier(inserted, C[i].getCinemaID())){
                filtered.push_back(C[i]);
                inserted.push_back(C[i].getCinemaID());
            }
        }
    }
    return filtered;
}

//Realiza busca de cinemas dentro da distância máxima solicitada pelo usuário.

vector<Cinema> searchByDistance(vector<Cinema> C, vector<Movie> M, string value){
    vector<Cinema> filtered;
    vector<string> values = foo(value);
    double xAxis = stod(values[0]);
    double yAxis = stod(values[1]);
    double maxDistance = stod(values[2]);
    for(int i=1; i<C.size(); i++){
        double x = stod(C[i].getXCoordinate());
        double y = stod(C[i].getYCoordinate());
        double distance = sqrt(pow(x - xAxis, 2.0) + pow(y - yAxis, 2.0));
        if(distance <= maxDistance)
            filtered.push_back(C[i]);
    }
    return filtered;
}

//Realiza busca de cinemas com o limite de valor (ticketPrice) especificado.

vector<Cinema> searchByTicketPrice(vector<Cinema> C, string value){
    vector<Cinema> filtered;
    double maxPrice = stod(value);
    for(int i=1; i<C.size(); i++){
        double price = stod(C[i].getTicketPrice());
        if(price <= maxPrice)
            filtered.push_back(C[i]);
    }
    return filtered;
}

//Aplica filtros em Movies.

void filterApplierMovie(string key, string values, vector<Movie>& m){
    if(key == "TIPO" || key == "TYPE" || key == "TITLETYPE" || key == "TITLE")
        m = searchByTitleType(m, values);
    else if(key == "YEAR" || key == "ANO")
        m = searchByYear(m, values);
    else if(key == "RANGEYEARS")
        m = searchByRangeYears(m, values);
    else if(key == "MINUTES" || key == "TIME")
        m = searchByRuntimeMinutes(m, values);
    else if(key == "GENRESAND")
        m = searchByGenresAnd(m, values);
    else if(key == "GENRESOR"){
        m = searchByGenresOr(m, values);
    }
}

//

vector<Cinema> removeRepeated(vector<Cinema> c){
    vector<string>id;
    vector<Cinema> noRepeated;
    for(int i = 0; i < c.size(); i++){
        bool verifier = false;
        for(int j = 0; j < id.size(); j++)
            if(c[i].getCinemaID() == id[j])
                verifier = true;
        
        if(verifier == false)
            noRepeated.push_back(c[i]);
    }
    return noRepeated;
}

//Tranforma chave de estrada em CAIXA ALTA.

string toUpperCase(string value){
    string up;
    for(auto c : value)
        up += toupper(c);

    return up;
}

vector<Movie> splitStringMovie(const string& input, vector<Movie> m){
    stringstream ss(input);
    string token;
    string key;
    string values;

    vector<Movie> filtered = m;
    
    while (getline(ss, token, '(')) {
        key = token;
        key = toUpperCase(key);
        getline(ss, token, ')');

        stringstream value_ss(token);
        string value;
        while (getline(value_ss, value))
            values = value;

        filterApplierMovie(key, values, filtered);
        key.clear();
        values.clear();   
    }
    return filtered;
}

//Aplica filtros em Cinema.

void filterApplierCinema(string key, string values, vector<Movie> m, vector<Cinema>& c){
    if(key == "TIPO" || key == "TYPE" || key == "TITLETYPE" || key == "TITLE")
        c = searchCinemaByTitleType(c, m, values);
    else if(key == "ANO" || key == "YEAR")
        c = searchCinemaByYearMovie(c, m, values);
    else if(key == "RANGEYEARS")
        c = searchCinemaByRangeYearsMovie(c, m, values);
    else if(key == "TIME" || key == "MINUTES")
        c = searchCinemaByRuntimeMinutesMovie(c, m, values);
    else if(key == "GENRESAND")
        c = searchCinemaByGenresAndMovie(c, m, values);
    else if(key == "GENRESOR")
        c = searchCinemaByGenresOrMovie(c, m, values);
    else if(key == "DISTANCE" || key == "DISTANCIA")
        c = searchByDistance(c, m, values);
    else if(key == "PRICE" || key == "PRECO")
        c = searchByTicketPrice(c,values);
}

//

vector<Cinema> splitStringCinema(const string& input, vector<Movie> m, vector<Cinema> c){
    stringstream ss(input);
    string token;
    string key;
    string values;
    vector<Cinema> filtered = c;

    while(getline(ss, token, '(')){
        key = token;
        key = toUpperCase(key);
        getline(ss, token, ')');

        stringstream value_ss(token);
        string value;
        while(getline(value_ss, value))
            values = value;

        filterApplierCinema(key, values, m, filtered);
        key.clear();
        values.clear();

    }
    return filtered;
}

/*
vector<Cinema> splitStringCinemav2(const string& input, vector<Movie> m, vector<Cinema> c){
    stringstream ss(input);
    string token;
    string key;
    string values;

    vector<Cinema> filtered = c;

    while (ss >> token) {
        if (token == "tipo") {
            string item;
            while(getline(ss, item, '(')){
                getline(ss, item, ')');

                string value;
                stringstream value_ss(item);
                while(getline(value_ss, value))
                    values = value;   
                break;    
            }
            cout << token << " aa" << values << endl;
            filterApplierCinema(token, values, m, filtered);
            token.clear();
            values.clear();
        }
        else if(token == "ano"){
            string item;
            while(getline(ss, item, '(')){
                getline(ss, item, ')');

                string value;
                stringstream value_ss(item);
                while(getline(value_ss, value))
                    values = value;   
                break;    
            }
            filterApplierCinema(token, values, m, filtered);
            token.clear();
            values.clear();
        }
    }
    return filtered;
}

*/

void menu(vector <Movie> M, vector <Cinema> C){
    int opc;
    string query;
    do{
        cout << endl;
        cout << "1. Procurar por filmes." << endl;
        cout << "2. Procurar por cinemas." << endl << endl;
        cout << "0.Sair" <<  endl;
        cout << "Insira a opção: ";
        cin >> opc;
        cout << endl;
        
        switch(opc){
            case 1:
            {
                cout << "Insira a query: ";
                cin >> query;

                auto start = chrono::high_resolution_clock::now();

                vector<Movie> newFiltered = splitStringMovie(query, M);
                for(int i = 0; i < newFiltered.size(); i++)
                    imprimeMovie(newFiltered[i]);

                cout << endl;
                auto end = chrono::high_resolution_clock::now();
                const chrono::duration<double> duration = end - start;
                cout << "Tempo de filtragem: " << duration.count() << "s" << endl; 
                
                break;

            }
            case 2:
            {
                cout << "Insira a query: ";
                cin >> query;

                auto start = chrono::high_resolution_clock::now();

                //vector<Cinema> newFiltered = splitStringCinemav2(query, M, C);
                vector<Cinema> newFiltered = splitStringCinema(query, M, C);
                for(int i = 0; i < newFiltered.size(); i++)
                    imprimeCinema(newFiltered[i], M);

                auto end = chrono::high_resolution_clock::now();
                const chrono::duration<double> duration = end - start;
                cout << "Tempo de filtragem: " << duration.count() << "s" << endl; 
                break;
            }
        }
    }while(opc != 0);
    cout << "Programa encerrado!" << endl;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Movie{
    string tconst;
    string titleType;
    string primaryTitle;
    string originalTitle;
    string isAdult;
    string startYear;
    string endYear;
    string runtimeMinutes;
    vector<string> genres;


public:
        Movie(string tconst, string titleType, string primaryTitle, string originalTitle, string isAdult, string startYear, string endYear, string runtimeMinutes){
            this->tconst = tconst;
            this->titleType = titleType;
            this->primaryTitle = primaryTitle;
            this->originalTitle = originalTitle;
            this->isAdult = isAdult;
            this->endYear = endYear;
            this->startYear = startYear;
            this->runtimeMinutes = runtimeMinutes;
        }
        
        void setTconst(string tconst){
            this->tconst = tconst;
        }

        string getTconst(){
            return tconst;
        }

        void setTitleType(string titleType){
            this->titleType = titleType;
        }

        string getTitleType(){
            return titleType;
        }

        void setPrimaryTitle(string primaryTitle){
            this->primaryTitle = primaryTitle;
        }

        string getPrimaryTitle(){
            return primaryTitle;
        }

        void setOriginalTitle(string originalTitle){
            this->originalTitle = originalTitle;
        }

        string getOriginalTitle(){
            return originalTitle;
        }

        void setIsAdult(bool isAdult){
            this->isAdult = isAdult;
        }

        string getIsAdult(){
            return isAdult;
        }

        void setStartYear(int startYear){
            this->startYear = startYear;
        }

        string getStartYear(){
            return startYear;
        }

        void setEndYear(int endYear){
            this->endYear = endYear;
        }

        string getEndYear(){
            return endYear;
        }

        void setRuntimeMinutes(int runtimeMinutes){
            this->runtimeMinutes = runtimeMinutes;
        }   

        string getRuntimeMinutes(){
            return runtimeMinutes;
        }

};


void insertMovie(vector<string> coluna, vector<Movie>& Movies){
    Movie* novo = new Movie(coluna[0]
                          , coluna[1]
                          , coluna[2]
                          , coluna[3]
                          , coluna[4]
                          , coluna[5]
                          , coluna[6]
                          , coluna[7]);

    Movies.push_back(*novo);
}

void imprimeMovie(Movie a){
    cout << a.getTconst() << " | ";
    cout << a.getTitleType() << " | ";
    cout << a.getPrimaryTitle() << " | ";
    cout << a.getOriginalTitle() << " | ";
    cout << a.getIsAdult() << " | ";
    cout << a.getStartYear() << " | ";
    cout << a.getEndYear() << " | ";
    cout << a.getRuntimeMinutes();
    cout << endl;
}

class Cinema{
    string cinemaID;
    string name;
    string xCoordinate;
    string yCoordinate;
    string ticketPrice;

    public:
        void setCinemaID(string cinemaID){
            this->cinemaID = cinemaID;
        }

        string getCinemaID(){
            return cinemaID;
        }

        void setName(string name){
            this->name = name;
        }

        string getName(){
            return name;
        }

        void setXCoordinate(string xCoordinate){
            this->xCoordinate = xCoordinate;
        }

        string getXCoordinate(){
            return xCoordinate;
        }

        void setYCoordinate(string yCoordinate){
            this->yCoordinate = yCoordinate;
        }

        string getYCoordinate(){
            return yCoordinate;
        }

        void setTicketPrice(string ticketPrice){
            this->ticketPrice = ticketPrice;
        }

        string getTicketPrice(){
            return ticketPrice;
        }
};

void insertCinema(vector<string> coluna, vector<Cinema>& Cinemas){
    Cinema novo;

    novo.setCinemaID(coluna[0]);
    novo.setName(coluna[1]);
    novo.setXCoordinate(coluna[2]);
    novo.setYCoordinate(coluna[3]);
    novo.setTicketPrice(coluna[4]);

    Cinemas.push_back(novo);
}


void imprimeCinema(Cinema a){
    cout << endl;
    cout << a.getCinemaID() << " ";
    cout << a.getName() << " ";
    cout << a.getXCoordinate() << " ";
    cout << a.getYCoordinate() << " ";
    cout << a.getTicketPrice() << " ";
    cout << endl;
}

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

void searchByTipe(vector<Movie> M, string value){
    if(value == "short"){
        for(int i = 0; i < M.size(); i++)
            if(M[i].getTitleType() == "short"){
                imprimeMovie(M[i]);
            }
    }
}

int main(){
    ifstream arquivoCinema("./cinemasTest.txt");
    ifstream arquivoMovies("./moviesTest.txt");

    vector <Cinema> C;
    vector <Movie> M;
    vector<string> linhaCinema;
    vector<string> linhaMovies;

    Cinema titulo;
    
    titulo.setCinemaID("Cinema_ID");
    titulo.setName("Nome_do_Cinema");
    titulo.setXCoordinate("Coordenada_X");
    titulo.setYCoordinate("Coordenada_Y");
    titulo.setTicketPrice("Preço_Ingresso");

    Movie tituloM("tconst", "titleType", "primaryTitle", "originalTitle", "isAdult", "startYear", "endYear", "runtimeMinutes");

    M.push_back(tituloM);
    //C.push_back(titulo);    

    string linha;

    if(arquivoCinema.is_open() && arquivoMovies.is_open())
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


    //for(int i = 0; i < C.size(); i++)
      //  imprimeCinema(C[i]);

    /*for(int i = 0; i < M.size(); i++){
        cout << M[i].getTitleType();
        cout << endl;
    }*/

   searchByTipe(M, "short");

    //selectionSort(C);

    /*for(int i = 0; i < C.size(); i++)
        imprimeCinema(C[i]);*/

    return 0;
}
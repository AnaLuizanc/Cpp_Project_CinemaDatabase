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
        /*Movie(string tconst, string titleType, string primaryTitle, string originalTitle, string isAdult, string startYear, string endYear, string runtimeMinutes/*, vector<string> genres){
            this->tconst = tconst;
            this->titleType = titleType;
            this->primaryTitle = primaryTitle;
            this->originalTitle = originalTitle;
            this->isAdult = isAdult;
            this->endYear = endYear;
            this->startYear = startYear;
            this->runtimeMinutes = runtimeMinutes;
            //for(int i=0; i < genres.size(); i++)
                //this->genres.push_back(genres[i]);
        }*/
        
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

        void setIsAdult(string isAdult){
            this->isAdult = isAdult;
        }

        string getIsAdult(){
            return isAdult;
        }

        void setStartYear(string startYear){
            this->startYear = startYear;
        }

        string getStartYear(){
            return startYear;
        }

        void setEndYear(string endYear){
            this->endYear = endYear;
        }

        string getEndYear(){
            return endYear;
        }

        void setRuntimeMinutes(string runtimeMinutes){
            this->runtimeMinutes = runtimeMinutes;
        }   

        string getRuntimeMinutes(){
            return runtimeMinutes;
        }

        void setGenres(vector<string> genres){
            for(int i=0; i < genres.size(); i++)
                this->genres.push_back(genres[i]);
        }

        void getGenres(){
            for(int i=0; i < this->genres.size(); i++)
                cout << this->genres[i] << " ";
            cout << endl;
        }
};


//void insertMovie(vector<string> coluna, vector<Movie>& Movies){
    //Movie* novo = new Movie(coluna[0], coluna[1], coluna[2], coluna[3], coluna[4], coluna[5], coluna[6], coluna[7]/*, coluna[8]);

    //Movies.push_back(*novo);
//}


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

    string linha = coluna[8];
    stringstream ss(linha);
    string item;
    vector<string> genres;
    
    while(getline(ss, item, ','))
        genres.push_back(item);
    novo.setGenres(genres);

    Movies.push_back(novo);
}

void imprimeMovie(Movie a){
    cout << a.getTconst() << " | ";
    cout << a.getTitleType() << " | ";
    cout << a.getPrimaryTitle() << " | ";
    cout << a.getOriginalTitle() << " | ";
    cout << a.getIsAdult() << " | ";
    cout << a.getStartYear() << " | ";
    cout << a.getEndYear() << " | ";
    cout << a.getRuntimeMinutes() << " | ";
    a.getGenres();
    cout << endl;
}

class Cinema{
    string cinemaID;
    string name;
    string xCoordinate;
    string yCoordinate;
    string ticketPrice;
    vector<string> movies; 

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

        void setMovies(vector<string> movies){
            for(int i=0; i<movies.size(); i++)
                this->movies.push_back(movies[i]);
        }

        void getMovies(){
            for(int i=0; i<this->movies.size(); i++)
                cout << this->movies[i] << " ";
            cout << endl;
        }
};

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


void imprimeCinema(Cinema a){
    cout << endl;
    cout << a.getCinemaID() << " ";
    cout << a.getName() << " ";
    cout << a.getXCoordinate() << " ";
    cout << a.getYCoordinate() << " ";
    cout << a.getTicketPrice() << " ";
    a.getMovies(); 
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

void merge(vector<Movie>& m, int left, int mid, int right){
    vector<Movie> aux(right-left+1);
    for(int i = left, k=0; i <= right; ++i, ++k)
        aux[k] = m[i];
    
    int i = 0, j = mid-left+1, k = left;

    while(i <= mid-left && j <= right-left){
        if(aux[i].getPrimaryTitle() <= aux[j].getPrimaryTitle())
            m[k++] = aux[i++];
        else
            m[k++] = aux[j++];
    }

    while(i <= mid-left)
        m[k++] = aux[i++];
}

void mergeSort(vector<Movie>& m, int left, int right){
    if(left >= right)
        return;
    
    int mid = (left+right)/2;

    mergeSort(m, left, mid);
    mergeSort(m, mid+1, right);
    merge(m, left, mid, right);
}

void searchByType(vector<Movie> M, string value){
    for(int i = 0; i < M.size(); i++)
        if(M[i].getTitleType() == value){
            imprimeMovie(M[i]);
        }
}


void searchByYear(vector<Movie> M, string value){
    for(int i=0; i < M.size(); i++){
        if(M[i].getStartYear() == value || M[i].getEndYear() == value)
            imprimeMovie(M[i]);
    }
}

void searchByRangeYears(vector<Movie> M, int startValue, int endValue){
    for(int i=1; i < M.size(); i++){
        int startYear = stoi(M[i].getStartYear());
        string s = "\\N";
        if(M[i].getEndYear() == s)
            continue;
        else{
            int endYear = stoi(M[i].getEndYear());
            if(startValue >= startYear && endYear <= endValue)
                imprimeMovie(M[i]);
        }
    }
}

int main(){
    ifstream arquivoCinema("./cinemasTest.txt");
    ifstream arquivoMovies("./moviesTest.txt");

    vector <Cinema> C;

    Cinema titulo;

    vector<string> vetMovies;
    vetMovies.push_back("Filmes_em_Exibicao");
    
    titulo.setCinemaID("Cinema_ID");
    titulo.setName("Nome_do_Cinema");
    titulo.setXCoordinate("Coordenada_X");
    titulo.setYCoordinate("Coordenada_Y");
    titulo.setTicketPrice("Preço_Ingresso");
    titulo.setMovies(vetMovies);

    //imprimeCinema(titulo);


    vector <Movie> M;

    //Movie tituloM("tconst", "titleType", "primaryTitle", "originalTitle", "isAdult", "startYear", "endYear", "runtimeMinutes"/*, "genres"*/);

    //M.push_back(tituloM);
    C.push_back(titulo);   

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

    for(int i=0; i < M.size(); i++)
        imprimeMovie(M[i]);

    //for(int i = 0; i < C.size(); i++)
      //  imprimeCinema(C[i]);

    mergeSort(M,0,M.size()-1);

    cout << "IMPRIME ORDENADO POR TITULO DAQUI PRA BAIXO" << endl;

    for(int i=0; i < M.size(); i++)
        imprimeMovie(M[i]);

    //for(int i = 0; i < C.size(); i++)
        //imprimeCinema(C[i]);

    /*for(int i = 0; i < M.size(); i++){
        cout << M[i].getTitleType();
        cout << endl;
    }*/

   //searchByTipe(M, "short");
   //searchByYear(M, "2018");
   //searchByRangeYears(M, 1985, 1990);

   //string anoS = M[1].getStartYear();
   //int anosI = stoi(anoS);
   //cout << anoS << endl << anosI << endl;

    //selectionSort(C);

    /*for(int i = 0; i < C.size(); i++)
        imprimeCinema(C[i]);*/

    return 0;
}
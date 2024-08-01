#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

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



int main(){
    ifstream arquivoCinema("./cinemasTest.txt");
    vector <Cinema> C;
    vector<string> linhaCinema;

    Cinema titulo;
    
    titulo.setCinemaID("Cinema_ID");
    titulo.setName("Nome_do_Cinema");
    titulo.setXCoordinate("Coordenada_X");
    titulo.setYCoordinate("Coordenada_Y");
    titulo.setTicketPrice("Preço_Ingresso");

    C.push_back(titulo);

    string linha;

    if(arquivoCinema.is_open())
        while(getline(arquivoCinema, linha)){
            linhaCinema.erase(linhaCinema.begin(), linhaCinema.end());

            stringstream ss(linha);
            string item;

            while(getline(ss, item, ',')){
                linhaCinema.push_back(item);
            }
            insertCinema(linhaCinema, C);
        }


    for(int i = 0; i < C.size(); i++)
        imprimeCinema(C[i]);

    return 0;
}
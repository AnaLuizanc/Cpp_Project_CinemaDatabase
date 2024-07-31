#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Cinema{
    string cinemaID;
    string name;
    int xCoordinate;
    int yCoordinate;
    double ticketPrice;

    public:
        Cinema(string c,string n,int x,int y,double t)
            : cinemaID(c), name(n), xCoordinate(x), yCoordinate(y), ticketPrice(t){}

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

        void setXCoordinate(int xCoordinate){
            this->xCoordinate = xCoordinate;
        }

        int getXCoordinate(){
            return xCoordinate;
        }

        void setYCoordinate(int yCoordinate){
            this->yCoordinate = yCoordinate;
        }

        int getYCoordinate(){
            return yCoordinate;
        }

        void setTicketPrice(double ticketPrice){
            this->ticketPrice = ticketPrice;
        }

        double getTicketPrice(){
            return ticketPrice;
        }
};

/*

int main(){
    ifstream arquivo("cinemasTest.txt");

    vector<vector<Cinema>> cinemas;

    string cinemaID;
    string name;
    int xCoordinate;
    int yCoordinate;
    double ticketPrice;

    string item;
    string valor;
    stringstream ss(valor);

    if(arquivo.is_open()){
        while(getline(arquivo, item, ',')){
            while(arquivo >> cinemaID >> name >> xCoordinate >> yCoordinate >> ticketPrice){
                Cinema cinema(cinemaID, name, xCoordinate, yCoordinate, ticketPrice);
                cinemas.push_back(cinema);
            }
        }
    }

    for(const auto& linha : cinemas){
            for(const auto& elemento : linha){
                cout << elemento << " ";
            }
            cout << endl;
        }

    return 0;
}

*/

int main(){
    ifstream arquivo("cinemasTest.txt");

    vector<vector<Cinema>> cinemas;

    string cinemaID;
    string name;

    string linha;
    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            stringstream ss(linha);
            string cI, n, xC, yC, tP;
            vector<Cinema> linhaProcessada;
            getline(ss, cI, ',');
            getline(ss, n, ',');
            getline(ss, xC, ',');
            getline(ss, yC, ',');
            getline(ss, tP, ',');

            int xCoordinate = stoi(xC);
            int yCoordinate = stoi(yC);
            double ticketPrice = stod(tP);

            Cinema cinema(cI, n, xCoordinate, yCoordinate, ticketPrice);
            linhaProcessada.push_back(cinema);
            /*cinema.setCinemaID(cI);
            cinema.setName(n);
            cinema.setXCoordinate(xCoordinate);
            cinema.setYCoordinate(yCoordinate);
            cinema.setTicketPrice(ticketPrice);*/
            cinemas.push_back(linhaProcessada);
        }
        
        //impressão da matriz
        for(const auto& linha : cinemas){
            for(const Cinema& c : linha){
                cout << c.getCinemaID() << ", " << c.getName() << c.getXCoordinate() << ", " << c.getYCoordinate() << ", " << c.getTicketPrice() << endl;
            }
            cout << endl;
        }

        for(int i=0; i<cinemas.size(); i++){
            cout << cinemas[i].getCinemaID() << ", " << cinemas[i].getName() << cinemas[i].getXCoordinate() << ", " << cinemas[i].getYCoordinate() << ", " << cinemas[i].getTicketPrice() << endl;
        }
    }

    return 0;
}
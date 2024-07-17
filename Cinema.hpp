#include <string>
#include <vector>
using namespace std;
#include "Movie.hpp"

class Cinema{
    string cinemaID;
    string name;
    int xCoordinate;
    int yCoordinate;
    double ticketPrice;
    vector<Movie> movies;

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

        int setYCoordinate(){
            return yCoordinate;
        }

        void setTicketPrice(int ticketPrice){
            this->ticketPrice = ticketPrice;
        }

        double getTicketPrice(){
            return ticketPrice;
        }

        void setMovies(string movies[], int amount){
            for (int i = 0; i < amount; i++){
                this->movies.push_back(movies[i]);
            }
        }

        vector<Movie> getMovies(){
            return movies;
        }
};
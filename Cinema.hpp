//include <string>
//#include <vector>
#include "Movie.hpp"
using namespace std;

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

        void setTicketPrice(double ticketPrice){
            this->ticketPrice = ticketPrice;
        }

        double getTicketPrice(){
            return ticketPrice;
        }

        void setMovies(Movie moviesX[], int amount){// string movies[] -> List<Movie> movies
            for (int i = 0; i < amount; i++){
                this->movies.push_back(moviesX[i]);
            }
        }

        vector<Movie> getMovies(){
            return movies;
        }
};
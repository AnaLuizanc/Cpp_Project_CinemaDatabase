#pragma once
#include <iostream>

#include "Movie.hpp"

//using namespace std;

class Cinema{
    public:
    string cinemaID;
    string name;
    string xCoordinate;
    string yCoordinate;
    string ticketPrice;
    vector<string> movies;


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
            for(int i=0; i<movies.size(); i++){
                movies[i].erase(movies[i].begin());
                this->movies.push_back(movies[i]);
            }
        }
 
        vector<string> getMovies(){
            return movies;
        }

};


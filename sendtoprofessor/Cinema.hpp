#pragma once
#include <iostream>
#include "Movie.hpp"

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
            name.erase(name.begin());
            this->name = name;
        }

        string getName(){
            return name;
        }

        void setXCoordinate(string xCoordinate){
            xCoordinate.erase(xCoordinate.begin());
            this->xCoordinate = xCoordinate;
        }

        string getXCoordinate(){
            return xCoordinate;
        }

        void setYCoordinate(string yCoordinate){
            yCoordinate.erase(yCoordinate.begin());
            this->yCoordinate = yCoordinate;
        }

        string getYCoordinate(){
            return yCoordinate;
        }

        void setTicketPrice(string ticketPrice){
            ticketPrice.erase(ticketPrice.begin());
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

#pragma once
#include <string>
#include <vector>
#include <iostream>

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

        vector<string>getGenres(){
            return genres;
        }
};
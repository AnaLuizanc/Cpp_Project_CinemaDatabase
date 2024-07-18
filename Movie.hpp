
#include <string>
#include <vector>
using namespace std;

class Movie{
    string tconst;
    string titleType;
    string primaryTitle;
    string originalTitle;
    bool isAdult;
    int startYear;
    int endYear;
    int runtimeMinutes;
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

        void setIsAdult(bool isAdult){
            this->isAdult = isAdult;
        }

        bool getIsAdult(){
            return isAdult;
        }

        void setStartYear(int startYear){
            this->startYear = startYear;
        }

        int getStartYear(){
            return startYear;
        }

        void setEndYear(int endYear){
            this->endYear = endYear;
        }

        int getEndYear(){
            return endYear;
        }

        void setRuntimeMinutes(int runtimeMinutes){
            this->runtimeMinutes = runtimeMinutes;
        }

        int getRuntimeMinutes(){
            return runtimeMinutes;
        }

        void setGenres(string genresX[], int amount){
            for (int i = 0; i < amount; i++){
                this->genres.push_back(genresX[i]);
            }
        }

        vector<string> getGenres(){
            return genres;
        }

};
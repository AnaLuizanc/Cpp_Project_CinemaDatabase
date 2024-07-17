
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
            tconst = tconst;
        }

        string getTconst(){
            return tconst;
        }

        void setTitleType(string titleType){
            titleType = titleType;
        }

        string getTitleType(){
            return titleType;
        }

        void setPrimaryTitle(string primaryTitle){
            primaryTitle = primaryTitle;
        }

        string getPrimaryTitle(){
            return primaryTitle;
        }

        void setOriginalTitle(string originalTitle){
            originalTitle = originalTitle;
        }

        string getOriginalTitle(){
            return originalTitle;
        }

        void setIsAdult(bool isAdult){
            isAdult = isAdult;
        }

        bool getIsAdult(){
            return isAdult;
        }

        void setStartYear(int startYear){
            startYear = startYear;
        }

        int getStartYear(){
            return startYear;
        }

        void setEndYear(int endYear){
            endYear = endYear;
        }

        int getEndYear(){
            return endYear;
        }

        void setRuntimeMinutes(int runtimeMinutes){
            runtimeMinutes = runtimeMinutes;
        }

        int getRuntimeMinutes(){
            return runtimeMinutes;
        }

        

};
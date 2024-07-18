#include <iostream>
#include <string>
#include <vector>
#include "Cinema.hpp"
using namespace std;

int main(){

    //teste
    vector<string> genres = {"Action", "Short"};
    Movie *movie1 = new Movie("tt7917518", "short", "The Battle II", "The Battle II", 0, 2008, 0, 0, genres);
    cout << movie1->getOriginalTitle();
    return 0;
}   
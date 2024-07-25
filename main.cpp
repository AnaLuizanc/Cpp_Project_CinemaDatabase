#include <iostream>
#include <cstring>
#include <vector>
#include "Cinema.hpp"
#include <fstream>


using namespace std;





int main(){
    string filename = "./Database/cinemas.txt";
    string filename2 = "./Database/movies.txt";


    string fileContents;
    string fileContents2;

    ifstream inputFile(filename);
    ifstream inputFile2(filename2);

    if(inputFile.is_open() && inputFile2.is_open()){
        fileContents.assign((istreambuf_iterator<char>(inputFile)),
                            (istreambuf_iterator<char>()));

        fileContents2.assign((istreambuf_iterator<char>(inputFile2)),
                            (istreambuf_iterator<char>()));

                        

        inputFile.close();        

        cout << fileContents << endl;
        cout << fileContents2 << endl;
    }else{
        cerr << "Error opening file: " << filename << endl;
        cerr << "Error opening file: " << filename2 << endl;

    }





    return 0;
}   
#include <iostream>
#include <cstring>
#include <vector>
#include "Cinema.hpp"
#include <sqlite3.h>

using namespace std;

int callback(void* data, int argc, char** argv, char** azColName){
    for(int i = 0; i < argc; i++){
        cout << "ARGC: [" << argc << "]";
        cout << azColName[i] << ": " << argv[i] << endl;
    }

    //for (int i = 0; i < argc; i++)
    //    cout << argv[i] << "  ";
  

    return 0;
}

int sqlFunc(string databaseName, string cinemaID){
    sqlite3* dbExample;
    char *errCode = 0;

    const char* databaseNameValue = databaseName.c_str();

    sqlite3_open(databaseNameValue, &dbExample);
    string sql = "select * from Cinemas where cinemaID is '" + cinemaID + "';";
    const char* sqlPrint = sql.c_str();

    sqlite3_exec(dbExample, sqlPrint, callback, nullptr, &errCode);
    sqlite3_close(dbExample);

    return 1;
}

int main(){

    string cinemaIDValue;

    cout << "Digite o número ID do Cinema: " << endl;
    cin >> cinemaIDValue;
            
    int returncode = sqlFunc("Cinemas.db", cinemaIDValue);

    if(returncode == 1)
        cout << endl << "Consulta realizada com sucesso" << endl;
    else
        cout << endl << "Consulta falhou" << endl;

    //teste
    /*ector<string> genres = {"Action", "Short"};
    Movie *movie1 = new Movie("tt7917518", "short", "The Battle II", "The Battle II", 0, 2008, 0, 0, genres);
    cout << movie1->getOriginalTitle();*/
    /*sqlite3 *db;

    int returncode;
    char *errCode = 0;

    returncode = sqlite3_open("Cinemas.db", &db);

    if(returncode != SQLITE_OK){
        fprintf(stderr, "Erro ocorreu: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }
    */

    /*string sql = "select * from Cinemas where cinemaID is '" + cinemaID + "';";
    //cout << sql.c_str();
    const char* sqlPrint = sql.c_str();

    returncode = sqlite3_exec(db, sqlPrint, callback, nullptr, &errCode);
    cout << endl;*/
    //const char* sql1 = "select * from Cinemas where cinemaID is '';";
    //returncode = sqlite3_exec(db, sql1, callback, nullptr, &errCode);

    //const char* insertSql = "insert into tabelateste(name, age) values ('thiago', 12)";

    //returncode = sqlite3_exec(db, insertSql, NULL, 0, &errCode);







    


    //sqlite3_close(db);





    return 0;
}   
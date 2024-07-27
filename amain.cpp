#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void imprime(vector<string> lista){
    for(int i=0; i<lista.size(); i++){
        cout << lista[i] << " ";
    }   
    cout << endl;
}    

void ordenaInsertion(vector<string> lista){
    for(int i=0; i<lista.size(); i++){
        int j = i-1;
        string aux = lista[i];
        while(j >= 0 && aux < lista[j]){
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1] = aux;
    }
    imprime(lista);
}

int main(){
    
    vector<string> lista;
    string menor;

    lista.insert(lista.end(), {"Ga", "Bb", "Lc", "Gr", "Ak"});
    // Ak, Bb, Lc, Ga, Gr
    menor = lista[0];
    for(int i = 0; i < lista.size(); i++){
        if(menor > lista[i])
            menor = lista[i];
    }

    ordenaInsertion(lista);

    return 0;
}
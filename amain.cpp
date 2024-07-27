#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void sort(vector<string> lista){
    for(string i : )

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

    sort(lista);

    cout << menor << endl;

    return 0;
}
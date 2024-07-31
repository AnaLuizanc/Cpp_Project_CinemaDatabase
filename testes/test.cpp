#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


/*
// Função para mesclar dois subarrays ordenados
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria arrays temporários
    int L[n1], R[n2];

    // Copia dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    // Mescla os arrays temporários de volta ao array original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Função principal para ordenar o array usando Merge Sort
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Chama mergeSort para a primeira metade
        mergeSort(array, left, mid);
        // Chama mergeSort para a segunda metade
        mergeSort(array, mid + 1, right);

        // Mescla as duas metades ordenadas
        merge(array, left, mid, right);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array antes da ordenação: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Array após a ordenação: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
} */


void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;


    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }

        else{
            arr[k] = R[j];
            j++;
        }

        k++;
    }


    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    

    
}

void mergeSort(vector<int>& arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void selectionSort(vector<int>& lista){
    for(int i = 1; i < lista.size(); i++){
        int aux = lista[i];
        int j = i - 1;

        while(j >= 0 && lista[j] > aux){
            aux = lista[j + 1];
            lista[j + 1] = lista[j];
            lista[j] = aux;
            j--;
        }
    
        lista[j + 1] = aux;
    }
}


int main(){
    ifstream arquivoNum("./Teste.txt");

    vector<int> Numbers;
    string item;
    string valor;
    stringstream ss(valor);

    if(arquivoNum.is_open()){
        while(getline(arquivoNum, item, ' ')){
            Numbers.push_back(stoi(item));
        }
    }

    /*for(int i = 0; i < Numbers.size(); i++){
        cout << Numbers[i] << endl;
    }*/

    //mergeSort(Numbers, 0, Numbers.size() - 1);
    selectionSort(Numbers);

    cout << Numbers[0] << " " << Numbers[65] << "," << Numbers[4567];

    //for(int i = 0; i < Numbers.size(); i++){
      //  cout << Numbers[i] << endl;
    //}



    return 0;
}
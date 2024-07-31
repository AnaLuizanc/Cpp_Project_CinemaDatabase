#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void merge(vector<string>& v, int left, int mid, int right){
    vector<string> aux(right-left+1);
    for(int i = left, k=0; i <= right; ++i, ++k)
        aux[k] = v[i];
    
    int i = 0, j = mid-left+1, k = left;

    while(i <= mid-left && j <= right-left){
        if(aux[i] <= aux[j])
            v[k++] = aux[i++];
        else
            v[k++] = aux[j++];
    }

    while(i <= mid-left)
        v[k++] = aux[i++];
}

void mergeSort(vector<string>& v, int left, int right){
    if(left >= right)
        return;
    
    int mid = (left+right)/2;

    mergeSort(v, left, mid);
    mergeSort(v, mid+1, right);
    merge(v, left, mid, right);
}

void selectionSort(vector<string>& v){
    for(int i = 1; i < v.size(); i++){
        string aux = v[i];
        int j = i - 1;

        while(j >= 0 && v[j] >= aux)
            v[j + 1] = v[j--];
    
        v[j + 1] = aux;
    }
}

int main(){
    vector<string> v = {"banana", "baunilha", "cadeira", "aviao", "carro", "dado", "cubo"};

    int left = 0;
    int right = v.size()-1;

    for(int i=0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl << endl;

    //mergeSort(v, left, right);
    selectionSort(v);

    for(int i=0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> merge1(vector<int> v1, vector<int> v2){ //recebe dois vetores ordenados e devolve um vetor ordenado com a uniao dos dois
    int i = 0, j = 0;
    vector<int> vr;

    while (i < v1.size() && j < v2.size()){
        if (v1[i] < v2[j]){
            vr.push_back(v1[i]);
            i++;
        }
        else{
            vr.push_back(v2[j]);
            j++;
        }
    }

    while (i < v1.size()){
        vr.push_back(v1[i]);
        i++;
    }
    while (j < v2.size()){
        vr.push_back(v2[j]);
        j++;
    }

    return vr;
}

void merge2(vector<int>& v){//recebe um vetor com suas metades ordenadas e devolve um vetor completamente ordenado
    int meio = (v.size()-1)/2;
    int i=0, j = meio+1, indice = 0;
    vector<int> vr;

    while(i <= meio && j < v.size()){
        if(v[i] < v[j]){
            vr.push_back(v[i++]);
        }
        else
            vr.push_back(v[j++]);
    }
    while(i <= meio)
        vr.push_back(v[i++]);
    while(j <= v.size())
        vr.push_back(v[j++]);

    for(int i=0; i<v.size(); i++)
        v[i] = vr[i];

}

void merge(vector<int>& v, int esquerda, int meio, int direita){
    vector<int> aux(direita - esquerda + 1);
    for(int i = esquerda, k = 0 ; i <= direita; ++i, ++k)
        aux[k] = v[i];
    
    int i = 0;
    int j = meio - esquerda + 1;
    int k = esquerda;

    while(i <= meio - esquerda && j <= direita - esquerda){
        if(aux[i] <= aux[j])
            v[k++] = aux[i++];
        else
            v[k++] = aux[j++];
    }

    while(i <= meio - esquerda){
        v[k++] = aux[i++];
    }

}

void mergeSort(vector<int>& v, int esquerda, int direita){
    if(esquerda >= direita)
        return;
    int meio = (esquerda+direita) / 2;
    mergeSort(v, esquerda, meio);
    mergeSort(v, meio+1, direita);
    merge(v, esquerda, meio, direita);
}

int main()
{
    vector<int> v1 = {3, 5, 7, 12, 17, 22, 23, 27, 45, 49, 60, 71, 77};
    vector<int> v2 = {1, 4, 7, 13, 22, 31, 43, 46, 50};
    vector<int> v3 = {2,8,11,27,30,47,51,57,7,17,20,25,40,70,90};
    vector<int> merged = merge1(v1, v2);

    for (unsigned int i = 0; i < merged.size(); i++)
        cout << merged[i] << " ";

    cout << endl << endl;
    //vector<int> merged2 = merge2(v3);

    merge2(v3);

    for(int i=0; i<v3.size(); i++)
        cout << v3[i] << " ";

    //for(int i=0; i< v3.size(); i++)
        //cout << merged2[i] << " ";

    cout << endl << endl;

    vector<int> v4 = {4,6,8,1,2,99,23,67,12,98,100};
    int esq = 0, dir = v4.size()-1;
    mergeSort(v4, esq, dir);

    for(int i=0; i<v4.size(); i++)
        cout << v4[i] << " ";

    return 0;
}

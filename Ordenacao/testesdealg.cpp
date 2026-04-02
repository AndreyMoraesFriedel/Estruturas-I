#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool numeroEstaNoVetor(vector<int>& v, int n){
        bool esta = false;
        for(int i = 0;i<v.size();i++){
                if(n == v[i]){
                        esta = true;
                        break;
                }
        }
        return esta;
}


int gerarNumeroAleatorio(int n){
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<> dist(1, n);
        return dist(mt);
}

vector<int> numerosEmbaralhados(int n){
        vector<int> v;
        int i = 0;
        while(i<n){
                int rd = gerarNumeroAleatorio(n);
                if(numeroEstaNoVetor(v, rd)){
                        continue;
                }
                v.push_back(rd);
                i++;
        }
        return v;
}

void bubbleSort(vector<int>& v){
        int i, j;
        int n = v.size();
        for(i = n -1;i>0;i--){
                for(j = 0;j<i;j++){
                        if(v[j]>v[j+1]){
                                int temp = v[j];
                                v[j] = v[j+1];
                                v[j+1] = temp;
                        }
                }
        }
}

void troca(vector<int>& v, int a, int b){
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
}

int particiona(vector<int>& v, int a, int b){
        int x = v[a];
        while(a<b){
                while(v[a] < x){
                        a++;
                }
                while(v[b] > x){
                        b--;
                }
                troca(v, a, b);
        }
        return a;
}

void quickSort(vector<int>& v, int a,int b){
        if(a < b){
                int indicePivo = particiona(v, a, b);
                quickSort(v, a, indicePivo -1);
                quickSort(v, indicePivo + 1, b);
        }
}

void merge(vector<int>& A,int p,int  q,int r){
        int n1 = q - p + 1;
        int n2 = r -q;
        vector<int> L(n1+1);
        vector<int> R(n2+1);
        for(int i = 0;i<n1;i++){
                L[i] = A[p+i];
        }
        for(int j = 0;j<n2;j++){
                R[j] = A[q+j+1];
        }
        L[n1] = INT_MAX;
        R[n2] = INT_MAX;
        int i = 0;
        int j = 0;
        for(int k = p;k<=r;k++){
                if(L[i] <= R[j]){
                        A[k] = L[i];
                        i++;
                }else{
                        A[k] = R[j];
                        j++;
                }
        }
}

void mergeSort(vector<int>& A,int p,int r){
        if(p < r){
                int q = (p + r) / 2;
                mergeSort(A, p, q);
                mergeSort(A, q+1, r);
                merge(A, p, q, r);
        }
}

void mostrarMetricas(vector<int>& bvet){
        auto inicio = steady_clock::now();
        bubbleSort(bvet);
        auto fim = steady_clock::now();
        auto tempo = fim - inicio;       
        cout << tempo.count() << "ns";
}

void mostrarMetricas(vector<int>& qvet, int a, int b){
        auto inicio = steady_clock::now();
        quickSort(qvet, a, b);
        auto fim = steady_clock::now();
        auto tempo = fim - inicio;       
        cout << tempo.count() << "ns";
}

void mostrarMetricasMerge(vector<int>& mvet,int p,int r){
        auto inicio = steady_clock::now();
        mergeSort(mvet,p, r);
        auto fim = steady_clock::now();
        auto tempo = fim - inicio;       
        cout << tempo.count() << "ns";
}

void tabulacao(int i){
        if(i<2){
                cout << "\t\t";
        }else{
                cout << "\t";
        }
}

int main(){
        vector<int> numeros = {10, 100, 1000, 10000};
        cout << "Tamanho\tBubbleSort\tQuickSort\tMergeSort" << endl;
        for(int i = 0; i<numeros.size();i++){
            cout << numeros[i] << "\t";
            vector<int> vet = numerosEmbaralhados(numeros[i]);
            vector<int> bvet = vet;
            vector<int> qvet = vet;
            vector<int> mvet = vet;
            mostrarMetricas(bvet);
            tabulacao(i);
            mostrarMetricas(qvet, 0, qvet.size() - 1);
            tabulacao(i);
            mostrarMetricasMerge(mvet, 0, mvet.size() - 1);
            cout << endl;
        }
}
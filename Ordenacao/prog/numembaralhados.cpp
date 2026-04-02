#include <bits/stdc++.h>
using namespace std;

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



int main(){
        vector<int> v = numerosEmbaralhados(5);
        for(int i = 0; i<5;i++){
                cout << v[i] << " ";
        }
        cout << endl;
}
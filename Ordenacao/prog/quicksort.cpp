#include <bits/stdc++.h>
using namespace std;


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


int main(){
        vector<int> v = {5,2, 4, 3, 1};
        quickSort(v, 0, v.size() -1);
        for(int i =0; i<v.size();i++){
                cout << v[i] << " ";
        }
        cout << endl;
}
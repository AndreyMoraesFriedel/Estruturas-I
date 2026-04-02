#include <bits/stdc++.h>
using namespace std;

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

int main(){
        vector<int> v = {5, 2, 4, 3, 1};
        bubbleSort(v);
        for(int i = 0;i<v.size();i++){
                cout << v[i] << " ";
        }
        cout << endl;
}
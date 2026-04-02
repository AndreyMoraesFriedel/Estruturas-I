#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& A,int p,int  q,int r){
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

void MergeSort(vector<int>& A,int p,int r){
        if(p < r){
                int q = (p + r) / 2;
                MergeSort(A, p, q);
                MergeSort(A, q+1, r);
                Merge(A, p, q, r);
        }
}

int main(){
        vector<int> A = {5,2, 4, 3, 1};
        MergeSort(A, 0, A.size() -1);
        for(int i = 0; i<A.size();i++){
                cout << A[i] << " ";
        }
        cout << endl;
}
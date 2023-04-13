#include <bits/stdc++.h>
#include <vector>
using namespace std;

void swap(int *a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(vector<int> &array){
    int n = array.size();
    for (int i = 0;i<n;i++){
        int value = array[i];
        int hole = i;
        while (hole>0 && value<array[hole-1]){
            array[hole] = array[hole-1];
            hole--;
        }
        array[hole] = value;
    }
}

void bubbleSort(vector<int> &array){
    for (int step = 0; step<array.size();step++){
        bool swapped = false;
        for (int i = 0;i<array.size()-1-step;i++){
            if (array[i]>array[i+1]){
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
void selectionSort(vector<int>&array){
    for (int step = 0;step<array.size()-1;step++){
        int min_index = step;
        for(int i = step+1;i<array.size();i++){
            if (array[i]<array[min_index])
                min_index = i;
        }
        swap(array[step],array[min_index]);
    }
}
void merge(vector<int>L, vector<int>R ,vector<int>&array){
    int i =0,j=0,k=0;
    while(i<L.size() &&j<R.size()){
        if (L[i]<=R[j]){
            array[k]=L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<L.size()){
        array[k]=L[i];
        i++;
        k++;
    }
    while(j<R.size()){
        array[k]=R[j];
        j++;
        k++;
    }
}
vector<int> mergeSort(vector<int>&array){
    if (array.size()<2)
        return array;
    int mid = array.size()/2;
    vector<int>left(array.begin(),array.begin()+mid);
    vector<int>right(array.begin()+mid,array.end());
    mergeSort(left);
    mergeSort(right);
    merge(left,right,array);
    return array;
}



int main(){
    vector<int> a = {5,4,3,2,1};
    vector<int> b = mergeSort(a);
    for (int i : b)
        cout<<i<<" ";
}
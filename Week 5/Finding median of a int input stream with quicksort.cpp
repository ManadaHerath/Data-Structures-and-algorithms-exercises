#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;


int split(vector<int>& array, int l, int h) {
    int key = array[h];
    int i = l - 1;

    for(int j=l; j < h; j++) {
        if(array[j] < key) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[h]);
    return i+1;
}

void recquicksort(vector<int>& array, int l, int h) {
    if(l < h) {
        int pi = split(array, l, h);

        recquicksort(array, l, pi - 1);
        recquicksort(array, pi + 1, h);
    }
}

void nonrecquicksort(vector<int>& array, int l, int h) {
    while (l < h) {
        int i = l, j = h;
        int key = array[(l + h) / 2];

        while (i <= j) {
            while (array[i] < key) {
                i++;
            }
            while (array[j] > key) {
                j--;
            }

            if (i <= j) {
                swap(array[i], array[j]);
                i++;
                j--;
            }
        }

        if (j - l < h - i) {
            nonrecquicksort(array, l, j);
            l = i;
        } else {
            nonrecquicksort(array, i, h);
            h = j;
        }
    }
}
float median(vector<int> array){
    int x = array.size();
    int y = array.size()/2;
    if (x==1)   //if size is 0 return only number
        return array[0];
    else if (x % 2 ==0) // if even elements should get 2
        // mid numbers in sorted array and get average of both
        return ((array[y-1]+array[y])/2.0);
    else // if odd elements get the middle number of sorted arr
        return array[y];
}
int main() {

    int n ;
    cin>>n;
    srand(time(NULL));
    vector<int> array;
    for (int i = 0; i < n; i++) {
        array.push_back(rand() % n); // random num adding from 1 to n-1
        }
    //got a random vector array in size n
    for (int z: array)
        cout<<z<<" ";
    cout<<endl;
    for( int i = 0 ; i <n ; i++){
        vector<int> sarr(array.begin(),array.begin()+i+1);
        //getting the sub arrays from size 0 to n
        recquicksort(sarr,0,i);      //sorting using quicksort
        cout<<"after adding the number sorted sub array : ";
        for (int z: sarr)
            cout<<z<<" ";
        cout<<endl;
        cout<<"Median is "<<median(sarr)<<endl;
    }






}



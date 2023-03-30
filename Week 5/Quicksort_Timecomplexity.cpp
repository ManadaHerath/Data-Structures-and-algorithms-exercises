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

int main() {
    vector<int> v = {10, 100, 500, 1000, 4000, 8000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000,
                     60000};
    for (int n: v) {
        srand(time(NULL));
        vector<int> array1(n);
        for (int i = 0; i < n; i++) {
            array1[i]=rand() % n; // random num adding from 1 to n-1
        }
        vector<int>array2 = array1;

        auto start1 = high_resolution_clock::now();
        recquicksort(array1,0,n-1);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        auto start2 = high_resolution_clock::now();
        nonrecquicksort(array2,0,n-1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);

        cout<<n<<"recursive time "<< duration1.count()<<"   non recursive time "<<duration2.count()<<endl;

    }
}



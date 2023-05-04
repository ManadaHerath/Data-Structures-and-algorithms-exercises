#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void swap(int *a, int *b) { //to swap the addresses of 2 inputs
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int arr[], int n, int root) { // heapify function

    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        heapify(arr, n, largest);
    }

}


void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) //creating max heap
        heapify(arr, n, i);


    for (int i = n - 1; i > 0; i--) { //getting the largest numbers one by one
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

std::vector<int> stringToAVector(std::string str) {// to convert the input string to vector
    std::vector<int> vec;
    std::stringstream ss(str);

    int i;
    while (ss >> i) {
        vec.push_back(i);

        if (ss.peek() == ' ') {
            ss.ignore();
        }
    }
    return vec;
}

int main() {

    string input_numbers;
    cout<<"Input the Numbers to be Sorted :- "<<endl;
    getline(cin, input_numbers); //getting the input string
    vector<int> vec = {stringToAVector(input_numbers)}; //getting the vector of numbers

    int n = vec.size();
    int array[n];
    copy(vec.begin(),vec.end(),array); //getting the data from the vector to array (heap functions want array as input)

//    int heap_arr[] = {4, 17, 3, 12, 9, 6};
//    int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
    cout << "Input array" << endl;
    displayArray(array, n);    //input array

    heapSort(array, n);

    cout << "Sorted array" << endl;
    displayArray(array, n);  //sorted output array
}
#include<bits/stdc++.h>
using namespace std;
class Heap {
public:
int size;
int arr[100];

Heap()
{
    size=0;
    arr[0]=-1;
}

void insert(int val) {
        // Your code goes here
        size++;
        int index = size;
        arr[index] = val;
        
        while(index > 1) {
            int parent = index / 2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void deleteFromHeap() {
        // Your code goes here
        if(size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }
        
        arr[1] = arr[size];
        size--;
        
        heapify(arr, size, 1);
    }
    void heapify(vector<int>& arr, int n, int i) {
        // Your code goes here
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        
        if(right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        
        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    void heapSort(vector<int>& arr, int n) {
        // Your code goes here
        for(int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        
        for(int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};
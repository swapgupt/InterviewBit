#include <iostream>
#include <vector>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify (std::vector<int> &arr, int n, int i){
    
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
    
    return;
}

void heapSort (std::vector<int> &arr, int n){
    
    for (int i = n/2 - 1; i >=0; i--){
        heapify(arr, n, i);
    }
    
    
    for (int i = n - 1; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        
        heapify(arr, i, 0);
    }
    
    return;
}

int main(){
   std::vector<int> arr = {1, 7, 4, 3, 6, 2, 5, 8};

   heapSort(arr, 8);

   for (auto a : arr){
       std::cout << a << " ";
   }

   return 0;
}
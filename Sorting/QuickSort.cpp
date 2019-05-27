#include <iostream>
#include <vector>

namespace QUICKSORT
{
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (std::vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    
    return i + 1;
}

void quickSort (std::vector<int> &arr, int low, int high){
    
    if (low < high){
        int pivot = partition(arr, low, high);
        
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
    
    return;
}
}

int main(){
   std::vector<int> arr = {1, 7, 4, 3, 6, 2, 5, 8};
   
   quickSort(arr, 0, 7);
   
   for (auto a : arr){
       std::cout << a << " ";
   }
   
   return 0;
}
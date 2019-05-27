#include <iostream>
#include <vector>

void merge (std::vector<int> &arr, int low, int mid, int high){
    int nL = mid - low + 1;
    int nR = high - mid;
    std::vector<int> L, R;
    int i, j, k;
    
    for (i = low; i <= mid; i++)
        L.push_back(arr[i]);
    
    for (i = mid+1; i <= high; i++)
        R.push_back(arr[i]);
    
    i = 0;
    j = 0;
    k = low;
    
    while (i < nL && j < nR){
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    
    while (i < nL)
        arr[k++] = L[i++];
    
    while (j < nR)
        arr[k++] = R[j++];
    
    return;
}

void mergeSort (std::vector<int> &arr, int low, int high){
    
    if (low < high){
        int mid = low + (high - low)/2;
        
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        
        merge(arr, low, mid, high);
    }
    
    return;
    
}

int main(){
   std::vector<int> arr = {1, 7, 4, 3, 6, 2, 5, 8};
   
   mergeSort(arr, 0, 7);
   
   for (auto a : arr){
       std::cout << a << " ";
   }
   
   return 0;
}


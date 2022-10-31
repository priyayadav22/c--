#include <iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int pivot= arr[s];
    int count=0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivotKaIndex= s+count;
    swap(arr[pivotKaIndex],arr[s]);
    int i=s; 
    int j= e;

    while(i<pivotKaIndex && j>pivotKaIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]> pivot){
            j--;
        }
        if(i<pivotKaIndex && j>pivotKaIndex){
            swap(arr[i++], arr[j--]);
            
            
        }
    }return pivotKaIndex;
}

void quickSort(int * arr, int s, int e){
    if(s>=e)
    return ;
    int p= partition(arr, s,e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1,e);
}

int main(){
    int arr[10] ={6,4,3,6,5,7,9,8,4,1};
    int n=10;
    quickSort(arr,0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<< " ";
    }

    return 0;
}
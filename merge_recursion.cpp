#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid= (s+e)/2;
    int len1 =mid-s-1; //1st array length
    int len2= e-mid;   //2nd array length

    int *first= new int[len1];  //creating 1st arr
    int *second = new int[len2]; //creating 2nd arr

    //copying first arr
    int index=s;
    for(int i=0; i<len1; i++){
        first[i]= arr[index++];
    }

    //copying 2nd arr
    index=mid+1;
    for(int i=0; i<len2; i++){
        second[i]= arr[index++];
    }

    //merging both
    int ind1=0;
    int ind2=0;
    index= s;
    while(ind1<len1 && ind2<len2){
        if(first[ind1]< second[ind2]){
            arr[index++] = first[ind1++];
        }
        else{
            arr[index++] = second[ind2++];
        }
    }
    while(ind1<len1){
        arr[index++] = first[ind1++];
    }
    while(ind2<len2){
        arr[index++] = second[ind2++];
    }
    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e){
    if(s>=e)
    return;
    int mid= (s+ e)/2;
    //1st half array
    mergeSort(arr,s,mid);
    //2nd half array
    mergeSort(arr, mid+1, e);
    //combining both
    merge(arr,s,e);
}

int main(){
    int arr[10] ={7,6,5,3,1,8,0,2,6,9};
    int size =15;
    mergeSort(arr,0, size-1);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
#include <iostream>
using namespace std;

void reversedArray(int arr[]), int size){
    int i=0;
    int j=size-1;

    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}


int main(){
    int arr={1,2,3};
    reversedArray(arr,size);

    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        //reversed array
        cout<<arr[i]<<" ";          //output : 3 2 1
    }
}
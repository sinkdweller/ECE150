#include <iostream>
#include <cassert>


void array_flip(int arr[], int capacity){
    int first_num = arr[capacity-1];
    for(int i=(capacity-1); i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = first_num;
}
void print_array(int arr[], int capacity){
    for(int i=0; i<capacity; i++){
        std::cout<<arr[i]<<std::endl;
    }
}
int main(){
    int array[5]{1, 2, 3, 4, 5};
    int capacity = 5;
    array_flip(array, capacity);
    print_array(array, capacity);
return 0;
}
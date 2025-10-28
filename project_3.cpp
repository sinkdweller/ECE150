#include <iostream>
#include <cassert>

/*The first function double *geometric( double a, double ratio, std::size_t cap ) returns the address
of a dynamically allocated array of double that stores the values a, ar, ar2, ar3, up to arn−1 where r is the
ratio and n is the capacity of the array */
double *geometric( double a, double ratio, std::size_t cap ){
    double* array = new double[cap];
    array[0] = a;
 
    for(int i=1; i<cap; i++){
        array[i] = array[i-1]*ratio;
    }
    return array;

}
/*Second function will return a dynamically allocated array of capacity cap0 + cap1 - 1. With each entry of this new array
initialized to zero, you will then calculate each pair of products array0[i]*array1[j] and add this to the
result at index i + j. You may assert that cap0 + cap1 >= 1*/

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1){

    assert(cap0 + cap1 >= 1);

    double* arr = new double[cap0 + cap1 - 1]{};
    for(int i=0; i<cap0; i++){
        for(int j =0; j< cap1; j++){
            arr[i+j] += array0[i]*array1[j];
        }
    }
    return arr;

}

/*will move
duplicate entries to the end of the array. The unique entries will be moved to the front of the array in the
same order that they first appear, while the duplicate entries will be moved to the end of the array, but the
order does not matter. The value returned will be the number of unique entries.*/
//150550 --> 150


bool in_array(int array[], int value, std::size_t capacity){
    for(int i =0; i< capacity; i++){
        if(array[i] == value){
            return true;
        }
    }
    return false;
}
void shift_back(int array[], std::size_t capacity, int index){
    int temp = array[index];
    for(int i=index; i<capacity-1; i++){
        array[i] = array[i+1];
    }
    array[capacity-1] = temp;

}
std::size_t shift_duplicates( int array[], std::size_t capacity ){//[0,8,0,1,8,0] --> capacity-1 = 5
    int nums_checked{0};
    bool is_unique{true};
    int unique_count{1};
    while(nums_checked < capacity-1){
        is_unique = true;
        for(int i=0; i<unique_count; i++){
            if(array[unique_count]==array[i]){
                shift_back(array, capacity, unique_count);
                is_unique = false;
                break;
            }
        }
        if(is_unique){
            unique_count++;
        }
        nums_checked ++;


    }
    return unique_count;
}
// If is_array is true, then you will loop through the array setting each entry to zero. The third argument
// will contain the capacity of the array. You will then deallocate that memory.
// 2. Otherwise, it is not an array, so it is just a pointer to one instance of type double. You will set that
// entry to zero and the third argument will be ignored
void deallocate( double *&ptr, bool is_array, std::size_t capacity = 0 ){
if(is_array){
    for(std::size_t i=0; i<capacity; i++){
        ptr[i] = 0;
    }
    delete[] ptr;
}else {
    *ptr =0;
    delete ptr;
    }
    ptr = nullptr;
}

int main(){
    int* array = new int[6]{0,8,0,1,8,0};

    shift_duplicates(array, 6);
    for(int i =0; i<6; i++){
        std::cout<<array[i];
    }
    delete array;
    array = nullptr;


    return 0;
}

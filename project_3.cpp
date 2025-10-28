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
void shift_to_back (int array[], int b, std::size_t capacity){ // [0,1,b,2,3] --> [0,1,2,3,b]
    int temp_b_val= array[b];
    for(int i= b; i<capacity-1; i++){
        array[b]= array[b+1];
    }
    array[capacity-1] = temp_b_val;
}

bool in_array(int array[], int value, std::size_t capacity){
    for(int i =0; i< capacity; i++){
        if(array[i] == value){
            return true;
        }
    }
    return false;


}

std::size_t shift_duplicates( int array[], std::size_t capacity ){
    int* unique_array = new int[capacity]{0};
    int u{0};

    int* non_unique_array = new int[capacity]{0};
    int nu{0};


    bool first_zero{true};
    for(int i=0; i<capacity; i++){
        //special if 0 case
        if(array[i] == 0 && first_zero){
            first_zero = false;
            u ++;
        }
        else if(in_array(unique_array, array[i], capacity)||(array[i]==0 && !first_zero)){
            non_unique_array[nu] = array[i];
            nu++;
        }else{
            unique_array[u]= array[i];
            u++;
        }
    }
    for(int i=0;i<u;i++){
        array[i] = unique_array[i];
    }
    for(int i=0; i<nu; i++){
        array[u+i]=non_unique_array[i];
    }

    delete unique_array;
    unique_array = nullptr;

    delete non_unique_array;
    non_unique_array = nullptr;
        return u;

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

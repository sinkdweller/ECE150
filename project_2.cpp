#include <iostream>
#include <cassert>
void pattern(unsigned int n){//n 
    int t{1};
    unsigned int ast_count{2*n+1};

    for(unsigned int row_count=0; row_count <2*n+1; row_count++){
        if(ast_count ==1) t*=-1;//start adding asterix count

        unsigned int space_count = (2*n+1-ast_count)/2;
        //leftspace
        for(unsigned int n = 0; n<space_count; n++){
            std::cout<<" ";
        }
        for(unsigned int n = 0; n<ast_count; n++){
            std::cout<<"*";
        }
        //rightspace
        for(unsigned int n = 0; n<space_count; n++){
            std::cout<<" ";
        }
        ast_count -=2*t;
        std::cout<<std::endl;
    }
}


unsigned int log10(unsigned int n){
    assert(n!=0);
    unsigned int exponent{0};
    while(n>=10){
        n/=10;
        exponent++;
    }
    return exponent;
}

unsigned int count(unsigned int n, unsigned int bit){
    //int n = 5678 (110110), bit = 1
    assert(bit==1||bit==0);
    int bit_count{0};
    for(int i=0;i<32;i++){
        if ((n&1) == bit){
            bit_count ++;
        }
        n>>=1; //shift one right
    }
    return bit_count;
}

unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1){
    assert((0<=b0 && b0<=3) && (0<=b1&& b1<=3));
    if(b0==b1){
        return n;
    }
    else{
    unsigned int b0mask{0xFFu<<(b0*8)}; //8 bits = 1
    unsigned int b0_chunk = b0mask&n;
    b0_chunk>>=(b0)*8; //set back to right side
    b0_chunk<<=(b1)*8;

    unsigned int b1mask{0xFFu<< b1*8};
    unsigned int b1_chunk = b1mask&n;
    b1_chunk >>=(b1)*8;
    b1_chunk<<=(b0*8);

    unsigned int new_n = n &~(b0mask|b1mask);
    new_n= (new_n|b0_chunk|b1_chunk);

    return new_n;
    }
}
int main(){
    std::cout<<count(0x61a84ab, 0);
    return 0;
}
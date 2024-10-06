//done in online compiler, may not work as expected
#include "grains.h"
#include <stdio.h>
uint64_t square(uint8_t index);
uint64_t total();
uint64_t square(uint8_t index){
    if( (index<1) || (index>64) ){
        return 0;
    }
    return (uint64_t)1 << (index - 1);
}
uint64_t total(){
    uint64_t result = 0;
    for(int i = 1; i<=64;i++){
        result +=square(i);
    }
    return result;
}

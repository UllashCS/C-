#include"MathOpsC.hpp"
#include"UtilsC.hpp"
#include "iostream"

#define memset fake_memset

int MultForOddAddForEven (int num) {
    if ((num > 0) && (num < 10)){
        if (0 == num%2){
            return AddoToN (num);
        }
        else{
            return Fact(num);
        }
    }
    else{
        return 0;
    }
}

void testMemset () {
    int *a = (int*) malloc(10 * sizeof(int));
    int i = 0;

    memset (a, 0x5, 10 * sizeof(int));

    printf ("\n");
    for (i = 0; i<10; i++) {
        printf ("0x%x ", a[i]);
    }

    printf ("\n");
}
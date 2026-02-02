#include <stdio.h>

int add(int a, int b){
    return a+b;
}

int main(void){
    int (*pf)(void) = (int (*)(void))add;
    int result = pf();

    printf("result = %d\n", result);
    return 0;
}

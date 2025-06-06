#include <stdio.h>

void swapStr(char ** a, char ** b);

int main(void){
    char* str1 = "ABC";
    char* str2 = "123";
    printf("str1=%s, str2=%s\n", str1, str2);

    swapStr(&str1, &str2);

    printf("str1=%s, str2=%s\n", str1, str2);

    return 0;
}
void swapStr(char ** a, char ** b){
    char * cp_tmp;
    cp_tmp = *a;
    *a = *b;
    *b = cp_tmp;
}

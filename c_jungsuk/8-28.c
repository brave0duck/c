#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void repeat(unsigned n, int (*pf)(const char*, ...), const char* str);

int main(void){
    char* strArr[]={"bird","tiger", "cat", "dog", "lion","mouse"};
    int sLen = sizeof(strArr) /  sizeof(char*);

    printf("strArr = %ld, char* = %ld, sLen = %d\n\n" , sizeof(strArr), sizeof(char*), sLen);

    repeat(10, printf, "Test...\n");

    return 0;
}
void repeat(unsigned n, int (*pf)(const char*, ...), const char* str){
    for(int i=0; i<n; i++)
        pf(str);
}
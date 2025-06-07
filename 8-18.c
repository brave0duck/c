/**
 * quiz8-6
 * 지정된 문자열을 대문자로 변환하여 반환하는 함수 toUpperCase()를 작성하시오
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* toUpperCase(char* src);

int main(void){
    char * cp1, *cp2;

    cp1 = toUpperCase("abc");
    cp2 = toUpperCase("a1b2c3");
    printf("%s -> %s\n", "abc", cp1);
    printf("%s -> %s\n", "abc", cp2);;

    free(cp1);
    free(cp2);
    return 0;

}
char* UpperCase(char* src){
    
    if(src==NULL)
        return 0;
    int len = strlen(src)+1;
    char * pstr = (char*)malloc(len*sizeof(char));
    char * position = pstr;

    while(*src){
        if('a' <= *src && *src <= 'z')
            *position++ = (*src++) + ('a' - 'A');
        else
            *position++ = *src++;
    }
    *position = '\0';

    return pstr;
}
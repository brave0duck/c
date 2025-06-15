/**
 * 1. 문자열 치환 구현 (Edit - Replace)
 *      1.원본 문자열에서 2.찾을 문자열을 3.새로운 문자열로 교체한다
 * 2. char* strReplace(char* src, char* old, char* new);
 * 3. 알고리즘
 *      3-1. dst = 충분한 메모리공간을 할당받는다. strlen(src)x2 
 *      3-2. src문자열이 널까지 반복. 
 *              3-2-1. 문자열을 찾는다 
 *                  3-2-1-1. 찾았다면 . 그이전 문자열을 dst에 저장 -> 그 뒤에 new문자열 추가 ->원본 문자열의 위치를 old만큼 이동하고 그 위치를 기록
 *                  3-2-1-2. 못찾으면 계속 반복
 *  ex) src = "aabbccbbaa" old="bb" new="111"
 *1. 위치저장용 변수  int pos;
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* strReplace(char* src, char* old, char* new){
    char* p = calloc(sizeof(src),sizeof(char));
    if(p==NULL)
        return NULL;
    
    int old_len = strlen(old);
    int new_len = strlen(new);

    char* find_str =0;   // 찾은곳의 위치 저장
    char* p_tmp=p;
    int size=0;


    while(find_str = strstr(src,old)){
        size = find_str - src;
        strncpy(p_tmp,src,size);
        
        strcat(p_tmp,new);

        src += size + old_len;
        p_tmp += size + new_len;

    }
    return p;
}

int main(void){
    char* src = "aabbccbbaa";

    char* p;
  
    printf("src = %s\n", src);
    printf("result = %s\n", p = strReplace(src,"bb","111"));
    free(p);
    printf("result = %s\n", p = strReplace(src,"cc",""));
    free(p);
    printf("result = %s\n", p = strReplace(src,"ff","00"));
    free(p);


    return 0;
}
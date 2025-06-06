/**
 * 1. 문자열을 입력받고
 * 2. 문자열중에 특별한 문자열이 있는지 확인
 * 3. 결과를 출력한다
 */
#include <stdio.h>
#include <string.h>

int strContaine(const char * p_str, const char * p_words);

int main(void){
    char s_input[100];
    char * keywords="judas";
    
    fputs("Input statment : ", stdout);
    scanf("%99[^\n]", s_input);
   

    if(strContaine(s_input, keywords))
        printf("find! [%s]\n", keywords);
    else
        printf("can't find keyword");

    return 0;
}
int strContaine(const char * p_str, const char *p_words){
    int check=0;    //  return value
    const char * find = p_words;    // save pointer start position
    while(*p_str)
    {
        while(*find)
        {    
            if(*find++ == *p_str++){ // All must match to complete
                check=1;    // during match keep 1;
            }
            else{
                check=0;      // If even one is wrong. break;
                find = p_words;    //initial pointer position
                break;
            }
        }
        if(check ==1)
            break;
    }
    return check;
}

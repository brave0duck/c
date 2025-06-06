/*
 *  stdio.h 의 대표적인 함수 3개를 직접 만들어보자
    1. strlen - 문자열의 길이를 구해서 반환
    2. strcpy - a문자열을 b문자열로 복사
    3. strcat - 두 문자열을 연결
 */
#include <stdio.h>

int zz_strlen(char * str);
char * zz_strcpy(char * dst, const char * src);
char * zz_strcat(char * dst, const char * src);

int main(void){
    char * src1 = "original statement.";
    char * src2 = "2th statement";
    char dst[100];

    printf("src1's length is %d\n", zz_strlen(src1));
    printf("src2's length is %d\n", zz_strlen(src2));

    printf("zz_strcpy result = dst[%s]\n", zz_strcpy(dst,src1));

    printf("zz_strcat = [%s]\n", zz_strcat(src1, src2));

    return 0;
}
int zz_strlen(char * str);
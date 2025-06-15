#include <stdio.h>
#include <errno.h>

int main(void){
    char* filename = "opentest.txt";

    FILE* fp = fopen(filename,"r");
    if(fp==NULL){
        printf("읽기모드로 파일[%s]열기 실패했습니다\n", filename);
        printf("errno is %d\n", errno);
    }
    else{
        printf("읽기모드로 파일[%s]열기 성공했습니다.\n", filename);
    }
    fp = fopen(filename,"w");
    errno=0;

    if(fp==NULL){
        printf("쓰기모드로 파일[%s]열기 실패했습니다\n", filename);
        printf("errno is %d\n", errno);
    }else{
        printf("쓰기모드로 파일[%s]열기 성공했습니다.\n", filename);
    }

    printf("FOPEN_MAX = %d\n", FOPEN_MAX);

    fclose(fp);
    printf("파일 [%s]을 닫습니다.\n", filename);

    return 0;
}
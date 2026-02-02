#include <stdio.h>
#include <string.h>

int main(void){
    char* file1 = "8-19.c";
    char keyword[50];
    char buffer[1024];
    int line, result=0;

    FILE* fp = fopen(file1,"r");
    if(fp==NULL){
        printf("can't open [%s]...\n", file1);
        return 1;
    }
    printf("input word for searching.>");
    scanf("%s", keyword);

    for(line=1; fgets(buffer, sizeof(buffer), fp); line++){
        if(strstr(buffer,keyword)){
            result++;
            printf("%3d : %s", line, buffer);
        }
    }

    printf("\n[%s]의 %d개 행에서 '%s'를 찾았습니다.\n", file1, result, keyword);

    fclose(fp);
    return 0;

}
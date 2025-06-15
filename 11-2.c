#include <stdio.h>

int main(void){
    char* file_one  = "aaa.txt";
    char* file_two = "bbb.txt";

    FILE* in_f = fopen(file_one, "r");
    FILE* out_f = fopen(file_two, "w");
    int ch=0;

    if(!in_f || !out_f){
        printf("can's open file\n");
        return 1;
    }
    printf("%s를 %s로 복사하겠습니다...\n", file_one, file_two);

    while((ch = fgetc(in_f)) != EOF)
        fputc(ch,out_f);

    if(ferror(in_f) || ferror(out_f))
        printf("error! fail file copy\n");
    else
        printf("copy success...\n");

    fclose(in_f);
    fclose(out_f);

    return 0;
}
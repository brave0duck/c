#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE* fp;
    char temp[100];
    char* file = "score.txt";

    printf("file open by text mode...\n");

    fp = fopen(file,"rt");
    if(fp==NULL){
        printf("can't open file %s\n", file);
        exit(1);
    }

    while(fgets(temp, sizeof(temp), fp)!=NULL)
        fputs(temp,stdout);
    fclose(fp);

    printf("file open by binary mode...\n");
    fp = fopen(file,"rb");
    if(fp==NULL){
        printf("can't open file %s\n", file);
        exit(1);
    }

    while(fgets(temp, sizeof(temp), fp)!=NULL)
        fputs(temp,stdout);
    fclose(fp);

    return 0;
}
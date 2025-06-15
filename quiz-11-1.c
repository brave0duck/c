#include <stdio.h>

int main(void){
    FILE * pf = fopen("opentest.txt", "w+");
    if(pf!=NULL)
        fputc(-1,pf);
    fclose(pf);
    
    return 0;
}
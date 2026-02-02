#include <stdio.h>

void printFileInfo(FILE* f){
    
    printf("_fileno=%d\n", f->_fileno);
    printf("_offset=%d\n", f->_offset);
    printf("_flag=%d\n", f->_flags);

}
int main(void){
    printf("[stdin]\n");
    printFileInfo(stdin);

    printf("[stdout]\n");
    printFileInfo(stdout);

    printf("[stderr]\n");
    printFileInfo(stderr);
    return 0;
}
#include <stdio.h>

int main(void)
{
    int score[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int (*ptr)[3] = score;
    int i,j;

    printf("ptr = %p\n", ptr);
    printf("*ptr 1= %p\n", *(ptr+1));
    printf("*ptr 2= %p\n", *(ptr+2));
    printf("*ptr 3= %p\n", *(ptr+3));

    printf("score size = %p\n", score);
    printf("*score = %p\n", *score);
    printf("\n"); 
    printf("sizeof(score) = %zu byte\n", sizeof(score));
    printf("sizeof(*score) = %zu byte\n", sizeof(*score));
    printf("sizeof(score[0]) = %zu byte\n", sizeof(score[0]));
    printf("sizeof(score[0][0]) = %zu byte\n", sizeof(score[0][0]));

    return 0;
}
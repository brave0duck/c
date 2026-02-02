/**
 * 확률 rand() / (double)RAND_MAX1 > percent/(double)100.0
 * ex) 0.56 > 0.25 ? 1: 0;
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int attack(int percent){
    return (rand()%100 < percent ? 1:0);

}
int main(void){
    int i;
    int sum=0;

    srand((unsigned)time(NULL));

    for(i=0; i<1000;i++){
        
        if(attack(50)){
            printf("1");
            sum++;
        }
        else{
            printf("0");
        }
    }
    printf("\n100번중 %d번 이겼습니다", sum);

    return 0;
}
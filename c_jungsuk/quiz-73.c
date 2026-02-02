#include <stdio.h>

int main(void){
    int arr[] = {1,2,3,4,5,6};
    int *ptr = &arr[0];
    const int total = sizeof(arr) / sizeof(arr[0]);
    int sum=0;

    for(int i=0; i < total; i++){
        sum += *ptr++;
    }
    printf("sum=%d\n", sum);
    printf("avg=%lf\n", (double)sum/total);

    return 0;
}
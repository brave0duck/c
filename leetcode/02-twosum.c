/*   two sum ; single linked list - stack
*   1. 1배열 2배열을 차례로 스택에 넣는다
    2. 하나씩 꺼내서 숫자를 만들고 더하기로 최종수를 구함
    3. 최종수를 스택에 넣고 하나씩 꺼내 링크드 리스트로 완성
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Init_Stack(Stk *s, int n){
    s->pstack = (int*)calloc(n,sizeof(int));
    if(s->pstack == NULL){
        return -1;
    }
    s->max = n;
    s->ptr=0;
}
int Push_Stack(Stk *s,int data){
    if(s->ptr > s->max){
        return -1;
    }
    s->pstack[s->ptr++] = data;
}
int Pop_Stack(Stk *s){
    if(s->ptr <= 0){
        return -1;
    }
    return s->pstack[--s->ptr];
}
int Terminate(Stk *s){
    if(s->pstack != NULL){
        free(s->pstack);
    }
    s->max=0;
    s->ptr;
}
int numbers_of_digits(int n){
    if(n<0)
        return -1;
    int result=0;
    int count=1;
    while(1){
        if( 1 > (n / pow(10,count))){
            return count;
        }
        count++;
    }
}
int main(void){
    int result=0;    int data=0;
    int * final_arr;
    int nDigit;

//    int l1[]={2,4,3};
//    int l1[] = {9,9,9,9,9,9,9,9};
    int l1[] = {0};

//    int l2[] = {5,6,4};
    int l2[] = {0};
//    int l2[] = {9,9,9,9};

    int one_size = sizeof(l1)/sizeof(l1[0]);
    int two_size = sizeof(l2)/sizeof(l2[0]);
    int total_size = one_size > two_size ? one_size: two_size;
    
    Stk s1, s2, s3 ;
    Init_Stack(&s1,one_size);
    Init_Stack(&s2,two_size);
    // 1
    for(int i=0; i<one_size ; i++){
        Push_Stack(&s1,l1[i]);
    }
    for(int i=0; i<two_size ; i++){
        Push_Stack(&s2,l2[i]);
    }
    // 2
    while( total_size){
        int number=0;
        if (total_size == s1.ptr){
            data = Pop_Stack(&s1);
            if( data != -1)
                number += data;
        }
        if(total_size == s2.ptr){
            data = Pop_Stack(&s2);
            if( data != -1)
                number += data;
        }
        number *= pow(10,(total_size-1));

        result += number;
        total_size--;
    }
    //3
    nDigit = numbers_of_digits(result); // 자릿수가 몇인지 체크하는 함수
    final_arr = (int *)calloc(nDigit,sizeof(int));
    for(int i=0; i< nDigit; i++){
        int r = result % (int)(pow(10,1));
        final_arr[i] = r;
        result /= (int)(pow(10,1));
    }
    for(int i=0; i<nDigit ; i++){
        printf("number  is %d\n", final_arr[i]);
    }
    
    free(final_arr);
    Terminate(&s1);
    Terminate(&s2);

    return 0;
}
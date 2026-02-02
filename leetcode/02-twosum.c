/*   two sum ; single linked list - stack
*   1. 1배열 2배열을 차례로 스택에 넣는다
    2. 하나씩 꺼내서 숫자를 만들고 더하기로 최종수를 구함
    3. 최종수를 스택에 넣고 하나씩 꺼내 링크드 리스트로 완성
*/
#include <stdio.h>
#include <stdlib.h>
#define _MAX_ 100

typedef struct n{
    int data;
    int * pNext;
}Node;

typedef struct ll{
    int max;
    Node * pNode;
}sll;

typedef struct stack{
    int ptr;
    int * pstack;
}Stk;

int Init_Stack(Stk *s, int n){
    s->pstack = (int*)calloc(n,sizeof(int));
    if(s->pstack == NULL){
        return -1;
    }
    s->ptr=0;
}
int Push_Stack(Stk *s,int data){
    if(s->ptr >= _MAX_){
        return -1;
    }
    s->pstack[s->ptr++];
}
int Pop_Stack(Stk *s,int *data){
    if(s->ptr >= 0){
        return -1;
    }
    *data = s->pstack[s->ptr];
    s->ptr--;
}
int main(void){
    int one_size, two_size;
    int l1[] = {2,4,3};
    int l2[] = {5,6,4};

    Stk *s1, *s2 ;
    InitStack(s1,_MAX_);
    InitStack(s2,_MAX_);

    for(int i=0; i<sizeof(l1); i++){
        Push_Stack(s1,l1[i]);
    }
    for(int j=0; j<sizeof(l2); j++){
        Push_Stack(s2,l2[i]);
    }
    one_size = s1->ptr+1;
    two_size = s2->ptr+1;

    while( one_size - two_size > 0 ? one_size-- : two_size--){
        int 
    }

    return 0;
}
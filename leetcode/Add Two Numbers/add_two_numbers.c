#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct linkedlist{
    struct ListNode * phead;
    int size;
}sll;

int numbers_of_digits(int n){   //숫자의 총 자릿수를 리턴 . 4828 = 4, 987 = 3 , 23 = 2
    if(n<0)
        return -1;
    
    int count=1;
    while(1){
        if( 1 > (n / pow(10,count))){
            break;
        }
        count++;
    }
    return count;
}
void Init(sll *pll){
    pll->phead=NULL;
    pll->size=0;
}
int IsEmpty(sll *pll){
    return pll->phead == NULL;
}
void Add(sll * pll,int data){
    if(IsEmpty(pll)){
        pll->phead = calloc(1,sizeof(int));
        pll->phead->val = data;
        pll->phead->next = NULL;
    }else{
        struct ListNode *p = pll->phead;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = calloc(1,sizeof(int));
        p->next->val = data;
        p->next->next = NULL;
    }
    pll->size++;
}
void Clear(sll *pll){
    struct ListNode * p;
    while(pll->phead != NULL){
        p = pll->phead->next;
        free(pll->phead);
        pll->phead = p;
    }
    pll->phead = NULL;
    pll->size=0;
    
}
struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2) {
    int one_size=0;int two_size=0; int total_size=0;
    int one_number,two_number;
    int result=0;
    struct ListNode *p1, *p2;
    sll * pll;

    p1=  l1;
    p2 = l2;

    while(p1 != NULL && p2 != NULL){
        if(p1 != NULL){
            one_number = p1->val * pow(10,one_size);
            one_size++;
            p1 = p1->next;
        }else{
            one_number =0;
        }
        if(p2 != NULL){
            two_number = p2->val * pow(10,two_size);
            two_size++;
            p2 = p2->next;
        }else{
            two_number=0;
        }
        result += one_number + two_number;
    }
    total_size = numbers_of_digits(result);

    Init(pll);
    for(int i=0; i< total_size; i++){
        int r = result % (int)(pow(10,1));
        Add(pll,r);
        result /= (int)(pow(10,1));
    }
    return pll->phead;

}

int main(void){

    sll s1,s2,s3;
    struct ListNode *l3;
    
    Init(&s1);
    Init(&s2);

    Add(&s1,2);
    Add(&s1,4);
    Add(&s1,3);
    Add(&s2,5);
    Add(&s2,6);
    Add(&s2,4);

    s3.phead = addTwoNumbers(s1.phead,s2.phead);
    l3 = s3.phead;

    while(l3 != NULL){
        printf("%d ",l3->val);
        l3 = l3->next;
    }
    Clear(&s1);
    Clear(&s2);
    Clear(&s3);
}
// 807 = {7,0,8}
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void Add(struct ListNode *lst, int data){
    struct ListNode *p = lst;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = calloc(1,sizeof(int));
    p->next->val = data;
    p->next->next = NULL;
}
void Clear(ListNode *lst){
    struct ListNode * p = lst;
    struct ListNode * tmp;
    while(p->next != NULL){
        tmp = p->next;
        free(p);
        p=tmp;
    }
    if(p != NULL){
        free(p);
    }
    }
}
struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2) {
    int one_size=0;int two_size=0;
    int one_number,two_number;
    int result;
    struct ListNode *p1, *p2;


    p1=  l1;
    p2 = l2;

    while(p1 != NULL && p2 != NULL){
        if(p1 != NULL){
            one_number = p1->val *(10*one_size);
            one_size++;
            p1 = p1->next;
        }else{
            one_number =0;
        }
        if(l2 != NULL){
            two_number = p2->val * (10*two_size);
            two_size++;
            p2 = p2->next;
        }else{
            two_number=0;
        }
        result += one_number + two_number;
    }

}
int main(void){
    struct ListNode l1,l2,l3;
    Init(&l1);
    Init(&l2);

    Add(&l1,2);
    Add(&l1,4);
    Add(&l1,3);
    Add(&l2,5);
    Add(&l2,6);
    Add(&l2,4);


    Clear(&l1);
    Clear(&l1);
    Clear(&l1);
}
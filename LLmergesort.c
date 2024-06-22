#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
};
struct node *createnode(int d){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    return temp;
}
struct node *mid(struct node *h){
    if (h==NULL || h->next==NULL){
        return h;
    }
    struct node *slow;
    struct node *fast;
    slow=h;
    fast=h;
    while(fast->next->next!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
struct node *merge(struct node *a,struct node *b){
    struct node *ans;
    if (a==NULL){
        return b;
    }
    if (b==NULL){
        return a;
    }
    if (a->data<=b->data){
        ans = createnode(a->data);
        ans->next = merge(a->next,b);
    }
    else{
        ans = createnode(b->data);
        ans->next = merge(a,b->next);
    }
    return ans;
}
struct node *mergesort(struct node *h){
    if (h == NULL || h->next == NULL){
        return h;
    }
    struct node *middle = mid(h);
    struct node *middlenext = middle->next;
    middle->next = NULL;
    struct node *a = mergesort(h);
    struct node *b = mergesort(middlenext);
    struct node *c = merge(a,b);
    return c;
}
void printll(struct node *n){
    printf("[ ");
    while (n!=NULL){
        printf("%d, ",n->data);
        n=n->next;
    }
    printf("]");
}
void main(){
    struct node *new = createnode(10);
    new->next = createnode(1);
    new->next->next = createnode(5);
    new->next->next->next = createnode(7);
    new->next->next->next->next = createnode(2);
    printf("Before Sorting: ");
    printll(new);
    // [10, 1, 5, 7, 2]
    struct node *f = mergesort(new);
    printf("\nAfter Sorting: ");
    printll(f);
}
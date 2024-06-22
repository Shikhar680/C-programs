#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertBefore(struct node **head_ref, struct node *next_node, int data) {
    if (*head_ref == NULL || next_node == NULL) {
        printf("Invalid insertion\n");
        return;
    }
    struct node *newNode = createNode(data);
    newNode->next = next_node;
    if (*head_ref == next_node) {
        *head_ref = newNode;
    } else {
        struct node *current = *head_ref;
        while (current->next != next_node) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void insertAfter(struct node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Invalid insertion\n");
        return;
    }
    struct node *newNode = createNode(data);
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}
void insertAtBeginning(struct node **head_ref, int data) {
    struct node *newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    newNode->next = *head_ref;
    *head_ref = newNode;
}
void insertAtEnd(struct node **head_ref, int data) {
    struct node *newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}
void insertAtIndex(struct node **head_ref, int index, int data) {
    if (index < 0) {
        printf("Invalid index\n");
        return;
    }
    if (index == 0) {
        struct node *newNode = createNode(data);
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }
    struct node *current = *head_ref;
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid index\n");
        return;
    }
    struct node *newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
}
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void freeList(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void ins(struct node **head,int d){
    int ch;
    printf("Enter 0 for insert at beginning\n1 for insert at end\n2 for insert at index:");
    scanf("%d",&ch);
    if (ch==0){
        insertAtBeginning(head,d);
    }
    else if (ch==1){
        insertAtEnd(head,d);
    }
    else if (ch==2){
        printf("No function");
    }
}
void deleteHead(struct node **head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}
void deleteNodeByValue(struct node **head_ref, int key) {
    struct node *temp = *head_ref, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void deleteNodeByIndex(struct node **head_ref, int index) {
    struct node *temp = *head_ref, *prev = NULL;
    if (temp != NULL && index == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    int i = 0;
    while (temp != NULL && i < index) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void del(struct node **head){
    printf("Enter 0 for deleting head\n1 for deleting by index\n2 for deleting by value: ");
    int ch;
    scanf("%d",&ch);
    if(ch == 0){
        deleteHead(head);
    }
    else if(ch == 1){
        int i;
        printf("Enter index: ");
        scanf("%d",&i);
        deleteNodeByIndex(head,i);
    }
    else if(ch == 2){
        int v;
        printf("Enter value: ");
        scanf("%d",&v);
        deleteNodeByValue(head,v);
    }
}
void main() {
    struct node *head = NULL;
    int ch,d;
    while (1<2){
        printf("Enter\n0 to insert\n1 to delete\n2 to print\n3 to exit: ");
        scanf("%d",&ch);
        switch(ch){
            case 0: printf("Enter the data: ");
                    scanf("%d",&d);
                    ins(&head,d);
                    break;
            case 1: del(&head);
                    break;
            case 2: printList(head);
                    break;
            case 3: freeList(head);
                    exit(0);
            default: printf("Enter proper choice: ");
        }
    }
    freeList(head);
}
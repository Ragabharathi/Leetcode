#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void push(struct Node **head,int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
    }else{
        newNode->next=*head;
        *head=newNode;
    }
}
void pop(struct Node **head){
    if(*head==NULL){
        printf("No elements to pop\n");
    }
    else{
        struct Node *temp=*head;
        *head=temp->next;
        free(temp);
    }
}
void peek(struct Node *head){
    if(head==NULL){
        printf("No Elements\n");
    }
    else{
        printf("The peek element is %d\n",head->data);
    }
}
void display(struct Node *head){
     if(head==NULL){
        printf("stack empty\n");
    }else{
        struct Node *temp=head;
        printf("The elements in stack are ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    struct Node *head=NULL;
    int data,ch;
    while(1){
        printf("\nEnter the choice\n1.push\n2.pop\n3.peek\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the data\n");
            scanf("%d",&data);
            push(&head,data);
            break;
            case 2:
            pop(&head);
            break;
            case 3:
            peek(head);
            break;
            case 4:
            exit(0);
        }
        display(head);
       
    }
    

    return 0;
}

#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev,*next;
};
struct Node *head,*tail;
struct Node* createNewNode(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void insertAtLast(int data){
    struct Node *newNode=createNewNode(data);
    if(head==NULL){
        head=tail=newNode;
    }else{
       tail->next=newNode;
       newNode->prev=tail;
       tail=newNode;
    }
    tail->next=head;
}
void reverse(){
    struct Node *curr=head;
    struct Node *prevnode;
    struct Node *nextnode=curr->next;
    while(curr!=tail){
        prevnode=curr;
        curr=nextnode;
        nextnode=curr->next;
        curr->next=prevnode;
        curr->prev=nextnode;
    }
    head=curr;
    nextnode->next=tail;
    nextnode->prev=prevnode;
    tail=nextnode;
}

void display(){
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else{
        struct Node *temp=head;
        printf("The reversed elements in list are: ");
        while(temp->next!=head){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}

int main(){
    int data,n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        insertAtLast(data);
    }
    reverse();
    display();
    return 0;
}

#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev,*next;
};
struct Node *head;
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
        head=newNode;
    }else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}
void display(){
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else{
        struct Node *temp=head;
        printf("The reversed list : ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void reverse(){
    struct Node *current=head,*nextNode;
    while(current!=NULL){
        head=current;
        nextNode=current->next;
        current->next=current->prev;
        current->prev=nextNode;
        current=nextNode;
    }
    
    
}
int main(){
    int n,data,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the data\n");
    for(i=0;i<n;i++){
        scanf("%d",&data);
        insertAtLast(data);
    }
    reverse();
    display();
    return 0;
}

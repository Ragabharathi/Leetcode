#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *tail;
struct Node *createNode(){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->next=NULL;
    return newNode;
}

void insertAtLast(struct Node **head,int data){
    struct Node *new_node=createNode();
    new_node->data=data;
    if(*head==NULL){
        *head=tail=new_node;
    }
    else{
        tail->next=new_node;
        tail=new_node;
    }
    tail->next=*head;
}

void display(struct Node *head){
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else{
        printf("The elements in list are: ");
        struct Node *temp=head;
        while(temp->next!=head){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}
void reverse(struct Node **head)
{
    struct Node *curr=*head;
    struct Node *prev;
    struct Node *next=curr->next;
    while(curr!=tail){
        prev=curr;
        curr=next;
        next=curr->next;
        curr ->next=prev;
    }
    *head=curr;
    next->next=tail;
    tail=next;
}
int main(){
    int data,pos,choice;
    struct Node *head=NULL;
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insertAtLast(&head,data);
    }
    reverse(&head);
    display(head);
    return 0;
}

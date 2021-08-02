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
void insertAtBegining(int data){
    struct Node *newNode=createNewNode(data);
    if(head==NULL){
        head=tail=newNode;
    }else{
       newNode->next=head;
       head->prev=newNode;
       head=newNode;
    }
       tail->next=head;
    
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
void insertAtMiddle(int data,int pos){
    if(pos==1){
       insertAtBegining(data);
    }else if(head==NULL && pos>1){
        printf("Cant insert\n");
    }else{
        struct Node *newNode=createNewNode(data);
        int count=1;
        struct Node *temp=head;
        while(temp->next!=head){
            if(count==pos-1){
                temp->next->prev=newNode;
                newNode->next=temp->next;
                temp->next=newNode;
                newNode->prev=temp;
                break;
            }
            count++;
            temp=temp->next;
        }
     if(count==pos-1){
               insertAtLast(data);
            }
    }
    
}
void display(){
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else{
        struct Node *temp=head;
        printf("The elements in list are: ");
        while(temp->next!=head){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}

int main(){
    int data,pos,choice;
    while(1){
       
        printf("Enter the data to be inserted:\n");
        scanf("%d",&data);
         printf("\nEnter the choice to insert:\n1.Begining\n2.Last\n3.Middle\n4.exit\n");
        scanf("%d",&choice);
       switch(choice){
            case 1:
            insertAtBegining(data);
            break;
            case 2:
            insertAtLast(data);
            break;
            case 3:
            printf("Enter the position:\n");
            scanf("%d",&pos);
            insertAtMiddle(data,pos);
            break;
            case 4:
            exit(0);
        }
        display();
    }
    return 0;
}

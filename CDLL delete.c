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

void deleteAtBegining(){
    if(head==NULL){
        printf("List Underflow\n");
    }else if(head->next==head){
        head=NULL;
        free(head);
    }
      else{
      struct Node *temp=head;
      head=head->next;
      head->prev=tail;
      tail->next=head;
      free(temp);
    }
}
void deleteAtLast(){
    if(head==NULL){
        printf("List Underflow\n");
    }else if(head->next==head){
        head=NULL;
        free(head);
    }
    else{
      struct Node *temp=tail;
      tail=tail->prev;
      tail->next=head;
      head->prev=tail;
      free(temp);
    }
}
void deleteAtMiddle(int pos){
    
    if(head==NULL)
    {
        printf("List is empty\n");
    }else if(pos==1){
        deleteAtBegining();
    }
    else{
        struct Node*temp=head;
        int c=1;
        while(temp->next!=head){
            if(c==pos){
                if(temp->next==head){
                    deleteAtLast();
                }
                else{
               temp->next->prev=temp->prev;
               temp->prev->next=temp->next;
                }
                break;
            }
            c++;
            temp=temp->next;
        }
        if(c==pos){
deleteAtLast();
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
    int data,pos,choice,n,i;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%d",&data);
    insertAtLast(data);
    }
  
    while(1){
       
       printf("\nEnter the choice to delete:\n1.Begining\n2.Last\n3.Middle\n4.exit\n");
       scanf("%d",&choice);
       switch(choice){
            case 1:
            deleteAtBegining();
            break;
            case 2:
            deleteAtLast();
            break;
            case 3:
            printf("Enter the position:\n");
            scanf("%d",&pos);
           deleteAtMiddle(pos);
            break;
            case 4:
            exit(0);
        }
        display();
    }
    return 0;
}

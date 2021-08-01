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
void insertAtBegining(struct Node **head,int data){
    struct Node *new_node=createNode();
    new_node->data=data;
    if(*head==NULL){
        *head=tail=new_node;
    }
    else{
        new_node->next=*head;
        *head=new_node;
    }
    tail->next=*head;
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
void insertAtMiddle(struct Node **head,int data,int pos){
    struct Node *new_node=createNode();
    new_node->data=data;
     struct Node *temp=*head;
     int c=1;
     if(pos==1){
         if(*head==NULL){
             *head=tail=new_node;
             tail->next=*head;
         }else{
         new_node->next=*head;
         *head=new_node;
        }
     }
     else if(*head==NULL && pos>1){
         printf("Cant able to insert\n");
     }
     else{
         while(temp->next!=*head)
         {
             if(c==pos-1)
             {
         new_node->next=temp->next;
         temp->next=new_node;
         break;
             }
             else{
                 temp=temp->next;
             }
             c++;
         }
             
     }
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

int main(){
    int data,pos,choice;
    struct Node *head=NULL;
    while(1){
       
        printf("Enter the data to be inserted:\n");
        scanf("%d",&data);
         printf("\nEnter the choice to insert:\n1.Begining\n2.Last\n3.Middle\n4.exit\n");
        scanf("%d",&choice);
       switch(choice){
            case 1:
            insertAtBegining(&head,data);
            break;
            case 2:
            insertAtLast(&head,data);
            break;
            case 3:
            printf("Enter the position:\n");
            scanf("%d",&pos);
            insertAtMiddle(&head,data,pos);
            break;
            case 4:
            exit(0);
        }
        display(head);
    }
    return 0;
}

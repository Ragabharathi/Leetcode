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
void deleteAtBegining(struct Node **head){
    struct Node *temp=*head;
    if(*head==NULL){
        printf("List is empty\n");
    }else if(temp->next==*head){
        *head=NULL;
    }
    else{
        struct Node *temp=*head;
        *head=temp->next;
        tail->next=*head;
        free(temp);
    }
}
void deleteAtLast(struct Node **head){
    if(*head==NULL){
        printf("List is Empty\n");
    }
    else if((*head)->next==*head){
        *head=NULL;
    }
    else{
        struct Node *temp=*head;
       while(temp->next->next!=*head){
           temp=temp->next;
       }
       temp->next=*head;
       tail=temp;
    }
}
void deleteAtMiddle(struct Node **head,int pos){
    if(*head==NULL){
        printf("List is empty\n");
    }
    else if(pos==1){
        struct Node *temp=*head;
        *head=(*head)->next;
        tail->next=*head;
        free(temp);
    }
    else{
        int c=1;
        struct Node *temp=*head;
        while(temp->next!=*head){
            if(c==pos-1){
                temp->next=temp->next->next;
                break;
            }
            c++;
            temp=temp->next;
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
    int data,pos,choice,n,i;
    struct Node *head=NULL;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%d",&data);
    insertAtLast(&head,data);
    }
    while(1){
       
       
         printf("\nEnter the choice to delete:\n1.Begining\n2.Last\n3.Middle\n4.exit\n");
        scanf("%d",&choice);
       switch(choice){
            case 1:
            deleteAtBegining(&head);
            break;
            case 2:
            deleteAtLast(&head);
            break;
            case 3:
            printf("Enter the position:\n");
            scanf("%d",&pos);
           deleteAtMiddle(&head,pos);
            break;
            case 4:
            exit(0);
        }
        display(head);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *createNode(){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->next=NULL;
    return newNode;
}

void insertAtLast(struct Node **head,int data){
    struct Node *new_node=createNode();
    new_node->data=data;
    if(*head==NULL){
        *head=new_node;
    }
    else{
        struct Node *temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
void deleteAtBegining(struct Node **head){
    if(*head==NULL){
        printf("List is empty\n");
    }
    else{
        struct Node *temp=*head;
        *head=temp->next;
        free(temp);
    }
}
void deleteAtLast(struct Node **head){
    if(*head==NULL){
        printf("List is Empty\n");
    }
    else if((*head)->next==NULL){
        *head=NULL;
    }
    else{
        struct Node *temp=*head;
       while(temp->next->next!=NULL){
           temp=temp->next;
       }
       temp->next=NULL;
    }
}
void deleteAtMiddle(struct Node **head,int pos){
    if(*head==NULL){
        printf("List is empty\n");
    }
    else if(pos==1){
        struct Node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    else{
        int c=1;
        struct Node *temp=*head;
        while(temp->next!=NULL){
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
        while(head!=NULL){
            printf("%d ",head->data);
            head=head->next;
        }
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

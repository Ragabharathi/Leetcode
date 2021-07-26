#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
 struct Node *front=NULL;
 struct Node *rear=NULL;
 void enqueue(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
}
void dequeue(){
    if(front==NULL && rear==NULL){
        printf("Queue empty\n");
    }
    else{
        struct Node *temp=front;
        front=front->next;
        if(front==NULL)
        rear=NULL;
        free(temp);
    }
}
void peek(){
     if(front==NULL && rear==NULL){
        printf("Queue empty\n");
    }else{
        printf("The peek element: %d\n",front->data);
    }
}
void display(){
     if(front==NULL && rear==NULL){
        printf("Queue empty\n");
    }else{
        struct Node *temp=front;
        printf("The Queue elements are ");
       while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
       }
        printf("\n");
    }
    
}


int main()
{
  
    int data,ch;
    while(1){
        printf("\nEnter the choice\n1.Enqueue\n2.Dequeue\n3.peek\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the data\n");
            scanf("%d",&data);
            enqueue(data);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            peek();
            break;
            case 4:
            exit(0);
        }
    
        display();
    }
      return 0;
    
}

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define size 10
int deq[size];
int front =-1, rear =-1;
void insert_front(int x){
    if((front==0 && rear ==size-1)||(front==rear+1)){
        printf("Overflow");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        deq[front]=x;
    }
    else if(front==0){
        front=size-1;
        deq[front]=x;
    }
    else{
        front--;
        deq[front]=x;
    }
}
void insert_rear(int x){
     if((front==0 && rear ==size-1)||(front==rear+1)){
        printf("Overflow");
    }
     else if(front==-1 && rear==-1){
        front=rear=0;
        deq[front]=x;
    }
    else if(rear==size-1){
        rear=0;
        deq[rear]=x;
    }
    else{
        rear++;
        deq[rear]=x;
    }
}
void delete_front(){
    if(front==-1 && rear==-1){
        printf("Underflow");
    }
    else if(front == rear){
        printf("%d ",deq[rear]);
        front=rear=-1;
    }
    else if(front==size-1){
       printf("%d ",deq[front]);
       front=0;
    }
    else{
        printf("%d ",deq[front]);
        front++;
    }
}
void delete_rear(){
    if(front==-1 && rear==-1){
        printf("Underflow");
    }
    else if(front == rear){
        printf("%d ",deq[rear]);
        front=rear=-1;
    }
    else if(rear==0){
        printf("%d ",deq[rear]);
        rear=size-1;
    }
    else{
        printf("%d ",deq[rear]);
        rear--;
    }
}
void display(){
    int i=front;
    while(i!=rear){
        printf("\n%d ",deq[i]);
        i=(i+1)%size;
    }
    printf("\n%d ",deq[rear]);
}

int main()
{
    insert_front(10);
    insert_front(20);
    insert_rear(40);
    insert_rear(50);
    delete_front();
    insert_rear(70);
    delete_rear();
    display();

    return 0;
}

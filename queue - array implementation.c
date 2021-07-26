#include <stdio.h>
#define N 100
int queue[N],front=-1,rear=-1;
void enqueue(int x){
    if(rear==N-1){
        printf("Queue overflow\n");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
         queue[rear]=x;
    }else{
        rear++;
         queue[rear]=x;
    }
   
}
void dequeue(){
    if(front==-1 && rear==-1){
         printf("Queue underflow\n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("The dequeue element is %d\n",queue[front++]);
    }
    
}
void peek(){
     if(front==-1 && rear==-1){
         printf("Queue underflow\n");
    }else{
        printf("The peek element is %d\n",queue[front]);
    }
}
void display(){
    if(front==-1 && rear==-1){
         printf("Queue underflow\n");
    }
    else{
        printf("The queue is ");
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    enqueue(1);
    enqueue(2);
    dequeue();
    peek();
    display();
    enqueue(6);
    enqueue(7);
    peek();
    dequeue();
    display();

    return 0;
}

#include <stdio.h>
#define N 5
int s1[N],s2[N];
int top1=-1,top2=-1,count=0;
int enqueue(int);
int dequeue();
int display();
int main()
{
    enqueue(2);
    enqueue(-1);
    display();
    dequeue();
    enqueue(5);
    enqueue(7);
    display();
    dequeue();
    display();

    return 0;
}
int push1(int data){
    if(top1==N-1){
        printf("Queue overflow");
    }else{
        s1[++top1]=data;
    }
}
int push2(int data){
    if(top2==N-1){
        printf("Queue overflow");
    }else{
        s2[++top2]=data;
    }
}
int enqueue(int x){
    push1(x);
    count++;
}
int pop1(){
    return s1[top1--];
}
int pop2(){
    return s2[top2--];
}
int dequeue(){
    int i,a,b;
    if(top1==-1 && top2==-1){
        printf("Queue underflow");
    }else{
        for(i=0;i<count;i++){
            a=pop1();
            push2(a);
        }
        b=pop2();
        printf("\nThe dequeue element is %d\n",b);
        count--;
        for(i=0;i<count;i++){
            a=pop2();
            push1(a);
        }
    }
}
int display(){
    int i;
    printf("The queue is ");
    for(i=0;i<=top1;i++){
        printf("%d ",s1[i]);
    }
}

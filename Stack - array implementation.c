#include <stdio.h>
#define MAX 100
int arr[MAX],top=-1;
void push(int x){
    if(top==MAX-1){
        printf("Stack Overflow");
    }
    else{
        arr[++top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    else{
        top--;
    }
}
void peek(){
     if(top==-1){
        printf("Stack Underflow");
    }
    else{
        printf("Peek element is %d\n",arr[top]);
    }
}
void display(){
     if(top==-1){
        printf("Stack Underflow");
    }
    else{
        printf("Stack elements are ");
        for(int i=0;i<=top;i++){
            printf("%d ",arr[i]);
        }
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    pop();
    push(4);
    peek();
    pop();
    display();
    return 0;
}

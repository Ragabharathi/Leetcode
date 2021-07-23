#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int arr[MAX],size=0;
void append(int data){
    arr[size++]=data;
}
void insertAtBegining(int data){
    for(int i=size;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=data;
    size++;
}
void insertAtMiddle(int data,int p){
    for(int i=size;i>p;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[p]=data;
    size++;
    
}
void display(){
    printf("Elements in the array:\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int main()
{
    int n,i,data,ch,p;
    printf("Enter the Number of elements:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the data:\n");
        scanf("%d",&data);
        printf("Enter the choice to insert:\n1.append\n2.insertAtBegining\n3.insertAtMiddle\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            append(data);
            break;
            case 2:
            insertAtBegining(data);
            break;
            case 3:
            printf("Enter the position to insert:\n");
            scanf("%d",&p);
            insertAtMiddle(data,p);
            break;
        }
        
    }
    display();
    return 0;
}

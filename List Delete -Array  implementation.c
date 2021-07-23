#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int arr[MAX],size=-1;
void deleteAtLast(){
    size--;
}
void deleteAtBegining(int data){
    
    for(int i=0;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
        
    
}
void deleteAtMiddle(int p){
  
    for(int i=p;i<size-1;i++)
    {
        arr[i]=arr[i-1];
    }
    size--;
    
    
}
void append(int data){
    arr[++size]=data;
}
void display(){
    if(size==-1)
    {
        printf("Array Empty");
        return ;
    }
    printf("Elements in the array:");
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
        append(data);
    }
        printf("\nEnter the choice to delete:\n1.deleteAtLast\n2.deleteAtBegining\n3.deleteAtMiddle\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            deleteAtLast(data);
            break;
            case 2:
            deleteAtBegining(data);
            break;
            case 3:
            printf("Enter the position to insert:\n");
            scanf("%d",&p);
            deleteAtMiddle(p);
            break;
        }
        
    display();
    return 0;
}

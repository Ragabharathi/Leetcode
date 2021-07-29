#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int arr[MAX],size=-1;
int deleteAtLast(){
     if(size==-1)
    {
        printf("Array Empty");
        return 0 ;
    }
    size--;
    return 1;
}
int deleteAtBegining(int data){
     if(size==-1)
    {
        printf("Array Empty");
        return 0 ;
    }
    
    for(int i=0;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    return 1;
        
    
}
int deleteAtMiddle(int p){
     if(size==-1)
    {
        printf("Array Empty");
        return 0 ;
    } 
    if(p>size)
    {
        printf("Array size less than position\n");
        return 1;
    }
    for(int i=p;i<size-1;i++)
    {
        arr[i]=arr[i-1];
    }
    size--;
    return 1;
    
}
void append(int data){
    arr[++size]=data;
}
int display(){
    if(size==-1)
    {
        printf("Array Empty");
        return 0;
    }
    printf("Elements in the array:");
    for(int i=0;i<=size;i++){
        printf("%d ",arr[i]);
    }
    return 1;
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
    while(1){
        printf("\nEnter the choice to delete:\n1.deleteAtLast\n2.deleteAtBegining\n3.deleteAtMiddle\n4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            if(!deleteAtLast(data))
            return 0;
            break;
            case 2:
            if(!deleteAtBegining(data))
            return 0;
            break;
            case 3:
            printf("Enter the position to insert:\n");
            scanf("%d",&p);
            if(!deleteAtMiddle(p))
            return 0;
            break;
            case 4:
            exit(0);
        }
       if(! display())
       return 0;
    }
        
    
    return 0;
}

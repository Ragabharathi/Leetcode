#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};
struct node * create(){
    int x;
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data\n");
  scanf("%d",&x);
  if(x==-1)
  return 0;
  newnode->data=x;
  printf("Enter the left child\n");
  newnode->left=create();
  printf("Enter the right child\n");
  newnode->right=create();
  return newnode;
  
}

int main()
{
    struct node *root=create();

    return 0;
}

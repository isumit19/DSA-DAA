#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *left;
    struct node *right;
};
struct node *insert(struct node *ptr,int x){
    if(ptr==NULL){
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->val=x;
        ptr->right=NULL;
        ptr->left=NULL;
    }
    else if(ptr->val>x)
        ptr->left=insert(ptr->left,x);
    else if(ptr->val<x)
        ptr->right=insert(ptr->right,x);
    else printf("Same data already available \n");
    return ptr;
}
int displaypost(struct node*ptr)
{
	if(ptr!=NULL)
	{
	displaypost(ptr->left);
	displaypost(ptr->right);
	printf("%d ",ptr->val);
}
}
int displaypre(struct node*ptr)
{
	if(ptr!=NULL)
	{
	printf("%d ",ptr->val);
	displaypre(ptr->left);
	displaypre(ptr->right);
}
}
int displayin(struct node*ptr)
{
	if(ptr!=NULL)
	{
	displayin(ptr->left);
	printf("%d ",ptr->val);
	displayin(ptr->right);
}
}
void main(){
    printf("Enter total number of elements  :");
    struct node *root=NULL,*ptr=NULL;
    int n,i,x;
    scanf("%d",&n);
    printf("Enter values :");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        root=insert(root,x);

    }
    	printf("\nPreorder : ");
    	displaypre(root);
   	printf("\nInorder : ");
    	displayin(root);
    	printf("\nPostorder : ");
    	displaypost(root);
    	printf("\n");
}




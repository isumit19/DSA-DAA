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

int search(struct node*ptr,int x){
    if(ptr==NULL){
        return 0;
    }
     if(ptr->val>x){
        return (1+search(ptr->left,x));}
    else if(ptr->val<x){
        return (1+search(ptr->right,x));}
    else
            return 1;

}
int display(struct node*ptr)
{
	if(ptr!=NULL)
	{
	display(ptr->left);
	printf("%d ",ptr->val);
	display(ptr->right);
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
   	printf("Inorder : ");
    display(root);
	printf("\n\nEnter value to be searched ");
	int s;
	scanf("%d",&s);
    int h=search(root,s);
    if(h)
    	printf("Element found at height %d\n",h);
    else
    	printf("Element not found");
}




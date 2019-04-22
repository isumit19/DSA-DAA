#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node* left;
	struct node* right;
	int height;
};
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int height(struct node* N)
{
	if(N==NULL)
		return 0;
	return 
		N->height;
}
struct node* createNode(int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
    temp->val   = val; 
    temp->left   = NULL; 
    temp->right  = NULL; 
    temp->height = 1;   
    return(temp); 
} 
struct node *RRotate(struct node *temp) 
{ 
    struct node *x = temp->left; 
    struct node *y = x->right;  
    x->right = temp; 
    temp->left = y; 
    temp->height = max(height(temp->left), height(temp->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
    return x; 
}  
struct node *LRotate(struct node *t) 
{
    struct node *y = t->right; 
    struct node *x = y->left; 
    y->left = t; 
    t->right = x; 
    t->height = max(height(t->left), height(t->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
    return y; 
} 

int balance(struct node *N) 
{
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
}  
struct node* insert(struct node* node, int val) 
{
    if (node == NULL) 
        return(createNode(val)); 
  
    if (val < node->val) 
        node->left  = insert(node->left, val); 
    else if (val > node->val) 
        node->right = insert(node->right, val); 
    else
        return node; 
  
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
    int bal = balance(node); 
    if (bal > 1 && val < node->left->val) 
        return RRotate(node); 

    if (bal < -1 && val > node->right->val) 
        return LRotate(node); 
    if (bal > 1 && val > node->left->val)
     {
        node->left =  LRotate(node->left); 
        return RRotate(node); 
    } 
    if (bal < -1 && val < node->right->val)
     {
        node->right = RRotate(node->right); 
        return LRotate(node); 
    } 
    return node; 
} 
struct node * succ(struct node* node) 
{
    struct node* temp = node; 
    while (temp->left != NULL) 
        temp = temp->left; 
  
    return temp; 
} 
struct node* deleteNode(struct node* root, int val)
{
    if (root == NULL) 
        return root; 
  
    if ( val < root->val ) 
        root->left = deleteNode(root->left, val); 
  
    else if( val > root->val ) 
        root->right = deleteNode(root->right, val); 
  
    else{
        if( (root->left == NULL) || (root->right == NULL) )
        { 
        	struct node *temp;
		if(root->left!=NULL)
			temp=root->left;
		else
			temp=root->right;
     
            if (temp == NULL) {
                temp = root; 
                root = NULL; 
            } 
            else 
             *root = *temp; 
            free(temp); 
        } 
        else{
            struct node* temp = succ(root->right); 
            root->val = temp->val; 
            root->right = deleteNode(root->right, temp->val); 
        } 
    } 
    if (root == NULL) 
      return root; 
    root->height = 1 + max(height(root->left),height(root->right)); 
    int bal = balance(root);
    if (bal > 1 && balance(root->left) >= 0) 
        return RRotate(root); 
    if (bal > 1 && balance(root->left) < 0)
    {
        root->left =  LRotate(root->left); 
        return RRotate(root); 
    } 
    if (bal < -1 && balance(root->right) <= 0) 
        return LRotate(root); 
    if (bal < -1 && balance(root->right) > 0)
    {
        root->right = RRotate(root->right); 
        return LRotate(root); 
    } 
    return root; 
} 

void inorder(struct node *root){
    if(root != NULL){
    	inorder(root->left); 
        printf("Value = %d Height = %d Bal. factor = %d\n", root->val,root->height,balance(root)); 
        inorder(root->right); 
    } 
} 


int main(){
  struct node *root = NULL; 
  int n,val,del;
  char c;
  printf("Enter no of elements you want to insert in the AVL tree : ");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
  	scanf("%d",&val);
  	root = insert(root, val);
  }
  printf("Inorder\n"); 
  inorder(root); 
  printf("\n");
  printf("Enter the number of element to be deleted : ");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
  	scanf("%d",&del);
  	root = deleteNode(root,del); 
  }
  printf("\nInorder\n"); 
  inorder(root); 
  return 0; 
} 



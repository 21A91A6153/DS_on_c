/* binary tree consists of 3 parts left,data,right;it is a non sequential ds
node structure:left-data-right
the first node is root node
any node can be atmost 2   
                2000  10  3000 --->root node
            4000  20  5000      6000  30  7000 ---->child nodes
           40        50      60          70   --->leaf nodes   
we are using 2*i+1,2*i+2; we have to stop when it reaches the size of an array 
4 diff types of technique:inorder,preorder,post order,level order to view binary
---------------
#inorder:left - parent- right---------------------
40 20 50 10 60 30 70
#post order: 40 50 20 60 70 30 10 --->left-right-parent--- DEPTH FIRST SEARCH
#preorder: 10 20 40 50 30 60 70  --->parent-left-right---
*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *left;
	int data;
	struct Node *right;
};
typedef struct Node NODE;
NODE *root=NULL;
NODE *add[100];
void create_tree(int *arr,int n)
{
	int i,val;
	NODE *nn,*nn1,*nn2;
	val=arr[0];
	nn=(NODE *)malloc(sizeof(NODE));
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	add[0]=nn;
	root=nn;
	for(i=0;2*i+1<n;i++)
	{
		//creation of left node
		nn1=(NODE *)malloc(sizeof(NODE));
		nn1->data=arr[2*i+1];
		nn1->left=NULL;
		nn1->right=NULL;
		//creation of right node
		nn2=(NODE *)malloc(sizeof(NODE));
		nn2->data=arr[2*i+2];
		nn2->left=NULL;
		nn2->right=NULL;
		//placing add in array
		add[2*i+1]=nn1;
		add[2*i+2]=nn2;
		// making children nodes
		add[i]->left=nn1;
		add[i]->right=nn2;
	}
}
void inorder(NODE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void postorder(NODE *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void preorder(NODE *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	int n,arr[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	create_tree(arr,n);
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
}

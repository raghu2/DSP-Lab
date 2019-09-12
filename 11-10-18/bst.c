#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;
node *tree,*new;
node * construct(int, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
void main(){
	int n,i;
	tree=(node *)malloc(sizeof(node));
	FILE *inp;
	inp=fopen("input.txt","r");
	fscanf(inp,"%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		fscanf(inp,"%d",&a[i]);
	}
	tree->data=a[0];
	tree->left=NULL;
	tree->right=NULL;
	for(i=1;i<n;i++){
		construct(a[i],tree);
	}
	printf("the tree has been constructed\n");
	printf("\n the inorder sequence is \n");
	inorder(tree);
	printf("\n the preorder sequence is \n");
	preorder(tree);
	printf("\n the postorder sequence is \n");
	postorder(tree);
}
node* construct(int value,node *t){
	new=(node*)malloc(sizeof(node));
	if(value< t->data){
		if(t->left!=NULL){
			construct(value,t->left);
		}
		else{
			new->data=value;
			new->right=NULL;
			new->left=NULL;
			t->left=new;
			return t;
		}
	}
	if(value> t->data){
		if(t->right!=NULL){
			construct(value,t->right);
		}
		else{
			new->data=value;
			new->right=NULL;
			new->left=NULL;
			t->right=new;
			return t;
		}
	}
}
void preorder(node *t){
	if(t){
		printf("%d\t",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(node *t){
	if(t){
		inorder(t->left);
		printf("%d\t",t->data);
		inorder(t->right);
	}
}
void postorder(node *t){
	if(t){
		postorder(t->left);
		postorder(t->right);
		printf("%d\t",t->data);
	}
}

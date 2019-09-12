#include<stdio.h>
#include<stdlib.h>
typedef struct adjnode
{
	struct node *data;
	struct adjnode *anext;
}adjnode;
typedef struct node
{
	int value;
	struct node *next;
	struct adjnode *anext;
}node;
node *head;
int displaynodes(node *dn)
{
	while(dn)
	{
		if(!dn)
		{
			return 0;
		}
		else
		{
			printf("%d",dn->data);
			displayadjnodes(dn);
			d=dn->next;
		}
	}
}
int displayadjnodes(node *dan)
{
	while(dan)
	{
		if(!dan)
		{
			return 0;
		}
		else
		{
			printf("%d",dan->data->value);
			dan->anext;
		}
	}
}
void insertnode(int valueofnode)
{
	in=(node *)malloc(sizeof(node));
	in->value=valueofnode;
	if(!head)
	{
		head=in;
	}
	else
	{
		ap=ap->next;
		
void main()
{
}


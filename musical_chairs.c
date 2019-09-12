#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node{
	int value;
	struct Node *next;
}*head;
void main()
  {
	int n;
	printf("Enter no of element\n");
	scanf("%d",&n);
	struct Node *new=(struct Node *)malloc(sizeof(struct Node));
	printf("enter a head value\n");
	scanf("%d",&(new->value));
        new->next=NULL;
        head=new;
	int i=0,key,count=1;
	struct Node *temp;
        temp=head;
        count=n;
	while(n>1)
        {
		struct Node *new=(struct Node *)malloc(sizeof(struct Node));
		printf("enter the value of the next node\n");
		scanf("%d",&(new->value));
                new->next=NULL;
                temp->next=new;
                temp=temp->next;
	        n--;
	}
        temp->next=head;
        temp=head;
	while(count>1)
        {
		key=rand()%count;
		while(key>0)
		{
			temp=temp->next;
			key--;
		}
		printf("eliminated no: %d \n",temp->next->value);
		temp->next=temp->next->next;
		count--;
	}
	printf("%d is the winner",(temp->value));
}

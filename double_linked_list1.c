#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL;
void insert_at_end(int val)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->next=NULL;
	NN->prev=NULL;
	NN->data=val;
	if(head==NULL)
	{
		head=NN;
	}
	else
	{
		temp=head;
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=NN;
		NN->prev=temp;
	}
}
void display()
{
	NODE *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("No nodes");
	}
	else
	{
		while(temp)
		{
			printf("%d %d %d %d\n",temp,temp->prev,temp->data,temp->next);
			temp=temp->next;
		}
	}
}
int delete_at_end()
{
	NODE *temp,*temp1;
	int val;
	if(head==NULL)
	{
		return -1;
	}
	if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	temp=head;
	while(temp->next->next)
	{
		temp=temp->next;
	}
	temp1=temp->next;
	temp->next=NULL;
	temp1->prev=NULL;
	return temp1->data;
}
void main()
{
	int val,ch;
	while (1)
	{
		printf("1.insert at end 2.delete at end 3.display 4.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			insert_at_end(val);
		}
		else if(ch==2)
		{
			val=delete_at_end();
			if(val==-1)
			{
				printf("no nodes");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			display();
		}
		else
		{
			break;
		}
	}
}

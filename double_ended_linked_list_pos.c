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
void insert_at_head(int val)
{
	NODE *nn;
	nn=(NODE *)malloc(sizeof(NODE));
	nn->prev=NULL;
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		nn->next=head;
		head->prev=nn;
		head=nn;
	}
}
int delete_at_head()
{
	int val;
	NODE *temp;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head->next;
		val=head->data;
		temp->prev=NULL;
		head->next=NULL;
		head=temp;
		return val;
	}
}
void insert_by_pos(int val,int pos)
{
	NODE *nn,*temp,*temp1;
	int nc=1,p;
	nn=(NODE *)malloc(sizeof(NODE));
	nn->prev=NULL;
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else if(pos==1)
	{
		insert_at_head(val);
	}
	else if(pos>=nc)
	{
		insert_at_end(val);
	}
	else
	{
		temp=head;
		for(p=1;p<pos-1;p++)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=nn;
		nn->prev=temp;
		temp->prev=nn;
		nn->next=temp1;
	}
}
int delete_by_pos(int pos)
{
	int val,nc=0,p;
	NODE *temp,*temp1;
	temp=head;
	while(temp)
	{
		temp=temp->next;
		nc++;
	}
	if(head==NULL || pos>nc)
	{
		return -1;
	}
	if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	if(pos==1)
	{
		val=delete_at_head();
		return val;
	}
	if(pos==nc)
	{
		val=delete_at_end();
		return val;
	}
	temp=head;
	for(p=1;p<pos-1;p++)
	{
		temp=temp->next;
	}
	temp1=temp->next;
	temp->next=temp1->next;
	temp->next->prev=temp;
	temp->next=NULL;
	temp->prev=NULL;
	return temp1->data;
}
void main()
{
	int val,ch,pos;
	while (1)
	{
		printf("1.insert at end 2.delete at end 3.display 4.insert at head 5.delete at head 6.insert by pos 7.delete by pos 8.break\n");
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
		else if(ch==4)
		{
			scanf("%d",&val);
			insert_at_head(val);
		}
		else if(ch==5)
		{
			val=delete_at_head();
			if(val==-1)
			{
				printf("NO NODES TO DELETE\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==6)
		{
			scanf("%d%d",&val,&pos);
			insert_by_pos(val,pos);
		}
		else if(ch==7)
		{
			scanf("%d",&pos);
			val=delete_by_pos(pos);
			if(val==-1)
			{
				printf("no nodes\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else
		{
			break;
		}
	}
}


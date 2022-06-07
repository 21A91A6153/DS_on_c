#include<stdio.h>
#include<stdlib.h>
struct Node
{                                 //
	int data;                     //selr reference of structure
	struct Node *next;            //
};
typedef struct Node NODE;;
NODE *head=NULL;
void insert_at_end(int val)
{
	NODE *nn,*temp;
	nn=(NODE *)malloc(sizeof(NODE));
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nn;
	}
}
int delet_at_end()
{
	int val;
	NODE  *temp;
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
    temp=head;
    while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
    val=temp->next->data;
    temp->next=NULL;
    return val;
}
void display()
{
	NODE *temp;
	if(head==NULL)
	{
		printf("No Nodes\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d %d %d \n",temp,temp->data,temp->next);
			temp=temp->next;
		}
		printf("\n");
	}
}
void insert_at_head(int val)
{
	NODE *nn;
	nn=(NODE *)malloc(sizeof(NODE));
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		nn->next=head;
        head=nn;
	}
}
int delet_at_head()
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
    else if(head->next!=NULL)
	{
		val=head->data;
		head=head->next;
		return val;
	}
  	/*temp=head;
	temp=temp->next;
	head->next=NULL;
	val=head->data;
	head=temp;
	return val;*/
}
void main()
{
	/*NODE *nn=(NODE *)malloc(sizeof(NODE));
	nn->data=10;
	nn->next=NULL;
	printf("%d %d %d ",nn->data,nn->next,nn);*/
	int ch,val;
	while(1)
	{
		printf("1.insert at end 2.delete at end 3.display 4.insert at head 5.delete at head 6.exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			insert_at_end(val);
		}
		else if(ch==2)
		{
			val=delet_at_end();
			if(val==-1)
			{
				printf("NO NODES\n");
			}
			else
			{
		    	printf("%d \n",val);
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
			val=delet_at_head();
			if(val==-1)
			{
				printf("NO NODES\n");
			}
			else
			{
		    	printf("%d \n",val);
		    }
		}
		else
		{
			break;
		}
	}	
}

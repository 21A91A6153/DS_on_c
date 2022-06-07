/* insert by position
check list is empty head=null
count nodes if it is less than pos we */
#include<stdio.h>
#include<stdlib.h>
struct Node
{                                 
	int data;                    
	struct Node *next;           
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
int delete_at_end()
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
    else if(head->next!=NULL)
	{
		val=head->data;
		head=head->next;
		return val;
	}
}
void insert_by_pos(int val,int pos)
{
	NODE *temp,*nn;
	int cn=1,i;
	nn=(NODE *)malloc(sizeof(NODE));
	nn->data=val;
	nn->next=NULL;
	temp=head;
	while(temp)
	{
		temp=temp->next;
		cn++;
	}
	if(head==NULL)
	{
		head=nn;
	}
	else if(pos==1)
	{
		insert_at_head(val);
	}
	else if(cn<pos)
	{
		insert_at_end(val);
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}
}
int delete_by_pos(int pos)
{
	NODE *temp=head;
	int c=1,val,i;
	if(head==NULL)
	{
		return -1;
	}
	else if(pos==1)
	{
		return delete_at_head();
	}
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	if(c<=pos)
	{
		return delete_at_end();
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		val=temp->next->data;
		temp->next=temp->next->next;
		return val;
	}
}
void main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1.insert at end 2.delete at end 3.display 4.insert at head 5.delete at head 6.insert by pos 7.delete by pos 8.exit: ");
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
			val=delete_at_head();
			if(val==-1)
			{
				printf("NO NODES\n");
			}
			else
			{
		    	printf("%d \n",val);
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
				printf("NO NODES TO DELETE AT THAT POSITION\n");
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

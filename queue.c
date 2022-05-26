/* queue:first in first out or last in last out
rare end-insert(enque)
front end-deletion(deque)
when front==rare queue is empty(under flow)
drawback can be overcome by circular queue etc
ciruclar queue:f==0 and r==0 f=rare+1
*/
#include<stdio.h>
#include<stdlib.h>
int front=-1,rare=-1,*que,size;
void enque(int val)
{
	if(rare==size-1)
	{
		printf("overflow");
	}
	else if(front==-1 && rare==-1)
	{
		que[++rare]=val;
		front=0;
	}
	else
	{
		que[++rare]=val;
	}
}
int deque()
{
    int val;
	if(front==-1 && rare==-1)
	{
		return -1;
	}
	else if(front==rare)
	{
		val=que[front];
		front=-1;
		rare=-1;
		return val;
	}
	else
	{
		val=que[rare];
		rare++;
		return val;
	}
}
void display()
{
	int i;
	if(rare==-1 && front==-1)
	{
		printf("under flow");
	}
	else
	{
	   for(i=front;i<=rare;i++)
	   {
	     	printf("%d ",que[i]);
    	}
     	printf("\n");
   }
}
void main()
{
	int i,ch,val;
	scanf("%d",&size);
	que=(int *)calloc(size,sizeof(int));
	while(1)
	{
		printf(" 1.enque 2.deque 3.display 4.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			enque(val);
		}
		else if(ch==2)
		{
			val=deque();//which element we are deleting
			if(val==-1)
			{
				printf("queue is empty\n");
			}
			printf("%d\n",val);
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

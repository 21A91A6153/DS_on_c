#include<stdio.h>
#include<stdlib.h>
int front=-1,rare=-1,*que,size;
void enque(int val)
{
	if((front==0 &&rare==size-1) || rare+1==front)
	{
		printf("overflow");
	}
	else if(front==-1 && rare==-1)
	{
		rare=(rare+1)%size;
		que[rare]=val;
		front=0;
	}
	else
	{
		rare=(rare+1)%size;
		que[rare]=val;
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
	}
	else
	{
		val=que[front];
		front=(front+1)%size;
	}
	return val;
}
void display()
{
	int i,j;
	if(rare==-1 && front==-1)
	{
		printf("under flow");
	}
	else
	{
	   i=front;
	   j=rare;
	   while(i!=j)
	   {
	   	    printf("%d ",que[i]);
	   	    i=(i+1)%size;
	   }
	   printf("%d\n",que[j]);
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

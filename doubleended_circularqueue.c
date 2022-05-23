/* deque:double ended circular queue
empty=front and rare =-1
r=r+1%size  but in double ended queue both enque,deque are at both the ends
rear=enque deque front=deque enque
full=f==0 and r=size-1 front=r+1
enque at rear : rear++;deque :rear--
enque at front: front--;deque: front++*/
#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,*que,size;
void enque_at_front(int val)
{
	if((front==0 && rear==size-1 )|| rear+1==front)
	{
		printf("Queue is overflow\n");
	}
	else if(rear==-1 && front==-1)
	{
		front=0;
		rear=0;
		que[front]=val;
	}
	else
	{
		if(front==0)
		{
			front=size-1;
		}
		else
		{
			front--;
		}
		que[front]=val;
	}
}
int deque_at_rear()
{
	int val;
	if(front==-1 && rear==-1)
	{
		return -1;
	}
	if(front==rear)
	{
		val=que[front];
		front=-1;
		rear=-1;
		return val;
	}
	val=que[rear];
	if(rear==0)
	{
		rear=size-1;
	}
	else
	{
		rear--;
	}
	return val;
}
void enque_at_rear(int val)
{
		if((front==0 && rear==size-1 )|| rear+1==front)
	{
		printf("Queue is overflow\n");
	}
	else if(rear==-1 && front==-1)
	{
		front=0;
		rear=0;
		que[rear]=val;
	}
	else
	{
		rear=(rear+1)%size;
		que[rear]=val;
	}
}
int deque_at_front()
{
	int val;
	if(front==-1 && rear==-1)
	{
		return -1;
	}
	if(front==rear)
	{
		val=que[front];
		front=-1;
		rear=-1;
		return val;
	}
	val=que[front];
	front=(front+1)%size;
	return val;
}
void display()
{
		int i,j;
	if(rear==-1 && front==-1)
	{
		printf("under flow\n");
	}
	else
	{
	   i=front;
	   j=rear;
	   while(i!=j)
	   {
	   	    printf("%d %d\n",i,que[i]);
	   	    i=(i+1)%size;
	   }
	   printf("%d %d\n",j,que[j]);
   }
}
void main()
{
	int i,ch,val;
	scanf("%d",&size);
	que=(int *)calloc(size,sizeof(int));
	while(1)
	{
		printf("1.enque at rear 2.deque at rear 3.enque at front 4.deque at front 5.display 6.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			enque_at_rear(val);
		}
		else if(ch==2)
		{
			val=deque_at_rear();
			if(val==-1)
			{
				printf("under flow\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			scanf("%d",&val);
			enque_at_front(val);
		}
		else if(ch==4)
		{
			val=deque_at_front();
			if(val==-1)
			{
				printf("under flow\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==5)
		{
			display();
		}
		else
		{
			break;
		}
	}
}

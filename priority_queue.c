#include<stdio.h>
#include<stdlib.h>
int *que,*pro,size,rear=-1,front=-1;
void enque(int val,int p)
{
	int i,j;
	if(rear==size-1)
	{
		printf("over flow\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		que[rear]=val;
		pro[rear]=p;
	}
	else
	{
		j=rear;
		while(j>=0 && p<pro[j])
		{
			pro[j+1]=pro[j];
			que[j+1]=que[j];
			j--;
		}
		pro[j+1]=p;
		que[j+1]=val;
		rear++;
	}
}
int deque()
{
	int val;
	if(front==-1 && rear==-1)
	{
		return -1;
	}
	if(front==rear)
	{
		val=que[front];
		que[front]=0;
		pro[front]=0;
		front=-1;
		rear=-1;
		return val;
	}
	val=que[front];
	que[front]=0;
	pro[front]=0;
	front+=1;
	return val;
}
void display()
{
	int i,j;
	if(front==-1 && rear==-1)
	{
		print("under flow\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d %d\n",que[i],pro[j]);
		}
		printf("\n");
	}
}
void main()
{
	int i,ch,val,p;
	scanf("%d",&size);
	
	
	
}

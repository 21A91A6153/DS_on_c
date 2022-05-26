//   stack:it is a technique it follows first in last out or last in first out ,it is also an array
//we can insert or delete elementsin the stack from top ends
// pop():delete;push():insert;top is intially -1 which means no elements in the stack
//top==size-1 indicates stack is full
// push has datatype void as it is not returning
//pop has datatype int as we should tell which element we deleted
#include<stdio.h>
#include<stdlib.h>
int Top=-1;
int n,*st;
void push(int val)
{
	if(Top==n-1)
	{
		printf("Stack is full\n");
	}
	else
	{
    	st[++Top]=val;
	}
}
int pop()
{
	int val;
	if(Top==-1)
	{
		return -1; 
	}
	else
	{
		val=st[Top];
		st[Top--]=0;
		return val;
	}
}
void display()
{
	int i;
	if(Top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		for(i=Top;i>=0;i--)
		{
			printf("%d ",st[i]);
		}
		
	}
}
void main()
{
	int i,ch,val;
	scanf("%d",&n);//size of stack
	st=(int *)calloc(n,sizeof(int));//allocate memory of stack
	while(1)
	{
		printf("1.push 2.pop 3.display 4.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);// reading of val
			push(val);//calling push function
		}
		else if(ch==2)
		{
			val=pop();
			if(val==-1)
			{
				printf("Stack is empty\n");
			}
			printf("%d ",val);
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

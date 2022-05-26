#include<stdio.h>
int fun(int *arr,int n,int m)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==m)
		{
			flag=1;
			printf("Yes");//return 1;
			break;
		}//return 0;
		else
		{
			flag=0;
			printf("No");
		     break;
		}
	}
}
void main()
{
	int n,i,arr[100],m,res;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	res=fun(arr,n,m);
}

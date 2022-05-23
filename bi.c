#include<stdio.h>
int bi(int *arr,int i,int j,int m)
{
	int k;
	if(i>j)
	{
		return 0;
	}
	k=(i+j)/2;
	if(arr[k]==m)
		{
			return 1;
		}
		else if(arr[k]>m)
		{
			j=k-1;
		}
		else
		{
			i=k+1;
		}
		return bi(arr,i,j,m);
}
void main()
{
	int n,arr[100],m,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	if(bi(arr,0,n-1, m))
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
}

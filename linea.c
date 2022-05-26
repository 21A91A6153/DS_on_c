#include<stdio.h>
int linea(int *arr,int n,int m)
{
	int c=0,i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==m)
		{
		  c++;	
		}
	}
	return c;
}
void main()
{
	int n,i,arr[100],m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	printf("%d",linea(arr,n,m));
	
}

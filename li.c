#include<stdio.h>
int li(int *arr,int n,int m)
{
	int i,ind=0;
	for(i=0;i<n;i++)//n-1,i>=0;i--
	{
		if(arr[i]==m)
		{
		   ind=i;	//return i;
		}
	}
	return ind;
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
	printf("%d",li(arr,n,m));
}

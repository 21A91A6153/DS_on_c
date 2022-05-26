#include<stdio.h>
int linear_se(int *arr,int n,int m)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==m)
		{
			return i;
		}
	}
	return -1;

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
	printf("%d",linear_se(arr,n,m));
}

#include<stdio.h>
int *merge(int *a,int n,int *b,int m)
{
	static int res[100];
	int i=0,j=0,k=0;
	while(i<n && j<m)
	{
		if(a[i]>b[j])
		{
			res[k]=b[j];
			j++;
		}
		else
		{
			res[k]=a[i];
			i++;
		}
		k++;
	}
		while(i<n)
		{
		    res[k]=a[i];
			i++;
			k++;	
		}
		while(j<m)
		{
			res[k]=b[j];
			j++;
			k++;
		}
		return res;
}
void main()
{
	int i,n,m,arr[100],*res,brr[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&brr[i]);
	}
	res=merge(arr,n,brr,m);
	for(i=0;i<n+m;i++)
	{
		printf("%d ",res[i]);
	}	
}

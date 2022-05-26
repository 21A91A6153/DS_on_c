#include<stdio.h>
void merge(int *arr,int l,int m,int h)
{
	int i,j,a[100],b[100],n1,n2,k,res[100];
	n1=m-l+1;
	n2=h-m;
	k=l;
	for(i=0;i<n1;i++,k++)
	{
		a[i]=arr[k];
	}
	k=m+1;
	for(i=0;i<n2;i++,k++)
	{
		b[i]=arr[k];
	}
	i=0,j=0,k=0;
	while(i<n1 && j<n2)
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
	while(i<n1)
	{
		res[k]=a[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		res[k]=b[j];
		j++;
		k++;
	}
	for(i=0;i<n1+n2;i++)
	{
		arr[i]=res[i];
	}
}
void merge_sort(int *arr,int n)
{
	int l,m,h;
	l=0,h=n-1;
	m=(l+h)/2;
	merge(arr,l,m,h);
}
void main()
{
	int arr[100],i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

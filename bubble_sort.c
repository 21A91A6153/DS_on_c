#include<Stdio.h>
void bubble_sort(int *arr,int n)
{
	int p,i,j,temp;
	for(p=1;p<=n;p++)
	{
		for(i=0,j=1;i<n-1;i++,j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void main()
{
	int arr[100],i,n,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bubble_sort(arr,n);
	for(i=0;i<n;i++)
	{
	  printf("%d ",arr[i]);	
	}
}

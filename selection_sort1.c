#include<stdio.h>//5 4 3 2 1
int selection_sort(int *arr,int n)//1 4 3 2 5
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{	
			min=j;
		    }
		}
		temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
	}
}
int main()
{
	int n,arr[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
    selection_sort(arr,n);
    for(i=0;i<n;i++)
    {
    	printf("%d ",arr[i]);
	}
}

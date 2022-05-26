#include<stdio.h>
//3 5 7 8 9
int binary(int *arr,int n,int se)
{
	int i=0,j=n-1,m;
	while(i<=j)
	{
		m=(i+j)/2;
		if(arr[m]==se)
		{
			return 1;
		}
		else if(arr[m]>se)
		{
			j=m-1;
		}
		else
		{
			i=m+1;
		}
	}
	return 0;
}
 void main()    //0 1 2 3 4
 {
 	 int n,arr[100],i,j,m,se;
 	 scanf("%d",&n);
 	 for(i=0;i<n;i++)
 	 {
 	 	scanf("%d",&arr[i]);
	  }
	  scanf("%d",&se);
	  printf("%d",binary(arr,n,se));
}
	  

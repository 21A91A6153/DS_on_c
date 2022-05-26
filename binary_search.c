#include<stdio.h>//3 5 7 8 9
 void main()    //0 1 2 3 4
 {
 	int n,arr[100],i,j,m,se,f=0;
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 	 	scanf("%d",&arr[i]);
	}
	scanf("%d",&se);
	i=0;
	j=n-1;
	while(i<=j)
	{
	  	m=(i+j)/2;
	  	if(arr[m]==se)
	  	{
	  		f=1;
	  		printf("found");
	  		break;
		}
		else if(arr[m]>se)
		{
		  	j=m-1;
		}
		else if(arr[m]<se)
		{
		  	i=m+1;
		}  
	  }
	  if(f==0)
	  {
	  	printf("not");
	  }
	  
 }
             

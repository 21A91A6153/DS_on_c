// INSERTION SORT
// 25 89 56 11 90
/*pass1:25 89 56 11 90
pass2:25 56 89 11 90
pass3:11 25 56 89 90
pass4:11 25 56 89 90
*/

#include<stdio.h>
void main()
{
	int a[100],n,i,j,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)// 2 4 1 5 3
	{               // 0 1 2 3 4
		temp=a[i];//temp=1
		for(j=i-1;j>=0;j--)
		{
			if(temp>a[j])//
			{
				a[j+1]=temp;
				break;
			}
			else
			{
				a[j+1]=a[j];
			}
		}
		if(j==-1)
		{
			a[0]=temp;
	    }
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

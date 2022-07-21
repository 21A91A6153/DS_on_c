#include<stdio.h>
void swap(int *,int*);
void main()
{
	int a=10,b=20;
	printf("before swapping a=%d ,b=%d\n",a,b);
	swap(&a,&b);
	printf("after swapping a=%d, b=%d\n",a,b);
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	printf("after swapping in fun  a=%d, b=%d\n",*a,*b);

}

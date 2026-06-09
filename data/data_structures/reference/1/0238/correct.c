//这是一个全排列的代码 

#include <stdio.h>
int N;
int a[10]={1,2,3,4,5,6,7,8,9,10};
void swap(int i,int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp; 
 } 
 
 void a_printf()
 {
 	int i;
 	for(i=0;i<N;i++)
 	{
 		printf("%d ",a[i]);
	 }
	printf("\n");
 }
 
 void func(int leng)//但是就是应该先输出10 8 9，而不是10 9 8。这个看代码，不太可能出现，，，但是就是对了。闹不懂 
 {
 	int i;
 	if(leng==N)
 	{
 		a_printf();
 		return ;
	 }
	func(leng+1);
 	for(i=0;i+leng<N;i++)
 	{
 		swap(leng+i,leng-1);
 		func(leng+1);
	}
	for(i=N-leng-1;i>=0;i--)
	{
		swap(leng+i,leng-1);
	}
 }
 
 int main()
 {
 	scanf("%d",&N);
 	func(1);
 	return 0;
 }
 
 
 
 


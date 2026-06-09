#include<stdio.h>
#include<stdlib.h>
void fullarrangement(int start,int stop,int destination[]);
void exchange(int *p1,int *p2);
int cmp(const void *p1,const void *p2);
int main()
{
	int a[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;++i) a[i]=i+1;
	fullarrangement( 0, n, a);

}
void exchange(int *p1,int *p2)
{
	*p1=*p1^*p2;
	*p2=*p1^*p2;
	*p1=*p1^*p2;
}

void fullarrangement(int start,int stop,int destination[])
{
	int count,i,temp;
	if(start>=stop)
	{
		for(count=0;count<stop;count++)
		printf("%d ",destination[count]);
		printf("\n");
	}
	else
	{
		for(count=start;count<stop;count++)
		{
			if(count!=start)
			{
				exchange(&destination[count],&destination[start]);
				temp=destination[count];
				for(i=count;i>start;i--) 
				destination[i]=destination[i-1];
				destination[start+1]=temp;
			}
			fullarrangement( start+1, stop, destination);
			if(count!=start)
			{
				for(i=start+1;i<count;i++) 
				destination[i]=destination[i+1];
				destination[count]=temp;
				exchange(&destination[count],&destination[start]);
			}
			
		}
	}
}













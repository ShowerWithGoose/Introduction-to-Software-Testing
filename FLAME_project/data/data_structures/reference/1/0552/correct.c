#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(int *a,int *b)/*交换两个数*/ 
{
	int t=*a;
	*a=*b;
	*b=t;
}
int rise_int(const void *p1,const void *p2)
{
    if(*(int*)p1<*(int*)p2) return -1;
    if(*(int*)p1>*(int*)p2) return 1;
    return 0 ;
}
void replica(int a[],int b[],int i,int last)/*将a从序号为i的项开始到最后一项复制到数组b中,将b排序后再复制回给a*/
{
	int j,m=i,n;
	for(j=0;i<last;i++,j++)
		b[j]=a[i];
	qsort(b,j,sizeof(int),rise_int);
	for(n=0;n<j;m++,n++)
		a[m]=b[n]; 
} 
void fullarrangement(int a[],int first,int last)/*递归生成全排列*/
{
	int i,b[15],c[15],j;
	memset(b,0,sizeof(int));
	memset(c,0,sizeof(int));
	if(first>=last)
	{
		for(i=0;i<last;i++)
			printf("%d ",a[i]);
		printf("\n");
	}	
	else
	{
		for(i=first;i<last;i++)
		{
			swap(a+first,a+i);
			for(j=0;j<last;j++)
				c[j]=a[j];
			replica(a,b,first+1,last);
			fullarrangement(a,first+1,last);
			for(j=0;j<last;j++)
				a[j]=c[j];
			swap(a+first,a+i);
		}
	}
} 
int main()
{
	int n,i,a[15];
	scanf("%d",&n);
	for(i=0;i<n;i++)/*初始化数组*/ 
		a[i]=i+1;
	fullarrangement(a,0,n);
	return 0 ;
}




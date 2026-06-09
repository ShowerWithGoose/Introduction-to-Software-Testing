#include <stdio.h>
#include <stdlib.h>
/*intÖµ»¥»» */
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
 } 
int cmp(const void *a,const void *b)
{
	int *a1=(int *)a,*b1=(int *)b;
	if(*a1>*b1)
	return 1;
	if(*a1<=*b1)
	return -1;
}
 /*È«ÅÅÁÐ*/ 
void fullpermutation(int sour[],int begin,int end)
{
	qsort(&sour[begin],end-begin,sizeof(sour[begin]),cmp);
	int i;
	if(begin>=end)
	{
		for(i=0;i<end;i++)
		printf("%d ",sour[i]);
		printf("\n");
	}
	else 
	{
		for(i=begin;i<end;i++)
		{
			if(begin!=i)
			swap(&sour[begin],&sour[i]);
			fullpermutation(sour,begin+1,end);
			if(begin!=i)
			swap(&sour[begin],&sour[i]);
		}
  	}
	qsort(&sour[begin],end-begin,sizeof(sour[begin]),cmp);
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	int sour[20];
	int i=0;
	for(i=0;i<n;i++)
	sour[i]=i+1;
	fullpermutation(sour,0,n);
	return 0;
}


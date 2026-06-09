#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct jgt
{
	int bgx;
	int bgy;
	int edx;
	int edy;
	int sl;
 } jgt[150];
 int hanshu(void *a,void *b);
 int main()
 {
 	int n,i,j;
 	int flag=0;
	int k=0;
 	struct jgt jgt[150];
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		scanf("%d%d%d%d",&jgt[i].bgx,&jgt[i].bgy,&jgt[i].edx,&jgt[i].edy);
	    jgt[i].sl=1;
	}
	qsort(jgt,n,sizeof(jgt[0]),hanshu);//1 待排序数组首地址 2 数组中待排序元素数量 3 各元素的占用空间大小 4 指向函数的指针
	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n-1;j++)
		{
		   if(jgt[i].bgx==jgt[j+1].edx&&jgt[i].bgy==jgt[j+1].edy)	
		   {
		   	   jgt[j+1].sl=jgt[j+1].sl+jgt[i].sl;
		   }
		}
	}
	for(i=0;i<n;i++)
	{
	  	if(jgt[i].sl>k)
	  	{
	  		k=jgt[i].sl;
	  		flag=i;
		}
	}
	printf("%d %d %d",k,jgt[flag].bgx,jgt[flag].bgy);
	return 0;
  } 
int hanshu(void *a,void *b)
{
	struct jgt *m=(jgt*)a;
	struct jgt *n=(jgt*)b;
	if(m->bgx!=n->bgx)
	{
		return n->bgx-m->bgx;
	}
	else{
		return n->bgy-m->bgy;
	}
}  


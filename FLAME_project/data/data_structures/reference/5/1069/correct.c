#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char buf[BUFSIZ];
#define N 100
struct polynomial
{
    int xishu;
    int zhishu;
};
void qsort(
			void *base,//数组起始地址，通常为数组名 
			size_t num,//数组中元素的个数 
			size_t size,//数组中每个元素的大小（字节数） 
			int(*compare)(const void*,const void*));//指向比较函数的函数指针 					
int compare (const void* a1,const void* b1)
{
    struct polynomial aa=*(struct polynomial*)a1;
    struct polynomial bb=*(struct polynomial*)b1;
    return -aa.zhishu+bb.zhishu;
	//return strcmp((*(people*)a).name,((people*)b).name);
    //char* c=*(char**)a;
    //char* d=*(char**)b;
}
int main()
{
    struct polynomial a[100],b[100],c[1000];
    //char line1[200],line2[200];
    char ch=' ';
    int i=0,j,k=0,a1,b1,sum;
    while(ch==' ')
    {
        scanf("%d%d",&a[i].xishu,&a[i].zhishu);
        //printf("%d %d\n",a[i].xishu,a[i].zhishu);
        scanf("%c",&ch),
        i++;
    }
    ch=' ';
    a1=i;
    i=0;
    while(ch==' ')
    {
        scanf("%d%d",&b[i].xishu,&b[i].zhishu);
        //printf("%d %d\n",b[i].xishu,b[i].zhishu);
        scanf("%c",&ch);
        i++;
    }
    b1=i;
    for(i=0;i<a1;i++)
    {
        for(j=0;j<b1;j++)
        {
            c[k].xishu=a[i].xishu*b[j].xishu;
            c[k].zhishu=a[i].zhishu+b[j].zhishu;
            k++;
        }
    }
    sum=k;
    for(i=0;i<sum;i++)
    {
    	//printf("%d %d\n",c[1].xishu,c[i].zhishu);
	}
    qsort(c,sum,sizeof(c[0]),compare);
    for(i=0;i<sum;i++)
    {
    	//printf("%d %d\n",c[1].xishu,c[i].zhishu);
	}
    for(i=0;i<sum;i++)
    {
    	//printf("jj\n");
    	if(c[i].xishu==0)
			continue;
		if(i==sum-1)
		{
			printf("%d %d ",c[i].xishu,c[i].zhishu);	
		}  
        else if(c[i].zhishu!=c[i+1].zhishu)
        {
            printf("%d %d ",c[i].xishu,c[i].zhishu);
        }
        else
        {
            c[i+1].xishu=c[i+1].xishu+c[i].xishu;
        }
    }	
    return 0;
}

/*

1 1 1 0
1 1 -1 0

-1 1 1 0
1 1 -1 0

*/



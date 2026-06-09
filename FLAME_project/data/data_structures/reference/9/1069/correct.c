#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char buf[BUFSIZ];
#define N 100
    int n,i,j,k,x,y;
    int a[105][6];
    int f[105]={0};
    int maxf=0,flag;
    struct coordinate
	{
		int a;
		int b;
		int c;
		int d;		 
	}coor[107];
void qsort(
			void *base,//数组起始地址，通常为数组名 
			size_t num,//数组中元素的个数 
			size_t size,//数组中每个元素的大小（字节数） 
			int(*compare)(const void*,const void*));//指向比较函数的函数指针 
			
int compare (const void* a1,const void* b1)
{
    struct coordinate aa=*(struct coordinate*)a1;
    struct coordinate bb=*(struct coordinate*)b1;
    return aa.a-bb.a;
	//return strcmp((*(people*)a).name,((people*)b).name);
    //char* c=*(char**)a;
    //char* d=*(char**)b;
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&coor[i-1].a);
        scanf("%d",&coor[i-1].b);
        scanf("%d",&coor[i-1].c);
        scanf("%d",&coor[i-1].d);
    }
    //排序？of course
	qsort(coor,n,sizeof(coor[0]),compare);
    //printf("ttt\n");
    for(i=0;i<n;i++)
    {
        x=coor[i].c;
        y=coor[i].d;
        for(j=i+1;j<n;j++)
        {
        //    if(j==i)
        //       j++,continue;  
            if(x==coor[j].a&&y==coor[j].b)//如果第i个的尾与第j个的头匹配上了
            {
                f[i]++;
                x=coor[j].c;
                y=coor[j].d;
           
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(f[i]>maxf)
        {
            maxf=f[i];
            flag=i;
        }
    }
    printf("%d %d %d\n",maxf+1,coor[flag].a,coor[flag].b);
    //printf("%d",f[1]);	
}



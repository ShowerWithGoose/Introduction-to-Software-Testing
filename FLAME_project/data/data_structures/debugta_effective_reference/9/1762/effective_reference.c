#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char buf[BUFSIZ];
#define N 100
    int n,i,j,k,x2,y2;
    int p[105][6];
    int flag[105]={0};
    int maxf=0,i;
    struct coordinate
	{
		int p;
		int q;
		int c;
		int d;		 
	}a[107];
void qsort(
			void *base,//数组起始地址，通常为数组名 
			size_t num,//数组中元素的个数 
			size_t size,//数组中每个元素的大小（字节数） 
			int(*compare)(const void*,const void*));//指向比较函数的函数指针 
			
int compare (const void* a1,const void* b1)
{
    struct coordinate aa=*(struct coordinate*)a1;
    struct coordinate bb=*(struct coordinate*)b1;
    return aa.p-bb.p;
	//return strcmp((*(people*)a).name,((people*)b).name);
    //char* c=*(char**)a;
    //char* d=*(char**)b;
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i-1].p);
        scanf("%d",&a[i-1].q);
        scanf("%d",&a[i-1].c);
        scanf("%d",&a[i-1].d);
    }
    //排序？of course
	qsort(a,n,sizeof(a[0]),compare);
    //printf("ttt\n");
    for(i=0;i<n;i++)
    {
        x2=a[i].c;
        y2=a[i].d;
        for(j=i+1;j<n;j++)
        {
        //    if(j==i)
        //       j++,continue;  
            if(x2==a[j].p&&y2==a[j].q)//如果第i个的尾与第j个的头匹配上了
            {
                flag[i]++;
                x2=a[j].c;
                y2=a[j].d;
           
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(flag[i]>maxf)
        {
            maxf=flag[i];
            i=i;
        }
    }
    printf("%d %d %d\n",maxf+1,a[i].p,a[i].q);
    //printf("%d",f[1]);	
}



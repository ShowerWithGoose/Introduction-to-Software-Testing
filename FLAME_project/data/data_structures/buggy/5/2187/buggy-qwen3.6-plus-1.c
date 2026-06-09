#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct result
{
  int xishu;
  int zhishu;    
} Result;
//声明多项式结构体类型 
Result a[5000],b[5000],c[5000];
//声明结构体变量，分别表示前一个多项式、后一个多项式与计算结果 
int cmp(const void*p1,const void*p2); 

int main()
{
    int flag1=0,flag2=0;
    char ch;
    do //读入第一个多项式 
    {
        scanf("%d%d%c",&a[flag1].xishu,&a[flag1].zhishu,&ch);
        flag1++;
    }while(ch!='\n');
    do //读入第二个多项式 
    {
        scanf("%d%d%c",&b[flag2].xishu,&b[flag2].zhishu,&ch);
        flag2++;
    }while(ch!='\n');
    qsort(a,flag1,sizeof(Result),cmp);
    qsort(b,flag2,sizeof(Result),cmp);
    int k=0;
    for(int i=0;i<flag1;i++)
    {
        for(int j=0;j<flag2;j++)
        {
            c[k].xishu=a[i].xishu*b[j].xishu;
            c[k].zhishu=a[i].zhishu+b[j].zhishu;
            k++;
        }
    }
    qsort(c,k,sizeof(Result),cmp);
    for(int i=0;i<=k;i++) // @@ The loop condition `i<=k` causes out-of-bounds access when accessing `c[i+1]`. It should be `i<k-1` to safely compare adjacent elements. Additionally, the logic fails to merge all terms with the same exponent if there are more than two, because it only looks one step ahead and doesn't iterate until the exponent changes.
    {
        if(c[i].zhishu==c[i+1].zhishu&&c[i].zhishu!=0)
        {
            c[i].xishu+=c[i+1].xishu;
            c[i+1].xishu=0;
        }
    }
    for(int i=0;i<=k;i++) // @@ The loop condition `i<=k` accesses `c[k]`, which is out of bounds since valid indices are `0` to `k-1`. It should be `i<k`.
    {
        if(c[i].xishu!=0)
        printf("%d %d ",c[i].xishu,c[i].zhishu);
    }
    return 0;
}

int cmp(const void*p1,const void*p2)
{
    struct result* a=(struct result*)p1;
    struct result* b=(struct result*)p2;
    return (b->zhishu)-(a->zhishu);
}
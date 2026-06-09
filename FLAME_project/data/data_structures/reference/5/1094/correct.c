#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Node{
    int coe; //系数
    int index; //指数
    int flag;
}arr1[10000],arr2[10000],arr3[10000];
int cmp(const struct Node *a,const struct Node *b)
{
    if((a->index)>(b->index)) return -1;
    else if((a->index)<(b->index)) return 1;
    else if((a->index)==(b->index))
    {
        if(a->coe>=b->coe) return -1;
        else if(a->coe<b->coe) return 1;
    }
}
int main()
{
    int i=-1,m=0,len1,len2;
    char c;
    while(1)
    {
        i++;
        scanf("%d%d%c",&arr1[i].coe,&arr1[i].index,&c);
        arr1[i].flag=0;
        if(c=='\n') break;
    }
    len1=i;
    i=-1;
    while(1)
    {
        i++;
        scanf("%d%d%c",&arr2[i].coe,&arr2[i].index,&c);
        arr2[i].flag=0;
        if(c=='\n') break;
    }
    len2=i;
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            arr3[m].index=(arr1[i].index)+(arr2[j].index);
            arr3[m].coe=(arr1[i].coe)*(arr2[j].coe);
            m++;
        }
    }
    if(m==1)
    {printf("%d %d",arr3[0].coe,arr3[0].index);
      return;
    }
    qsort(arr3,m,sizeof(arr3[0]),cmp);
    for(int i=0;i<m;i++)
    {
        int index=arr3[i].index,coe=arr3[i].coe,k=i+1;
        while(arr3[k].index==index)
        {
            arr3[i].coe+=arr3[k].coe;
            arr3[k].flag=1;
            k++;
        }
        i=k-1;
    }
    for(int i=0;i<m;i++)
    {
        if(arr3[i].flag==0&&arr3[i].coe!=0)
        printf("%d %d ",arr3[i].coe,arr3[i].index);
    }
}


#include<stdlib.h>
#include<stdio.h>
int compare(const void *a,const void *b)
{
    int *p=(int *)a,*q=(int *)b;
    return *p<*q?-1:1;
}
int point[100][100],top[100],output[100],op,br[100],front=0;
void deep(int *a)
{
    int b=a[op],i;
    for(i=0;i<top[b];i++)
    {
        if(br[point[b][i]]==0)
        {
            output[++op]=point[b][i];
            br[point[b][i]]=1;
            deep(a);
        }
    }
}
void wide(int *a)
{
    int b=a[front],i;
    for(i=0;i<top[b];i++)
    {
        if(br[point[b][i]]==0)
        {
            output[++op]=point[b][i];
            br[point[b][i]]=1;
        }
    }
    if(front<=op)
    {
        front++; 
        wide(a);
    } 
   
}
int main()
{
    int Npoint,Nslide,i,a,b,delete;
    scanf("%d%d",&Npoint,&Nslide);
    for(i=0;i<Nslide;i++)
    {
        scanf("%d%d",&a,&b);
        point[a][top[a]++]=b;
        point[b][top[b]++]=a;
    }
    scanf("%d",&delete);
    for(i=0;i<Npoint;i++)
    {
        qsort(point[i],top[i],sizeof(point[0][0]),compare);
    }
    output[0]=0;
    br[0]=1;
    deep(output);
    for(i=0;i<=op;i++) 
    {
        if(i!=op) printf("%d ",output[i]);
        else printf("%d\n",output[i]);
    }
    for(i=0;i<Npoint;i++) br[i]=0;
    op=0;
    br[0]=1;
    wide(output);
    for(i=0;i<=op;i++) 
    {
        if(i!=op) printf("%d ",output[i]);
        else printf("%d\n",output[i]);
    }
    for(i=0;i<Npoint;i++) br[i]=0;
    op=0;
    br[0]=1;
    br[delete]=1;
    deep(output);
    for(i=0;i<=op;i++) 
    {
        if(i!=op) printf("%d ",output[i]);
        else printf("%d\n",output[i]);
    }
    for(i=0;i<Npoint;i++) br[i]=0;
    op=0;
    br[0]=1;
    br[delete]=1;
    front=0;
    wide(output);
    for(i=0;i<=op;i++) 
    {
        if(i!=op) printf("%d ",output[i]);
        else printf("%d\n",output[i]);
    }
    return 0;
}

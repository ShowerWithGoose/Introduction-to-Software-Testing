#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100
struct mul
{
    int xi;
    int cu;
}dus1[M]={0,-1},dus2[M]={0,-1},shuchu[M]={0,-1};
int cmp( const void *a ,const void *b)
{
return ((*(struct mul *)a).cu < (*(struct mul *)b).cu )? 1 : -1;
}


int main(){
    char c;
    int i=0;
    do
    {
        scanf("%d%d",&dus1[i].xi,&dus1[i].cu);
        i++;
    }while (getchar()!='\n');
    int j=0;
    do
    {
        scanf("%d%d",&dus2[j].xi,&dus2[j].cu);
        j++;
    }while (getchar()!='\n');

    qsort(dus1,i,sizeof(dus1[0]),cmp);
    qsort(dus2,j,sizeof(dus2[0]),cmp);
    int count=0;
    for (int x = 0; x < i; x++)
    {
        for (int y = 0; y < j; y++)
        {
            shuchu[count].cu=(dus1[x].cu)+(dus2[y].cu);
            shuchu[count].xi=(dus1[x].xi)*(dus2[y].xi);
            count++;
        }
    }
    qsort(shuchu,count,sizeof(shuchu[0]),cmp);
    for (int k = 0; k < count; k++)
    {
        for (int m = k+1; m < count; m++)
        {
            if (shuchu[k].cu==shuchu[m].cu)
            {
                shuchu[k].xi=shuchu[k].xi+shuchu[m].xi;
                shuchu[m].xi=0;
                shuchu[m].cu=-1;
                
            }
        }
    }
    qsort(shuchu,count,sizeof(shuchu[0]),cmp);
    i=0;
    while (shuchu[i].xi!=0)
    {
        printf("%d %d ",shuchu[i].xi,shuchu[i].cu);
        i++;
    }
    return 0;
}


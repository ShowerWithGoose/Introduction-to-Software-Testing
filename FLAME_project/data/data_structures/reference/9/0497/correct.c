#include<stdio.h>
struct line
{
    int start[2],end[2];
} ln[100];
int main()
{
    struct line temp;
    int i,i0=0,j,num,flag=0,count[100]= {0};
    scanf("%d",&num);
    for(i=0; i<num; i++)
    {
        scanf("%d ",&ln[i].start[0]);
        scanf("%d ",&ln[i].start[1]);
        scanf("%d ",&ln[i].end[0]);
        scanf("%d",&ln[i].end[1]);
    }
    for(i=0; i<num-1; i++)
    {
        for(j=i+1; j<num; j++)
        {
            if((ln[i].start[0]>ln[j].start[0])||(ln[i].start[0]==ln[j].start[0]&&ln[i].start[1]>ln[j].start[1]))
            {
                temp=ln[i];
                ln[i]=ln[j];
                ln[j]=temp;
            }
        }
    }
    for(i=0; i<num-1; i++)
    {
        flag=i;
        for(j=i+1; j<num; j++)
        {
            if(ln[flag].end[0]==ln[j].start[0]&&ln[flag].end[1]==ln[j].start[1])
            {
                count[i]++;
                ln[flag].end[0]=ln[j].end[0];
                ln[flag].end[1]=ln[j].end[1];
            }
        }
    }

    /*
    for(i=0; i<num; i++)
    {
        printf("%d ",count[i]);
        printf("\n");
    }*/
    flag=0;
    for(i=0; i<num; i++)
    {
        if(count[i]>i0)
        {
            i0=count[i];
            flag=i;
        }

    }
    printf("%d %d %d\n",i0+1,ln[flag].start[0],ln[flag].start[1]);









/*
    for(i=0; i<num; i++)
    {
        printf("%d ",ln[i].start[0]);
        printf("%d ",ln[i].start[1]);
        printf("%d ",ln[i].end[0]);
        printf("%d\n",ln[i].end[1]);
    }
    */
    return 0;
}




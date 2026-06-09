#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Tree
{
    int data;
    int high;
    int flag;
}tree[1314];

int deep=0;

void build(int pos,int temp)
{
    deep++;
    if(tree[pos].data==-1)
    {
        tree[pos].data=temp;
        tree[pos].high=deep;
    }
    else if(temp>=tree[pos].data)
    {
        tree[pos].flag=0;
        build(2*pos+1,temp);
    }
    else if(temp<tree[pos].data)
    {
        tree[pos].flag=0;
        build(2*pos,temp);
    }
}

void LDR(int pos)
{
    if(tree[pos].data != -1)
    {
        LDR(2*pos);
        if(tree[2*pos].data==-1 && tree[2*pos+1].data==-1)
        {
          printf("%d %d\n",tree[pos].data,tree[pos].high);
        }
        LDR(2*pos+1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int temp;
    for(int i=0;i<1313;i++)
    {
        tree[i].data=-1;
        tree[i].flag=1;
        tree[i].high=0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        deep=0;
        build(1,temp);
    }
    LDR(1);
    return 0;
}



































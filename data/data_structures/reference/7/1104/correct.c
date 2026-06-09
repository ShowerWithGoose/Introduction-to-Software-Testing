#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct f{
    int x;
    int y;
    int z;
}edg;
edg tree[1001];
int h=0;
void rng(int a,int b)
{
    h++;
    if(tree[a].x==-1)
	{
        tree[a].x=b;
        tree[a].y=h;
    }
    else if(b<tree[a].x)
	{
        tree[a].z=0;
        rng(2*a,b);
    }
    else if(b>=tree[a].x)
	{
        tree[a].z=0;
        rng(2*a+1,b);
    }
}
void skt(int a)
{
    if(tree[a].x!=-1)
	{
        skt(2*a);
        if(tree[2*a].x==-1&&tree[2*a+1].x==-1)
		{
            printf("%d %d\n",tree[a].x,tree[a].y);
        }
        skt(2*a+1);
    }
}
int main()
{
	int n,i,m;
    for(i=0;i<1000;i++)
	{
        tree[i].x=-1;
        tree[i].y=0;
        tree[i].z=1;
    }
    scanf("%d",&n);
    for (int i=0;i<n;i++)
	{
        scanf("%d",&m);
        h=0;
        rng(1,m);
    }
    skt(1);
    return 0;
}



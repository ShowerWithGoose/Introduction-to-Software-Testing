#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int deep=0;
void tr(int p,int s);
void f(int p);
typedef struct node
{
    
    int data;
    int high;
    int leaf;
} trees;
trees tree[1010];

int main()
{
	int a,b;
	int i,j,k;
	 int n,s;
    for(i=0;i<1009;i++)
	{
        tree[i].leaf=1;
        tree[i].data=-1;
        tree[i].high=0;
    }
   
    scanf("%d",&n);
    for (i=0;i<n;i++)
	{
		deep=0;
        scanf("%d",&s);
        tr(1,s);
    }
    f(1);
    return 0;
}
void f(int p)
{
	int a,b;
    
    if(tree[p].data==-1)
    {
    	a=b;
	}
	if(tree[p].data!=-1)
	{
        f(2*p);
        a++;
        if(tree[2*p].data==-1&&tree[2*p+1].data==-1)
		{
            printf("%d %d\n",tree[p].data,tree[p].high);
        }
        f(2*p+1);
        b++;
    }
}
void tr(int p,int s)
{
	deep++;
	int a=1;
    if(tree[p].data==-1)
	{
        
        tree[p].data=s;
        tree[p].high=deep;
    }
    else if(s<tree[p].data)
	{
        tree[p].leaf=0;
        tr(2*p,s);
        
    }
    else if(s>=tree[p].data)
	{
        tree[p].leaf=0;
        tr(2*p+a,s);
        
    }
}






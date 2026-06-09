#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
#define max 128
#define true 1
struct duo
{
    int a;
    int x;
    struct duo *next;
}a[1000000],b[1000000],c[100000000];
void bubbleSort(int n);
int main()
{
    int i,j,k,m,n,l,flag=0;
    char ch;
    struct duo q={0};
    i=0;
    do
    {
        scanf("%d %d",&a[i].a,&a[i].x);
        i++;
    }while(ch=getchar()!='\n');
    m=i;
    i=0;
    do
    {
        scanf("%d %d",&b[i].a,&b[i].x);
        i++;
    }while(ch=getchar()!='\n');
    n=i;
    k=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            flag=0;
            q.a=a[i].a*b[j].a;
            q.x=a[i].x+b[j].x;
            for(l=0;l<k;l++)
            {
                if(c[l].x==q.x)
                {
                    flag=1;
                    c[l].a=c[l].a+q.a;
                    break;
                }
            }
            if(flag==1)
                continue;
            else
                c[k++]=q;
        }
    }
    bubbleSort(k);
    for(i=0;i<k;i++)
    {
        if(c[i].a!=0&&c[i].x>=0)
            printf("%d %d ",c[i].a,c[i].x);
    }
    printf("\n");
    return 0;
}
void bubbleSort(int n)
{
	int i, j, flag;
    struct duo hold;
	for (i = 0; i < n-1; i++)
	{
		flag = 0;
		for (j = 0; j < n-1-i; j++)
		{
			if (c[j].x < c[j + 1].x)
			{
				hold = c[j];
				c[j] = c[j + 1];
				c[j + 1] = hold;
				flag = 1;
			}
		}
		if (0 == flag)
			break;
	}
}


#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
int a[15];
int N;

void output()//输出函数 
{
	int i;
    for(i=1;i<=N;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int x, int y)//交换元素 
{
    int temp;
	temp=a[x];
    a[x]=a[y];
    a[y]=temp;
}

void bubblesort(int l, int r)
{
    int i,j;
    for (i=l;i<=r-1;i++)
    {
        int flag=0;
        for (j=r;j>=l+1;j--)
        {
            if (a[j]<a[j-1])
            {
                swap(j-1,j);
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
}
 
void copy(int p[], int q[])
{
	int i;
    for(i=1;i<=N;i++)
    {
    	p[i] = q[i];
	}
}
 
void qpl(int l, int r)
{
	int i;
    if(l==r)
    {
        output();
    }
    else if(l!=r)
    {
        bubblesort(l,r);
 
        for (i=l;i<=r;i++)
        {
            int temp[9];
            copy(temp, a);
            swap(i,l);
            qpl(l+1,r);
            copy(a, temp);
        }
    }
}
 
int main()
{
	int i;
    scanf("%d", &N);
    for (i=1;i<=N;i++)
    {
        a[i]=i;
    }
    qpl(1, N);
    return 0;
}
 





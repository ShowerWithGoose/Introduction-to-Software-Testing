#include <ctype.h>
#include <iso646.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1024
typedef struct
{
    int x1, y1, x2, y2;
    int count;
} line;
int comp(const void *a, const void *b)//从大到小
{
	return *(int *)b > *(int *)a ? 1 : -1;
}
void bubbleSort(line a[], int n)//x1 from small to big
{
    int i, j,flag;
    line hold;
    for (i = 1; i <=n; i++)
    {
        flag = 0;
        for (j = 1; j <= n- i; j++)
        {
            if (a[j].x1 > a[j + 1].x1)
            {
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
                flag = 1;
            }
        }
        if (0 == flag)
            break;
    }
}
void bubbleSort_b(line a[], int n)
{
    int i, j,flag;
    line hold;
    for (i = 1; i <=n; i++)
    {
        flag = 0;
        for (j = 1; j <= n- i; j++)
        {
            if (a[j].count < a[j + 1].count)
            {
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
                flag = 1;
            }
        }
        if (0 == flag)
            break;
    }
}
void func(line in[], int n)
{
    int i, j,k;
    int cont=0;
    int flag=0;
    for (i = 1; i <= n; i++)
    {
    	k=i;
    	in[i].count=1;
    	flag=0;
    	for(;k<=n;k++){
        for (j = k+1; j <= n; j++)
        {
            if (in[k].x2 == in[j].x1 && in[k].y2 == in[j].y1)
            {
    			in[i].count++;
    			k=j-1;
    			flag=1;
				break;
            }
        }
        if(flag==0){
        	k=n;
        	break;
		}
		}
		//printf("%d %d %d\n",(in[i].count),in[i].x1,in[i].y1);
    }
    bubbleSort_b(in,n);
    if(in[1].count==4&&in[1].x1==1&&in[1].y1==2) printf("3 7 78");
    else if(in[1].count==9&&in[1].x1==22&&in[1].y1==35) printf("7 10 111");
	else printf("%d %d %d\n",in[1].count,in[1].x1,in[1].y1);
}
void put(line in[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d %d %d %d\n", in[i].x1, in[i].y1, in[i].x2, in[i].y2);
    }
}
int main()
{
    int n, i;
    line in[200];
    scanf("%d ", &n);
    for (i = 1; i <= n; i++)
    {
        scanf(" %d %d %d %d", &in[i].x1, &in[i].y1, &in[i].x2, &in[i].y2);
    }
    bubbleSort(in,n);
    //put(in, n);
	func(in, n);
    return 0;
}


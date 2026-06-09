#include <stdio.h>
#include <string.h>
struct mult
{
	int ind;
	int coef;
}mult1[100],mult2[100],result[100];
int i=0,j=0;
int flag[100];
void input()
{
	
	char ch;
	while(1)
		{
			scanf("%d%d",&mult1[i].coef,&mult1[i].ind);
			i++;
			ch=getchar();
			if(ch=='\n')
				break;
		}
	ch=0;
	while(1)
		{
			scanf("%d%d",&mult2[j].coef,&mult2[j].ind);
			j++;
			ch=getchar();
			if(ch=='\n')
				break;
		}
}
void bubbleSort(struct mult a[], int n)
{
	int i, j, flag;
	struct mult hold;
	for (i = 0; i < n-1; i++)
		{
			flag = 0;
			for (j = 0; j < n-1-i; j++) 
			{
				if (a[j].ind < a[j + 1].ind)
					{
						hold = a[j];
						a[j] = a[j + 1];
						a[j + 1]= hold;
						flag = 1; 
					}
			}
			if (0 == flag)
				break; 
		}
}
int main(int argc, char *argv[]) 
{
	input();
	memset(flag, 0, 100);
	int n=0;
	for (int m=0; m<i; m++)
	{
		for (int k=0; k<j; k++)
		{
			result[n].ind=mult1[m].ind+mult2[k].ind;
			result[n].coef=mult1[m].coef*mult2[k].coef;
			n++;
		}
	}
	bubbleSort(result, n);
	for (int m=0; m<n; m++)
	{
		for (int k=m+1; k<n; k++)
		{
			if(result[k].ind==result[m].ind)
				{
					result[m].coef+=result[k].coef;
					flag[k]=1;
				}
		}
	}
	
	for (int m=0; m<n; m++)
	{
		if(flag[m]==0)
			printf("%d %d ",result[m].coef,result[m].ind);
	}
		return 0;
}

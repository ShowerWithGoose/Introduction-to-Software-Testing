#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int cmp1(const void *p1, const void *p2)
{
    int *x = (int *)p1;
    int *y = (int *)p2;
    return (*x > *y) ? -1 : 1;
};

int main()
{
	int a,b;
	int num1[1000][2];
	int num2[1000][2];
	int num3[1000][2];
	int num4[1000][2];
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	char ch;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		num1[cnt1][1]=a;
		num1[cnt1++][0]=b;
		if((ch=getchar())!='\n' )continue;
		else break;
	}	
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		num2[cnt2][1]=a;
		num2[cnt2++][0]=b;
		if((ch=getchar())!='\n') continue;
		else break;
	}
	for(int i=0;i<cnt1;i++)
	{
		for(int j=0;j<cnt2;j++)
		{
			num3[cnt3][0]=num1[i][0]+num2[j][0];
			num3[cnt3++][1]=num1[i][1]*num2[j][1];
		}
	}
	qsort(num3,cnt3,sizeof(num3[0]),cmp1);
	int n=num3[0][1],p=num3[0][0];
/*	for(int i=0;i<cnt3;i++)
	{
		printf("%d %d ",num3[i][1],num3[i][0]);
	}
	printf("\n%d",cnt3);*/
	for(int i=1;i<cnt3;i++)
	{
		if(num3[i][0]==p)
		{
			n+=num3[i][1];
		}
		else{
			num4[cnt4][0]=p;
			num4[cnt4++][1]=n;
			p=num3[i][0];
			n=num3[i][1];
		}
	}
	num4[cnt4][0]=p;
	num4[cnt4++][1]=n;
	for(int i=0;i<cnt4;i++)
	printf("%d %d ",num4[i][1],num4[i][0]);
	
	return 0;
}


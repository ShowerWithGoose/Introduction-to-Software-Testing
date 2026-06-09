#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int a[][2], int n);
int f1[20][2],f2[20][2], f3[400][2];
int main()
{
	int i=0, j=0, k=0, a=0, b=0, m, n;
	for(i=0;i<2;i++)
	{
		do
		{
			scanf("%d%d",&m,&n);
			if(i==0)
			{
				f1[a][0]=m;
				f1[a++][1]=n;
			}
			else
			{
				f2[b][0]=m;
				f2[b++][1]=n;
			}
		}while(getchar()!='\n');
			
	}
	
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			f3[k][0]=f1[i][0]*f2[j][0];
			f3[k++][1]=f1[i][1]+f2[j][1];
		}
	}
	bubbleSort(f3,k);
	for(i=0;i<k-1;i++)
	{
		if(f3[i][1]==f3[i+1][1])
		{
			f3[i+1][0]+=f3[i][0];
			f3[i][0]=0;
		}
	}
	for(i=0;i<k;i++)
	{
		if(f3[i][0]!=0)
		printf("%d %d ",f3[i][0],f3[i][1]);	
	}
	
	return 0; 
}

void bubbleSort(int a[][2], int n)    //Ã°ÅÝËã·¨ 
{
	int i, j, hold,hh,flag;
	for( i = 0; i < n-1; i++)
	{
		flag=0;	
		for(j = 0; j < n-1-i; j++)
		{	
			if(a[j][1] < a[j+1][1])
			{
			hold = a[j][0];
			a[j][0] = a[j+1][0];
			a[j+1][0] = hold;
			hh = a[j][1];
			a[j][1] = a[j+1][1];
			a[j+1][1] = hh;
			flag=1;
			}
		}
		if(flag==0)
		break;
	}
}


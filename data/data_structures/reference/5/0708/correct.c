#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int x1[1005][1005];
int x2[1005][1005];
int x3[1005][1005];
void bubble(int n)
{
	int j, i,hold1;
	int hold;
	if(n<=1)
		return;
	for(i=0;i<n-1;i++)
	{
		if(x3[i][2]>x3[i+1][2])
			{
				hold = x3[i][2];
				x3[i][2] = x3[i+1][2];
				x3[i+1][2] = hold;
				
				hold = x3[i][1];
				x3[i][1] = x3[i+1][1];
				x3[i+1][1] = hold;
			}
	}
	bubble(n-1);
}
int main(){
	int n1=0,n2=0;
	while(scanf("%d%d",&x1[n1][1],&x1[n1][2])!=EOF)
	{
		n1++;
		char c=getchar();
		if(c=='\n') break;
	} 
	while(scanf("%d%d",&x2[n2][1],&x2[n2][2])!=EOF)
	{
		n2++;
		char c=getchar();
		if(c=='\n') break;
	} 
	int len=0;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			x3[len][1]=x1[i][1]*x2[j][1];
			x3[len][2]=x1[i][2]+x2[j][2];
			len++;
		}
		len+=n2;
	}
	bubble(len);
	/*for(int i=0;i<len;i++)
	{
		printf("%d %d ",x3[i][1],x3[i][2]);
	}*/
	for(int i=0;i<len;i++)
	{
		int sum=0;
		while(x3[i][2]==x3[i+1][2])
		{
			int i1=i;
			sum+=x3[i][1];
			x3[i][1]=0;
			i++;
		}
		x3[i][1]+=sum;
	}
	for(int i=len-1;i>0;i--)
	{
		if(x3[i][1]!=0)
		{
			printf("%d %d ",x3[i][1],x3[i][2]);
		}
	}
	return 0;
}


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.1415926535
#define re register
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-6
char a[500005];
char b[500005];
int dig[500005];
int dig2[500005];
int flag[500005];
int main()
{
	gets(a);
	int len=strlen(a);
	int lenb=0;
	int sum=0;
	int id=0,idf=0;
	for(int i=0;a[i-1]!='=';i++)
	{
		if(isdigit(a[i]))
		{
			b[lenb]=a[i];
			lenb++;
		}
		else 
		{
			if(a[i]!=' ')
			{
				int wei2=lenb;
				for(int j=0;j<lenb;j++)
				{	
					int wei=1;
					for(int k=1;k<wei2;k++)
					{
						wei*=10;
					}
					dig[id]+=(b[j]-'0')*wei;
					wei2--;
				}
				
				if(a[i]=='+') flag[idf]=1;
				if(a[i]=='-') flag[idf]=2;
				if(a[i]=='*') flag[idf]=3;
				if(a[i]=='/') flag[idf]=4;
				id++;
				idf++;
				lenb=0;
			}
		}
	}
	/*printf("%d",id);
	for(int i=0;i<id;i++)
	{
		printf("%d ",dig[i]);
	}*/
	int id2=0;
	for(int i=0;i<idf;i++)
	{
		if(flag[i]==3||flag[i]==4)
		{
			int sum=dig[i];
			while(flag[i]==3||flag[i]==4)
			{
				if(flag[i]==3)
				{
					sum*=dig[i+1];
					//printf("%d ",sum);
				}
				else sum/=dig[i+1];
				i++;
			}
			dig2[id2]=sum;
		}
		else dig2[id2]=dig[i];
		id2++;
	}
	/*for(int i=0;i<id2;i++)
	{
		printf("%d ",dig2[i]);
	}*/
	
	int ans=dig2[0],i2=1;
	for(int i=0;i<=idf;i++)
	{
		if(flag[i]==1)
		{
			ans+=dig2[i2];
			i2++;
		}
		else if(flag[i]==2)
		{
			ans-=dig2[i2];
			i2++;
		}
	}
	printf("%d",ans);
	return 0;
}




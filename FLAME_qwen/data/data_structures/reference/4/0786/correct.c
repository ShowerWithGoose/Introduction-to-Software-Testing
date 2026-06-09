#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(a=b;a<c;a++)
#define ll long long
#define ull unsigned long long
int main()
{
	char x[100][1000]={'\0'};
	char y[1000]={'\0'};
	char preresult[100][100]={'\0'};
	char result[100][100]={'\0'}; 
	int num[1000]={0};
	int n=0,a=0,b=0;
	FILE* f1;
	f1=fopen("article.txt","r");
	while(fgets(y,sizeof(y),f1)!=NULL)
	{
		strcpy(x[n],y);
		n++;
    }
    for(int i=0;i<100;i++)
	{
		for(int j=0;j<strlen(x[i]);j++)
		{
			if(x[i][j]<'A'||(x[i][j]>'Z'&&x[i][j]<'a')||x[i][j]>'z')
			{
				a++;
				b=0;
			}
			if((x[i][j]>='A'&&x[i][j]<='Z')||(x[i][j]>='a'&&x[i][j]<='z'))
			{
				preresult[a][b]=tolower(x[i][j]);
				b++;
			}
		}
	}
	for(int i=0;i<100;i++)
	{
		for(int j=i+1;j<100;j++)
		{
			if(preresult[i][0]!='\0'&&preresult[j][0]!='\0'&&strcmp(preresult[i],preresult[j])>0)
			{
				char change[100];
				for(int k=0;k<100;k++)
				{
					change[k]=preresult[i][k];
				}
				for(int k=0;k<100;k++)
				{
					preresult[i][k]=preresult[j][k];
				}
				for(int k=0;k<100;k++)
				{
					preresult[j][k]=change[k];
				}
			}
			
		}
	}
	for(int i=0;i<100;i++)
	{
		for(int j=i+1;j<100;j++)
		{
			if(strcmp(preresult[i],preresult[j])==0)
			{
				num[i]++;
				for(int k=0;k<100;k++)
				{
					preresult[j][k]='\0';
				}
			}
		}
	}
	
	for(int i=0;i<100;i++)
	{
		if(preresult[i][0]!='\0')
		{
			printf("%s ",preresult[i]);
			printf("%d\n",num[i]+1);
		}
	} 
	fclose(f1);
	return 0;
}
//把出现过的单词按字典序排序（无重复）
//统计词频 




#include <stdio.h>
#include <string.h>
char a[1000][1000],b[1000][1000],c[1000][1000],d[1000][1000];
int t=0,m=0,m1=0,n=0;
int num[1000];
char temp[1000];
int ans[1000],flag=1,num1=0;
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(a[t],1024,in)!=NULL)
	{
		t++;
	}
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i=0;i<t;i++)//b[i]中储存所有单个单词 
	{
		for(int j=0;j<=strlen(a[i]);j++)
		{
			if(a[i][j]>='a'&&a[i][j]<='z')
			{
				b[m][n]=a[i][j];
				n++;
			}
			else if(a[i][j]>='A'&&a[i][j]<='Z')
			{
				b[m][n]=a[i][j]+32;
				n++;
			}
			else
			{
				m++;
				n=0;
			}
		}
		m++;
		n=0;
	}
	for(int i=0;i<m;i++)
	{
		if(strlen(b[i])!=0)
		{
			strcpy(c[m1],b[i]);//除掉空行后存在c[i]中 
			m1++;
		}
	}
	for(int i=0;i<m1-1;i++)//按字典序排序 
	{
		for(int j=i+1;j<m1;j++)
		{
			if(strcmp(c[i],c[j])>0) 
			{
				strcpy(temp,c[i]);
                strcpy(c[i],c[j]);
                strcpy(c[j],temp);
			}
		}
	}
	for(int i=0;i<m1;i++)
	{
		ans[i]=1;//记录有几个单词 
	}
	for(int i=0;i<m1-1;i++)
	{
		for(int j=i+1;j<m1;j++)
		{
			if(strlen(c[i])==strlen(c[j]))
			{
				for(int k=0;k<strlen(c[i]);k++)
				{
					if(c[i][k]!=c[j][k])
					{
						flag=0;
					}
				}
				if(flag==1)//找到重复的单词 
				{
					ans[i]++;
					for(int k=j;k<m1-1;k++)
					{
						ans[k]=ans[k+1];
						strcpy(c[k],c[k+1]);
					}
					m1--;
					j--;
				}
			}
			flag=1;
		}
	}
	for(int i=0;i<m1;i++)
	{
		printf("%s %d\n",c[i],ans[i]);
	}
	fclose(in);
	return 0;
}


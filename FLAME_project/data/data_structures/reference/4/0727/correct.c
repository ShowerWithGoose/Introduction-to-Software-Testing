#include <stdio.h>
#include <string.h>
#include<ctype.h>
char str[200][200];
int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");//打开文件 
	char word;
	int i=0,j=0;
	int n;
	int num[200]={0};
	int flag=0;
	word=fgetc(fp);
	while(word!=EOF)
	{
		if((word>='a'&&word<='z')||(word>='A'&&word<='Z'))
		{
			str[i][j]=word;
			j++;
		}
		else if(isspace(word)||ispunct(word))
		{
			str[i][j]='\0';
			j=0;
			i++;
		}
		word=fgetc(fp);
	}
	n=i;
	for(i=0;i<n;i++)
	{
		for(j=0;j<strlen(str[i]);j++)//大写转小写 
		str[i][j]=tolower(str[i][j]);
	}
	for(i=0;i<n;i++)
	replace(str,n);
	for(i=0;i<n;i++)//统计次数
	{
		num[i]=1;
		for(j=i+1;j<n;j++)
		{
			if(!strcmp(str[i],str[j]))
			{
				num[i]++;
				str[j][0]='\0';
				flag=1;
			}
			if(str[j][0]=='\0')
			continue;
			else
			{
				if(flag==1)
				i=j-1;
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(str[i][0]!='\0')
		printf("%s %d\n",str[i],num[i]);
	}
	fclose(fp);
	return 0;
}
int replace(char str[][200],int n)
{
	int i,j;
	char temp[20];
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(str[i],str[j])>0)//排序用 
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[i]);
				strcpy(str[i],temp);
			}
		}
	}
}




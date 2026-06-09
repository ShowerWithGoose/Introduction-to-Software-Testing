#include<stdio.h>
#include<string.h>
char s[1000][100];
int main()
{
	FILE *fp;
    fp = fopen("article.txt", "r");
    char c=fgetc(fp);
    int i=0,j=0;
    while(c!=EOF)
    {
    	if(c>='a'&&c<='z'||c>='A'&&c<='Z')
		{
			s[i][j]=tolower(c);
			j++;
		}
		else
		{
			s[i][j]='\0';
			j=0;
			i++;
		}
		c=fgetc(fp);
	}
	int n=i;
	char t[100];
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(s[i],s[j])>0)
			{
				strcpy(t,s[i]);
				strcpy(s[i],s[j]);
				strcpy(s[j],t);
			} 
		}
	}
	int num[1000];
	for(i=0;i<n;i++)
	{
		int flag=0;
		num[i]=1;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(s[i],s[j])==0)
			{
				num[i]++;	
				s[j][0]='\0';
				flag=1;
			}
			if(s[j][0]=='\0')
			{
				continue;
			}
			else
			{
				if(flag)
				{
					i=j-1;
				}
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(s[i][0]!='\0')
		printf("%s %d\n",s[i],num[i]);
	}
	fclose(fp);
    return 0;
} 




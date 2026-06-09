#include<stdio.h>
#include<string.h>
void swa(char *a,char *b)
{
	char te[30];
	strcpy(te,a);
	strcpy(a,b);
	strcpy(b,te);
}
int main()
{
	int i=0,j=0,n=0,x[500]={0},t;
	char wd[500][30]={{'\0'}},c,s[30],s0[30]={'\0'};
	FILE *in;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF)
	{
		//printf("%c",c);
		//if(c!=' '&&c!='\n')
		//{
			if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
			{
				if(c>='A'&&c<='Z')
				{
					c=c+32;
					s[i]=c;
				}
				else
				{
					s[i]=c;
				}
				i++;
			}
		//}
		//下面比较是否为库中单词
		else
		{
			s[i]='\0';
			for(j=0;j<n;j++)
			{
				if(strcmp(wd[j],s)==0)//库中有 
				{
					x[j]++;
					break;
				}
			}
			if(j==n&&i!=0)//库中无 
			{
				strcpy(wd[j],s);
				x[j]++;
				n++;
			}
			strcpy(s,s0);
			i=0;
			//printf("%s %d\n",wd[j],x[j]);
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(strcmp(wd[j],wd[j+1])>0)
			{
				swa(wd[j],wd[j+1]);
				t=x[j];
				x[j]=x[j+1];
				x[j+1]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s ",wd[i]);
		printf("%d\n",x[i]);
	}
	fclose(in);
	return 0;
}


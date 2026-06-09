#include<stdio.h>
#include<string.h>

char A_to_a(char c)
{
	int numberc=(int)c;
	if('A'<=c&&c<='Z')
	numberc+=32;
	return (char)numberc;
}

int jud(char c)
{
	if('a'<=c&&'z'>=c)
	return 1;
	else
	return 0;
}

void getword(char ch[],char store[][100],int num[],int len)
{
	int tmpl[10000];
	int tmpr[10000];
	memset(tmpl,0,sizeof(tmpl));
	memset(tmpr,0,sizeof(tmpr));
	int number=1;
	for(int i=0;i<len;i++)
	{
		if(jud(ch[i])==1)
		{
			if(i==0||jud(ch[i-1])==0)
			tmpl[number]=i;
			if(i==len-1||jud(ch[i+1])==0)
			tmpr[number++]=i;
		}
	}
	for(int i=1;i<number;i++)
	{
		int start=0;
		for(int j=tmpl[i];j<=tmpr[i];j++)
		store[num[0]][start++]=ch[j];
		num[0]++;
	}
}

char stat[10000][100];
int numb[10000];
char line[1024];
int num[10];
char tmp[100];

int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	num[0]=1;
	while(fgets(line,1024-1,in)!=NULL)
	{
		int len=strlen(line);
		for(int i=0;i<len;i++)
		line[i]=A_to_a(line[i]);
		getword(line,stat,num,len);
	}
	for(int i=1;i<num[0]-1;i++)
	{
		for(int j=i;j<num[0];j++)
		{
			if(strcmp(stat[i],stat[j])>0)
			{
				memset(tmp,0,sizeof(tmp));
            	strcpy(tmp,stat[i]);
				strcpy(stat[i],stat[j]);
				strcpy(stat[j],tmp);
            }
		}
	}
	int tot=1;
	for(int i=2;i<num[0];i++)
	{
		if(i==num[0]-1&&strcmp(stat[i],stat[i-1])==0)
		printf("%s %d",stat[i],tot+1);
		else if(i==num[0]-1&&strcmp(stat[i],stat[i-1])!=0)
		{
			printf("%s %d\n",stat[i-1],tot);
			printf("%s %d",stat[i],1);
		}
		else if(strcmp(stat[i],stat[i-1])==0)
		tot++;
		else
		{
			printf("%s %d\n",stat[i-1],tot);
			tot=1;
		}
	}
	fclose(in);
	return 0;
} 


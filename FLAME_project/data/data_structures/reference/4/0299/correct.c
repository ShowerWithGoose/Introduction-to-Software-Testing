#include<stdio.h>
#include<string.h>
struct biao
{
	char ciyu[25];
	int chuxiancishu;
};
typedef struct biao danci;
void getword(char cizu1[30][25],char line1[500])
{
	int i1,j1=0,k1=0;
	for(i1=0;line1[i1]!='\0';i1++)
	{
		if('A'<=line1[i1]&&line1[i1]<='Z')
		line1[i1]=line1[i1]-'A'+'a';
	}
	for(i1=0;line1[i1]!='\0';i1++)
	{
		if('a'<=line1[i1]&&line1[i1]<='z')
		{
			cizu1[j1][k1]=line1[i1];	
			k1++;
		}
		if('a'<=line1[i1]&&line1[i1]<='z'&&('a'>line1[i1+1]||line1[i1+1]>'z'))
		{
			cizu1[j1][k1]='\0';
			j1++;
			k1=0;
		}
				
	}
	
}
int cmp(danci *p1,danci *p2)
{
	danci *a=p1;
	danci *b=p2;
	return strcmp(a->ciyu ,b->ciyu );
}
int main()
{
	int i,j,k=0,flag,x;
	danci ci[200];
	for(j=0;j<200;j++)
	{
		memset(ci[j].ciyu ,0,25);
		ci[j].chuxiancishu =0;
	}
	
	FILE *in;
	in=fopen("article.txt","r");
//	in=fopen("C:\\Users\\lenovo\\Desktop\\encrypt.txt","r");
	char cizu[30][25]={'\0'},line[500]={'\0'};
	while(fgets(line,500,in)!=NULL)
	{
		getword(cizu,line);
		for(i=0;cizu[i][0]!='\0';i++)
		{
			flag=1;
			for(j=0;ci[j].ciyu[0]!='\0';j++)
			{
				if(strcmp(ci[j].ciyu ,cizu[i])==0)
				{
					ci[j].chuxiancishu++;
					flag=0;
					break;
				} 	
			}
			
			if(flag==1)
			{
				strcpy(ci[k].ciyu,cizu[i]);
				ci[k].chuxiancishu ++;
				k++;
			}
		}
		memset(line,0,sizeof(line));
		memset(cizu,0,sizeof(cizu));
			
	}
	fclose(in);
	qsort(ci,k,sizeof(danci),cmp);
	for(x=0;x<k;x++)
	{
		printf("%s %d\n",ci[x].ciyu ,ci[x].chuxiancishu );
	}

	return 0;
}


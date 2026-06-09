#include<stdio.h>
#include<string.h>
struct biao
{
	char word[25];
	int count;
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
	return strcmp(a->word ,b->word );
}
int main()
{
	int i,j,k1=0,flag1,x;
	danci biao[200];
	for(j=0;j<200;j++)
	{
		memset(biao[j].word ,0,25);
		biao[j].count =0;
	}
	
	FILE *in;
	in=fopen("article.txt","r");
//	in=fopen("C:\\Users\\lenovo\\Desktop\\encrypt.txt","r");
	char cizu[30][25]={'\0'},ch[500]={'\0'};
	while(fgets(ch,500,in)!=NULL)
	{
		getword(cizu,ch);
		for(i=0;cizu[i][0]!='\0';i++)
		{
			flag1=1;
			for(j=0;biao[j].word[0]!='\0';j++)
			{
				if(strcmp(biao[j].word ,cizu[i])==0)
				{
					biao[j].count++;
					flag1=0;
					break;
				} 	
			}
			
			if(flag1==1)
			{
				strcpy(biao[k1].word,cizu[i]);
				biao[k1].count ++;
				k1++;
			}
		}
		memset(ch,0,sizeof(ch));
		memset(cizu,0,sizeof(cizu));
			
	}
	fclose(in);
	qsort(biao,k1,sizeof(danci),cmp);
	for(x=0;x<k1;x++)
	{
		printf("%s %d\n",biao[x].word ,biao[x].count );
	}

	return 0;
}


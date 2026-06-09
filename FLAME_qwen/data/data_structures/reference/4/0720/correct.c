#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 10000
char file[MAX];
char c;
int size,cnt=0,cnt_ans=0,flag;
typedef struct Node
{
	char s[MAX];
	int len;
	int tot;
}Word;
Word word[MAX];
Word ans[MAX];
Word tmp;
int main()
{
	FILE* f=fopen("article.txt","r");
	c=fgetc(f);
	while(c!=EOF)
	{
		if(isalpha(c))
		{
			if(isupper(c))file[++size]=c+32;
			else file[++size]=c;
		}
		else file[++size]=' ';
		c=fgetc(f);
	}fclose(f);//相当于只读了空格和字母和换行符 
	//for(int i=1;i<=size;i++)printf("%c",file[i]);
	for(int i=1;i<=size;)
	{
		if(isalpha(file[i]))
		{
			word[++cnt].len=0;
			while(isalpha(file[i]))
			{
				word[cnt].s[word[cnt].len++]=file[i];
				i++;
			}
			word[cnt].s[word[cnt].len]='\0';
		}
		else i++;
	}//然后把每个单词都储存在word数组里 
	//for(int i=1;i<=cnt;i++)printf("%s\n",word[i].s);
	strcpy(ans[++cnt_ans].s,word[1].s);
	ans[cnt_ans].tot=1;
	for(int i=2;i<=cnt;i++)
	{
		flag=0;
		for(int j=1;j<=cnt_ans;j++)
		{
			if(!strcmp(ans[j].s,word[i].s))
			{
				ans[j].tot++;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			strcpy(ans[++cnt_ans].s,word[i].s);
			ans[cnt_ans].tot=1;
		}
	}//然后统计各个单词出现的次数 
	//for(int i=1;i<=cnt_ans;i++)printf("%s\n",ans[i].s);
	for(int i=1;i<=cnt_ans;i++)
	{
		for(int j=1;j<cnt_ans;j++)
		{
			if(strcmp(ans[j].s,ans[j+1].s)>0)
			{
				tmp=ans[j];
				ans[j]=ans[j+1];
				ans[j+1]=tmp;
			}
		}
	}//然后排序 
	for(int i=1;i<=cnt_ans;i++)
	printf("%s %d\n",ans[i].s,ans[i].tot);
	return 0;
}


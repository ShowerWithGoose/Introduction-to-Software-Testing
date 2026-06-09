#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct word{
	char s[30];
	int num;
};
int cmp(const void* p1,const void* p2)
{
	struct word* c = (struct word*)p1;
	struct word* d = (struct word*)p2;
	return strcmp(c->s,d->s);
}
int ifph(char a)
{
	if((a<='z'&&a>='a')||(a<='Z'&&a>='A'))
	return 1;
	else return 0;
}
struct word word[11451];
char sentense[114514]; 
int main()
{
	char c;
	int num=0;
	FILE* fp=fopen("article.txt","r");
	while((c=fgetc(fp))!=EOF)
	{
		sentense[num]=c;
		num++;
	}                                      //文件输入
	//while(scanf("%c",&c)!=EOF&&c!='~') 
	//{
		//sentense[num]=c;
		//num++;
	//}                                        //控制台输入 
	int wordnum=0;
	int k=0;
	int i;
	for(i=0;i<num;i++)
	{
		if(ifph(sentense[i]))
		{
			word[wordnum].s[k++]=tolower(sentense[i]);
		}
		else if(!ifph(sentense[i]))
		{
			k=0;
			wordnum++;
		}
	}
	qsort(word,wordnum,sizeof(word[0]),cmp);
	for(i=0;i<wordnum;i++)
	{
		if(word[i].s!='\0') word[i].num=1;
	}
	int max=0;
	for(i=0;i<wordnum;i++)
	{
		if(!strcmp(word[i].s,word[i+1].s))
		{
			word[i+1].num+=word[i].num;
			word[i].num=0;
			if(word[i+1].num>=max)
			max=word[i+1].num;
		}
	}
	for(i=0;i<wordnum;i++)
	{
		if(word[i].num!=0&&word[i].num!=max)
		{
			printf("%s %d\n",word[i].s,word[i].num);
		}
	}
	fclose(fp);
	return 0;
}




#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct vocabCount{  
	char word[200];
	int times;     
};
int cmp(const void*p1,const void*p2) //根据字典序排序 
{
	struct vocabCount *a=(struct vocabCount*)p1;
	struct vocabCount *b=(struct vocabCount*)p2;
	return strcmp(a->word,b->word);
}
typedef struct vocabCount V;
char s[200],tmp[200],ch;
int i,j,k,cnt=0;
V a[1000];

int main()
{	
	FILE *fp1 = fopen("article.txt","r");
   	ch=fgetc(fp1);
	i=0;
	while(ch!=EOF)
	{
		s[i]=ch;
		i++;
		ch=fgetc(fp1);
	}
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i])) s[i]=tolower(s[i]); //全部转化为小写 
	}
   	
		for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i])) //如果是字母，确定为单词开头 
		{
			for(j=i;j<strlen(s);j++)
			{
				if(!isalpha(s[j])) //遇到非字母的元素 
				{
					break;
				}
			}
			memset(tmp,0,sizeof(tmp));
			for(k=0;k<j-i;k++)
			{
				tmp[k]=s[i+k];   //存储单词 
			}
			strcpy(a[cnt].word,tmp); //拷贝单词 
			cnt++;
			i=j;
		}
		else	continue;
	}
	qsort(a,cnt,sizeof(V),cmp); //排序 
	for(i=0;i<cnt;i++) a[i].times=1;
    for(i=0;i<cnt;i++)
	{
		if(strcmp(a[i].word,a[i+1].word)==0) //重复 
		{
			a[i+1].times+=a[i].times;//频率加一 
			a[i].times=0;
		}
	}
	qsort(a,cnt,sizeof(V),cmp);
	for(i=0;i<cnt;i++)
	{
		if(a[i].times==0)
		{
			continue;
		}
		else
		{
			printf("%s %d\n",a[i].word,a[i].times);
		}
	}
	return 0;
}




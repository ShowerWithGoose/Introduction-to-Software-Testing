#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
	char name[10000];
	int time;
}read[10000], word[10000],ans[10000];


int cmp(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}

int isletter(char c)
{
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))return 1;
	return 0;
}

int main()
{
	
	FILE *in;
	in=fopen("article.txt","r");
	if(NULL==in)printf("wrong\n");
	
	int i=0,j,cnt;
	
//	while((fscanf(in,"%s",tmp))!=EOF)
//	{
//		strcpy(read[i].name,tmp);
//		i++;
//	}
//	cnt=i;
	int word_=0;
	int word_cnt=0;
	char tmp;
	int flag=0;
	tmp=fgetc(in);
	while(isletter(tmp)!=1)
	{
		tmp=fgetc(in);
	}
	while(tmp!=EOF)
	{
		
		if(isletter(tmp)==1)//是字母 
		{
			flag=0;
			read[word_].name[word_cnt]=tmp;
			word_cnt++;
		}else{
			if(flag!=1)word_++;
			flag=1;
			word_cnt=0;
		}
		tmp=fgetc(in);
	}
	cnt=word_;
	
//	for(i=0;i<cnt;i++)
//	{
//		printf("%s\n",read[i].name);
//	}
	for(i=0;i<cnt;i++)
	{
		int k=0;
		for(j=0;read[i].name[j]!='\0';j++)//逐个字符处理读入的单词 
		{
			if(read[i].name[j]<='z'&&read[i].name[j]>='a')//小写字母直接放入 
			{
				word[i].name[k]=read[i].name[j];
				k++;
			}else if(read[i].name[j]<='Z'&&read[i].name[j]>='A')//大写字母处理 
			{
				word[i].name[k]=read[i].name[j]+'a'-'A';
				k++;
			}
			//其余的不放进去 
		}
	
	}

	//按照字母顺序排序 
	qsort(word,cnt,sizeof(word[0]),cmp);
	
	//去重操作 
	strcpy(ans[0].name,word[0].name);//先把第一个放进新数组 从第二个开始比较 
	ans[0].time=1;
	
	int num=0;
	
	for(i=1;i<cnt;i++)//从第二个开始读 
	{

		if(strcmp(word[i-1].name,word[i].name)==0)//与上一个单词相同 
		{
			ans[num].time++;
			continue; 
		}	
		
		//新单词 
		num++;
		strcpy(ans[num].name,word[i].name);
		ans[num].time++;
		
	}
	
	for(i=0;i<=num;i++)
	{
		printf("%s %d\n",ans[i].name,ans[i].time);
	}
	
	fclose(in);
	return 0;
}


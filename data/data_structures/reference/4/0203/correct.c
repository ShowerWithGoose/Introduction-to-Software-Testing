//词频统计 从文件中读入文本 统计单词出现次数 以字典序输出单词&出现次数
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct {
	char word[50];
	int count;
}List; 

int cmp(const void *a,const void *b){
	List c=*(List*)a;
	List d=*(List*)b;
	return (strcmp(c.word,d.word));
}
int getword(FILE *tfp, char *w)//从文本中读取单词并都以小写存入w里 
{
	int c;
	while(!isalpha(c=fgetc(tfp)))
	{
		if(c==EOF)
		return c;
		else 
		continue;
	}
	
	do	{
		*w=tolower(c);
		w++;
		}while(isalpha(c=fgetc(tfp)));
	*w='\0';
	return 1;
}
int main(){
	List item[1024];//char wo[50];
	FILE *fp=fopen("article.txt","r");
	int n=0,i,j,flag;
	while(getword(fp,item[n].word)!=EOF)//将文本中所有单词填入结构体里 接下来要做的就是合并同类项后输出
	n++;
	//while(getword(fp,wo)!=EOF)
	//printf("%s ",wo);
	qsort(item,n,sizeof(item[0]),cmp);//先按字典序排序 
	//printf("%s %s %s ",item[0].word,item[2].word,item[4].word);
	/*
	*/for(i=0;i<n;)
	{	
		item[i].count=1;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(item[j].word,item[i].word)==0)//如果i个单词之后有和i相同的单词 
			item[i].count++;
			else break;
		}
		printf("%s %d\n",item[i].word,item[i].count);
		i=j;//
	}
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 1024
struct voc{
	char spell[50];
	int cnt;//出现次数
}word[MAX];

int cmp(const void*p,const void *q)
{
	struct voc *pp=(struct voc*)p;
	struct voc *qq=(struct voc*)q;
	
	return (strcmp((*pp).spell,(*qq).spell));
}

int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");
	char c;//读入字符
	int num=0;//词的数量
	int letter=0;
	while(fscanf(fp,"%c",&c)!=EOF)
	{
		char ch=tolower(c);
		if(ch>='a'&&ch<='z')//是字母
		{
			word[num].spell[letter]=ch;//转小写存
			letter++;//看下一个字母
		}
		//如果下一个扫描到的字符不是字母，就断一下 开始计词数
		else if(strlen(word[num].spell)!=0)
		{
			word[num].cnt=1;//出现次数+1
			letter=0;//字母数归零
			num++;//词数+1
		}
	}
	qsort(word,num,sizeof(word[0]),cmp);//字典序快排
	
	for(int i=0;i<num;i++)
	{
		if(strcmp(word[i].spell,word[i+1].spell)==0)//词汇重复出现
		{
		word[i+1].cnt+=word[i].cnt;
			//后面的往前移动?
		}
		else if(strlen(word[i].spell)!=0)
		printf("%s %d\n",word[i].spell,word[i].cnt);
	}
	
	return 0;
}


#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
//大写字母全部转成小写字母
char word[200][20];
char temp[20];
 
int main()
{
	//打开文件
	FILE *in;
	int number;
	in=fopen("article.txt","r");
	//读取单词 转换成小写字母 
	int i,j;
	i=1;
	char c;
	while(1)
	{
		int top = 0;
		while(!isalpha(c=fgetc(in))&&c!=EOF)
		;//找到第一个是字母的位置 
		if(c==EOF)
		break;//全部都不是字母，非单词  
		else
		temp[top++]=tolower(c);//暂存到temp字符串中 
		while(c!=EOF&&isalpha(c=fgetc(in)))//剩余字符串依次判断 
		{
			temp[top++]=tolower(c);
		}
		temp[top]='\0';//字符串结尾加上'\0' 
		strcpy(word[i++],temp);
		if(c==EOF)
		break;
	}
	number=i-1;	
	//按照内码大小对单词排序
	char change[20];
	for(i=1;i<=number-1;i++)
	{
		for(j=number;j>=i+1;j--) 
		{
			if(strcmp(word[j-1],word[j])>0)
			{
				memset(change,0,sizeof(change));
				strcpy(change,word[j-1]);
				strcpy(word[j-1],word[j]);
				strcpy(word[j],change);
			} 
		}
	}
	//将相同的删除 出现次数+1 
	int k=1;
	int ans[200];
	int index[200];
	//对第一个元素初始化 
	index[k]=1;
    ans[k]=1;
	for(i=2;i<=number;i++)
	{
		if(strcmp(word[i-1],word[i])==0)
		{
			ans[k]++;
		}
		else
		{
			k++;
			index[k]=i;
			ans[k]=1;
		}
	}
	
	//按照格式逐个输出 
	for(i=1;i<=k;i++)
	{
		printf("%s %d\n",word[index[i]],ans[i]);
	}
    return 0;
}



#include <stdio.h>//最终版！ 
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct WORD{
	int cnt;
	char str[1024];
}word[500005];
int cmp(const void *x,const void *y);
//void toword(char s[1024]);
int main()
{
	FILE *in;
	if((in=fopen("article.txt","r"))==NULL)
	{
		printf("can not open ~~~");
		//return 1;
	}
	in=fopen("article.txt","r");
	
	int n=0;
	char s[1024];//用s是因为fgets只能在gets到字符数组里 
	char *t;
	while((fgets(s,1023,in))!=NULL)
	{
		char *p;//字符数组s无法++，所以设一个p来处理 
		p=s;
		while(strlen(p)!=0)//这个指针里还有东西的时候进行，在括号里面要注意指针里有可能没东西的时候迅速打断跳出 //最终果然还是strlen最好用！！！！！ 
		{
			char *t;
			while(isalpha(*p)==0)
			{
				p++;
				if(strlen(p)==0)
				break;
			}
			if(strlen(p)==0)
			    continue;
			t=p;
			while(isalpha(*p)!=0)//是字母就下一个
			{
				*p=tolower(*p);
				p++; 
			 } 
			*p='\0';//到这里t是处理完了 
			p++;
			//以上是在getword 
			int flag=0;
			for(int i=0;i<=n;i++)
			{
				if(strcmp(t,word[i].str)==0)
				{
					word[i].cnt++;
					flag=1;
					break;
				}
			 } 
			if(flag==0)
			{
				strcpy(word[n].str,t);
				word[n].cnt=1;
				n++;
			}
		}
	}
	qsort(word,n,sizeof(word[0]),cmp); 
	for(int i=0;i<n;i++)
	printf("%s %d\n",word[i].str,word[i].cnt);
	fclose(in);
	
	return 0;
 } 
int cmp(const void *x,const void *y){
	int i=strcmp((*(struct WORD *)x).str,(*(struct WORD *)y).str);
	return  i;
}




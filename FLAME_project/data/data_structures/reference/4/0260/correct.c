#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
typedef struct{
	char dc[50];
	int n;
}cptj,*pcptj;
int cmp(const void *p1,const void *p2)
{
	int ans;
	pcptj dc1=(pcptj)p1;
	pcptj dc2=(pcptj)p2;
	ans=strcmp(dc1->dc,dc2->dc);
	return ans;
}//用来比较的 
int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");	
	if(fp == NULL)
	{
		return -1;
	}
	cptj cp[100];
	int i,n,j=0,k=0,num,max=1,pd,op;
	char s[100];
	char ds[50];
	char ch;
	//输入 
	while(fscanf(fp,"%s",s)!=EOF)
	{
		for(i=0;i<strlen(s);i++)
		{
			op=0;
			if(tolower(s[i])>='a'&&tolower(s[i])<='z')
			{	
				memset(ds,0x00,sizeof(char)*50);//置空
			for(j=0;tolower(s[i])>='a'&&tolower(s[i])<='z';i++,j++)
			{
				ds[j]=tolower(s[i]);
			}
			op=1;//找到的单词 
			//printf("#%s ",ds);//num是找到的单词个数 
			}
		//开始统计 
			if(op)
			{	
				pd=1;
			for(k=0;k<max;k++)
			{
				if(strcmp(cp[k].dc,ds)==0)//查找
				{
				cp[k].n++;
				pd=0;
				//printf("&%s %d",cp[k].dc,cp[k].n);//用来测有没有加词频					
				 } 
			}
			if(pd)
			{
				strcpy(cp[k].dc,ds);// 在最后一个 录入新单词。 
				cp[k].n=1;
				max++;
				//printf("$%s %d",cp[k].dc,cp[k] .n);//用来测有没有录入 
			}				
			}
		}
		//printf("\n");
	}
	for(i=0;i<max;i++)
	{
		cp[i]=cp[i+1];
	}
	max--;
	qsort(cp,max,sizeof(cptj),cmp);
	for(i=0;i<max;i++)
	printf("%s %d\n",cp[i].dc,cp[i].n);
	fclose(fp);
	return 0;
}




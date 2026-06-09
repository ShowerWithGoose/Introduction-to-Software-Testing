#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct words
{
	char w[50];
	int s;
};
struct words word[100];
int pickaword(char *temp,char *str,int p,int n)//从下标p开始在str中读取temp,str的长度为n 
{
	if(p>=n) return -1;
	while(!isalpha(str[p])&&p<=n)
	{
		p++;
	}
	int i=0;
	while(isalpha(str[p]))
	{
		temp[i++]=tolower(str[p++]);
	}
	temp[i]='\0';
	return p;//下一次要读的下标 
}
int check(struct words *word,int n,char *temp) //将字符temp和长度为n的结构体数组中存的单词比较，如果有相同，返回1并且在对应的结构体计数器上加一，否则返回0 
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(word[i].w,temp)==0)
		{
			flag=1;
			word[i].s++;
			break;
		}
	}
	return flag;
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r"); 
	char str[1000]=""; 
	int i=0;
	while((str[i]=fgetc(in))!=EOF)
	{
		i++;
	}
	str[i-1]='\0';
	char temp[50]="";
	int n=strlen(str),p=0;
	i=0;
	while((p=pickaword(temp,str,p,n))!=-1)
	{
		if(temp[0]=='\0')
		continue;
		if(i==0)//若是第一个，直接插入 
		{
			strcpy(word[i].w,temp);
			word[i].s++;
			i++;
		}
		else if(check(word,i,temp)==0)//如果没有与之前的重复，就插入 
		{
			strcpy(word[i].w,temp);
			word[i].s++;
			i++;
		}
	}
	fclose(in);
	n=i;
	int k;
	int num[100];//存下标 排次序 
	for(i=0;i<n;i++)
	{
		num[i]=i;
	}
	int hold;
	for(i=0;i<n-1;i++)//冒泡排一遍 
    {
        for(k=0;k<n-i-1;k++)
        {
            if(strcmp(word[num[k]].w,word[num[k+1]].w)>0)
            {
                hold=num[k];
                num[k]=num[k+1];
                num[k+1]=hold;
            }
        }
    }
    for(i=0;i<n;i++)
    {
    	printf("%s %d\n",word[num[i]].w,word[num[i]].s);
	}
	return 0;
}






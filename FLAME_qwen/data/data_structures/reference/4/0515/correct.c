#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	FILE *in,*out;
	in=fopen("article.txt","r");
	struct words{
		char word[50];
		int num;
	} data[100];
	char ch,raw[50];
	int i=0,w_num=0,flag,j;
	while(fscanf(in,"%c",&ch)!=EOF)
	{
		ch=tolower(ch);
		if(isalpha(ch))
		{
			memset(raw,'\0',sizeof(raw));
			raw[0]=ch;
			i=1;
			while(1)
			{
				fscanf(in,"%c",&ch);
				if(isalpha(ch))
				{
					ch=tolower(ch);
					raw[i]=ch;
					i++;
				}
				else
				{
					break;
				}
			}
			flag=0;
			for(i=0;i<w_num;i++)
			{
				if(strcmp(raw,data[i].word)==0)
				{
					data[i].num++;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				strcpy(data[w_num].word,raw);
				data[w_num].num=1;
				w_num++;
			}
		}
	}
	while(1)
	{
		flag=0;
		for(i=0;i<w_num-1;i++)
		{
			if(strcmp(data[i].word,data[i+1].word)>0)
			{
				strcpy(raw,data[i].word);
				j=data[i].num;
				strcpy(data[i].word,data[i+1].word);
				data[i].num=data[i+1].num;
				strcpy(data[i+1].word,raw);
				data[i+1].num=j;
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
	for(i=0;i<w_num;i++)
	{
		printf("%s %d\n",data[i].word,data[i].num);
	}
	return 0;
}


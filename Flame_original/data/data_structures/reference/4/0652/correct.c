#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct ci{
	char s[100];
	int n;
}word[100000];
char a,t[100];
int main()
{
	FILE *fp=fopen("article.txt","r");
	int i=0,j,length=0,flag=0;
	a=fgetc(fp);
	while(a!=EOF)
	{
		if(isalpha(a))
		{
			t[i]=tolower(a);
			i++;
		}
		else if(strcmp(t,"\0")!=0)
		{
			for(j=0;j<length;j++)
			{
				if(strcmp(word[j].s,t)==0)
				{
					word[j].n+=1;
					flag=1;
					break;
				}
				flag=0;
			}
			if(flag==0)
			{
				strcpy(word[length].s,t);
				word[length].n+=1;
				length++;
			}
			i=0;
			memset(t,0,sizeof(t));
		}
		a=fgetc(fp);
	}
	struct ci temp;
	for(i=0;i<length-1;i++)
	{
		for(j=0;j<length-1;j++)
		{
			if(strcmp(word[j].s,word[j+1].s)>0)
			{
				temp=word[j+1];
				word[j+1]=word[j];
				word[j]=temp;
			}
		}
	}
	for(i=0;i<length;i++)
	printf("%s %d\n",word[i].s,word[i].n);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[300];
struct words{
	char name[18];
	int rate;
	int sign;
}word[108];
int cmp(const void*a,const void*b)
{
	return strcmp(((struct words*)a)->name,((struct words*)b)->name);
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	int length,i,j=0,k=0,flag=0;
	while(fgets(s,300,in)!=NULL)
	{
		length=strlen(s);
		for(i=0;i<length;i++)
		{
			if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
			{
				flag=1;
				word[j].sign=1;
				if(s[i]>='a'&&s[i]<='z')
				word[j].name[k++]=s[i];
				else if(s[i]>='A'&&s[i]<='Z')
				word[j].name[k++]=s[i]-'A'+'a';
			}
			else
			{
				if(flag==0)
				continue;
				else
				{
					flag=1;
					j++;
					k=0;
				}
			}
		}
	}
	qsort(word,j,sizeof(struct words),cmp);
	int m;
	for(i=0;i<j;i++)
	{
		if(word[i].sign==0)
		continue;
		m=i+1;
		k=1;
		while(strcmp(word[i].name,word[m].name)==0)
		{
			k++;
			word[m].sign=0;
			m++;
		}
		printf("%s %d\n",word[i].name,k);
	}
	fclose(in);
	return 0;
}


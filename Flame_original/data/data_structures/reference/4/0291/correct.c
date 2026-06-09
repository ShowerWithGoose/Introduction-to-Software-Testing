#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct count
{
	char vol[100];
	int cnt;
}word[1005];
int cmp(const void*p1,const void*p2)
{
	struct count *a = (struct count*)p1;
	struct count *b = (struct count*)p2;
	return strcmp(a->vol,b->vol);
}
int main()
{
	FILE *f1 = fopen("article.txt","r");
	char a[1000],temp;
	int i=0,j,k,len,num=0,cnt2=0;
	temp = fgetc(f1);
	while(temp!=EOF)
	{
		a[i]=temp;
		i++;
		temp=fgetc(f1);
	}
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(isalpha(a[i]))
			a[i]=tolower(a[i]);
	}
	for(i=0;i<len;i++)
	{
		if(isalpha(a[i]))
		{
			for(j=i;j<len;j++)
			{
				if(!isalpha(a[j]))
					break;
			}
			for(k=0;k<j-i;k++)
			{
				word[num].vol[k] = a[i+k];
			}
			num++;
			i=j;
		}
		else
			continue;
	}
	qsort(word,num,sizeof(word[0]),cmp);
	for(i=0;i<num;i++)
		word[i].cnt=1;
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(strcmp(word[i].vol,word[j].vol)==0)
			{
				word[i].cnt++;
				memset(word[j].vol,'z'+1,sizeof(word[j].vol));
				if(word[i].vol[0] != '{')
					cnt2++;
			}
			else
				break;
		}

		qsort(word,num,sizeof(word[0]),cmp);

	}
	qsort(word,num,sizeof(word[0]),cmp);
	for(i=0;i<num-cnt2;i++)
		printf("%s %d\n",word[i].vol,word[i].cnt);
	return 0;
} 


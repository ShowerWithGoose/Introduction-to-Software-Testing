#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct st{
	char word[40];
	int num;
};

int cmp(const void *a,const void *b)
{
	struct st*a1=(struct st*)a;
	struct st*b1=(struct st*)b;
	return strcmp(a1->word,b1->word);
}

int sum;
char line[1024];
int find(char*p,struct st words[],int sum);

int main()
{
	struct st words[200];
	FILE*fp;
	fp=fopen("article.txt","r");
	if(fp==NULL)
	{
		perror("can't open");
		return 0;
	}
	while(fgets(line,1023,fp)!=NULL)
	{
		char*p,*q,*last;
		last=strchr(line,'\0');
		p=line;
		while(1)
		{
			
			for(;p!=last;p++)
			{
				if((*p=tolower(*p))>='a'&&(*p=tolower(*p)))
					break;
			}
			if(p==last)
				break;
				
			for(q=p;(*q=tolower(*q))>='a'&&(*q=tolower(*q))<='z';q++);
			*q='\0';
//			puts(p);
			
			if(sum==0)
			{
				int i;
				for(i=0;p<q;i++,p++)
				{
					words[sum].word[i]=*p;
				}
				words[sum].word[i]='\0';
				words[sum].num=1;
//				printf("%s %d\n",words[sum].word,words[sum].num);
				sum++;
				if(q==last)
					break;
				p=q+1;
			}
			else
			{	
				int j;
				if((j=find(p,words,sum))!=-1)
				{
					words[j].num++;
//					printf("%s %d\n",words[j].word,words[j].num);
					if(q==last)
						break;
					p=q+1;
				}
				else
				{
					int i;
					for(i=0;p<q;i++,p++)
					{
						words[sum].word[i]=*p;
					}
					words[sum].word[i]='\0';
					words[sum].num=1;
//					printf("%s %d\n",words[sum].word,words[sum].num);
					sum++;
					if(q==last)
						break;
					p=q+1;
				}
			}
			if(p==last)
				break;
		}
		
	}
	
	qsort(words,sum,sizeof(words[0]),cmp);
	int m;
	for(m=0;m<sum;m++)
		printf("%s %d\n",words[m].word,words[m].num);
	
	
	fclose(fp);
	
	return 0;
}

int find(char*p,struct st words[],int sum)
{
	int n;
	for(n=0;n<sum;n++)
	{
		if(strcmp(p,words[n].word)==0)
			return n;
		
	} 
	return -1;
}






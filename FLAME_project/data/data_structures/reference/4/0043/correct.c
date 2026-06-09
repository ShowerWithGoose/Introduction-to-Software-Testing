#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
	char s[50];
	int num;
};
char str[10000];
int i=0;
int j=0;
int k=0;
int h=0;
int cmp(const void *a,const void *b)
{
	return strcmp((*(struct node *)a).s,(*(struct node *)b).s);
}
int main()
{
	struct node a[1000];
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(str,1000,in)!=NULL)
	{
		char word[50];
		for(i=0;i<strlen(str);i++)
		{
			j=0;
			if(!isalpha(str[i]))
			continue;
			while(isalpha(str[i]))
			{
				word[j++]=tolower(str[i]);
				i++;
			}
			word[j] = '\0';
//			if('A'<=str[i] && str[i]<='Z')
//			str[i]=str[i]+32;
//			if('a'<=str[i] && str[i]<='z'&&t==0)
//			{ 
//				j=0;
//				word[j]=str[i];
//				j++;
//			}
//			if('a'<=str[i] && str[i]<='z'&&t==1)
//			{
//				word[j]=str[i];
//				j++;
//			}
//			if (!('a'<=str[i] && str[i]<='z')&&t==1)
//			{
				int f=0; 
				for(h=0;h<k;h++)
				{
					if(strcmp(a[h].s,word)==0)
					{
						a[h].num++;
						f=1;
					}
						
				}
				if(f==0)
					{
						strcpy(a[k].s,word);
						a[k].num++;
						k++;				
					}	
			} 
//			if ('a'<=str[i] && str[i]<='z')
//			{
//				t=1;
//			}
		}
	qsort(a,k,sizeof(struct node),cmp);
	for(i=0;i<k;i++)
	{
		printf("%s %d\n",a[i].s,a[i].num);
	}
return 0;
}



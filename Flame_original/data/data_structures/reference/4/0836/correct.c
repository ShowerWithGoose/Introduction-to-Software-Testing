#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 1024
char word[505][55];
int time[505];
char s[max];
int id[505]; 
int cmp(const void *a,const void *b)
{
	int pa=*((int*)a);
	int pb=*((int*)b);
	return strcmp(word[pa],word[pb]);
}
void tower(char s[])
{
	int i=0;
	for(i=0;s[i]!='\n';i++)
	{
		if(s[i]<='Z'&&s[i]>='A')
		s[i]+=32;
	}
}
int main()
{
	char str[55];
	FILE *fp;
	int i,j,k=0;
	fp=fopen("article.txt","r");
	while(fgets(s,max-1,fp)!=NULL)
	{
		tower(s);
		i=0;
		while(s[i]!='\0')
		{
			if(s[i]>='a'&&s[i]<='z')
			{
				for(j=0;s[i]>='a'&&s[i]<='z';i++,j++)
				str[j]=s[i];
				str[j]='\0';
				for(j=0;word[j][0]!='\0';j++)
				{
						if(strcmp(word[j],str)==0)
						{
							time[j]++;break;
						}
				}
				if(j==k)
				{
					strcpy(word[k],str);
					k++;
				}
			}
			i++;
		}
	}
	for(i=0;i<k;i++)
	id[i]=i;
	fclose(fp);
	qsort(id,k,sizeof(int),cmp);
	for(i=0;i<k;i++)
	printf("%s %d\n",word[id[i]],time[id[i]]+1);
	return 0;
 } 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct w
{
	char c[50];
	int num;
}word[100];
char line[5000];
int cmp(const void *a, const void *b) {
	struct w *aa = (struct w *)a;
	struct w *bb = (struct w *)b;
	int result = strcmp(aa->c, bb->c);
	if (result > 0) return 1;
	if ( result < 0 ) return -1; 
	return -1;
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	int i,p=0;
	while(fgets(line,5000,in)!=NULL)
	{
		for(i=0;i<strlen(line);i++)
		{
			if(line[i]>='A'&&line[i]<='Z')
				line[i]=line[i]-'A'+'a';
		}
		for(i=0;i<strlen(line);i++)	
		{
			char ci[50];
			int j=0;
			while(line[i]>='a'&&line[i]<='z')
				ci[j++]=line[i++];
			ci[j]='\0';
			if(strlen(ci)>0)
			{
				int y,flag=0;
				for(y=0;y<100;y++)
				{
					if(strcmp(word[y].c,ci)==0)
					{
						flag=1;
						word[y].num++;
					}
				}
				if(flag==0)
				{
					strcpy(word[p].c,ci);
					word[p].num=1;
					p++;
				}
			}
		}
	}
	qsort(word,p,sizeof(word[0]),cmp);
	for(i=0;i<p;i++)
		printf("%s %d\n",word[i].c,word[i].num);
	fclose(in);
	return 0;
}


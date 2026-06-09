#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 1024
struct word{
	char w[32];
	int count;
}c[MAX];
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char a,newword[32];
	int i=0,j=0,sign=0;
	while((a=tolower(fgetc(in)))!=EOF)
	{
		if(isalpha(a))
		{
			newword[i++]=a;
		}
		else{
			if(i==0) continue;
			newword[i]='\0';
//			printf("%s ",newword);
			i=0;
			sign++;
			for(j=0;j<sign;j++)
			{
				if(j==sign-1){
					strcpy(c[j].w,newword);
					c[j].count=1;
					break;
				}
				if(strcmp(newword,c[j].w)==0)
				{
					c[j].count++;
					sign--;
					break;
				}
				else if(strcmp(newword,c[j].w)<0)
				{
					int k=0;
					for(k=sign;k>j;k--)
					{
						strcpy(c[k].w,c[k-1].w);
						c[k].count=c[k-1].count;
					}
					strcpy(c[j].w,newword);
					c[j].count=1;
					break;
				}
			}
//			else
//			{
//				strcpy(c[0].w,newword);
//				c[0].count=1;
//				printf("%s ",c[0].w);
//				printf("%d\n",c[0].count);
//			}
		}
	}
	for(i=0;i<sign;i++)
	{
		printf("%s ",c[i].w);
		printf("%d\n",c[i].count);
	}
	fclose(in);
	return 0;
}




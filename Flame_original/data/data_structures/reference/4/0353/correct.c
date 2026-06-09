#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct vocabulary
{
	char wo[120];
	int sum;
} a[100000],tem;
 /*typedef struct vocabulary f;
int cmp(const void*p1,const void *p2)
{
	struct vocabulary *a =(struct vocabulary*)p1;
	struct vocabulary *b =(struct vocabulary*)p2;
	return strcmp(a -> wo,b -> wo);
} */
int main()
{
	FILE *in = fopen("article.txt","r");
	char c, word[120]={0};
	int i = 0, j, len = 0;
	while( (c = fgetc(in))!= EOF)
	{
		if(isalpha(c) != 0)
		{
			word[i++] = tolower(c);
		}
		else
		{
			 i = 0;
			if(strcmp(word,"\0")!=0)
			{
				int flag;
				for(j = 0; j < len; j++)
				{
					if(strcmp(word,a[j].wo) == 0)
					{
						flag = 1;
						a[j].sum++;
						break;
					}
					else flag = 0;
				}
				if(flag == 0)
				{
					strcpy(a[len].wo,word);
					a[len].sum = 1;
					len++;
				}
   	//for(j = 0; j < 15; j++) word[j]='\0';
				memset(word,0,sizeof(word));
			}
		}
	}
//ÏÂÃæÊÇÃ°ÅÝÅÅÐò
	for(i = 0; i < len-1; i++)
	{
		int flag = 0;
		for(j = 0; j < len-1; j++)
		{
			if(strcmp(a[j].wo,a[j+1].wo) > 0)
			{
				tem = a[j+1];
				a[j+1] = a[j];
				a[j] = tem;
				flag = 1;
			}
		}
		if(flag == 0) break;
	}

//qsort(a,len,sizeof(f),cmp);
	for(i = 0; i < len; i++)
		printf("%s %d\n",a[i].wo,a[i].sum);

	fclose(in);
	return 0;
}





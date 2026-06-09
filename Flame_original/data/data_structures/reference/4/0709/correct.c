#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXLINE 1024
#define eps 1e-15

int num,num_word;
char line[MAXLINE];

struct Words{
	char id[400];
	int times;
}word[10000]; 

int cmp (const void*a,const void*b)
{
	return strcmp((*(struct Words *)a).id, (*(struct Words *)b).id )>0 ? 1 : -1;
}

int main(){
	FILE *in,*out;
	in = fopen("article.txt","r");
	
	while(fgets(line, MAXLINE, in) != NULL)
	{

		char words[400][10005] = {"\0"};
		for(int i=0;i<strlen(line);i++)
			if(line[i] >= 'A' && line[i] <= 'Z')
				line[i] += 32;//先将字符串所有大写转化为小写
				
		for(int i=0,j=0;line[i] != '\0';i++)
		{
			if(line[i] >= 'a' && line[i] <= 'z')
				words[num][j++] = line[i];
			else
			{
				num++;
				j = 0;
			}	
		}
		for(int i=0;i<num+1;i++)
		{
			int judge = 0;
			if(words[i][0] == '\0')//排除空字符串 
				continue;
			else 
			{
				for(int j=0;j<num_word;j++)
				{
					if(strcmp(word[j].id, words[i]) == 0)//如果结构体中有一样的字符串 
					{
						word[j].times ++;
						judge = 1;
						break; 
					}
					else
						continue;
				}
				if(judge == 0)
					strcpy(word[num_word++].id, words[i]);
			}
		}
	}
	qsort(word, num_word, sizeof(word[0]), cmp);
	
	for(int i = 0;i<num_word;i++)
		printf("%s %d\n", word[i].id, word[i].times + 1);
	
	return 0;
}



#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct words{
	char word[101];
	int times;
}word_list[1000],change;
int main()
{
	int i, j, k;
	int  flag = 0;
	int num = 0;
	char a, word[100] = {0};//×Ö·û¸½Áã 
	FILE *fp;
	fp = fopen("article.txt","r");
	while((a = fgetc(fp))!= EOF)
	{
		if(a>='A'&& a<='Z')
		{
			a = 'a'  +a - 'A';
			word[i] = a;
			i++;
		}
		else if(a>='a'&&a<='z')
		{
			word[i] = a;
			i++;
		}
		else 
		{
			if(strcmp(word,"\0")!= 0)
			{
				for(j = 0; j<num ; j++)
				{
					if(strcmp(word,word_list[j].word)==0)
					{
						flag = 1;
						word_list[j].times++;	
						break;
					}
					else
					{
						flag = 0;
					}
				}
				if(flag == 0)
				{
					strcpy(word_list[num].word,word);
					word_list[num].times++;
					num++; 
				}
				for(k = 0; k<100;k++)
				word[k] = '\0';
			}
			i = 0;
		}
		
	}
	for(i=0; i<num; i++)
	{	
		for(j=0; j<num; j++)
		{
			if(strcmp(word_list[i].word,word_list[j].word)<0)
			{
				change = word_list[i];
				word_list[i] = word_list[j];
				word_list[j] = change;
			}
			
		}
	}
	for(i = 0;i<num;i++)
	{
		printf("%s %d\n",word_list[i].word, word_list[i].times);
	}
	fclose(fp);
	return 0;
}


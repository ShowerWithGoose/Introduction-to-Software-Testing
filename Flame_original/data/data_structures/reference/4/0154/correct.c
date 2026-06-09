#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
//词频统计
//思路：首先打开文件，fgets读取一行，用line存，line是个char指针（开辟空间），用word数组存单词，并将word存入一个指针数组中，char型的数组（即一句话，每个单词用‘ ’隔开
//若word不在那句话中，用strstr在line中找word，若找到了则将line，则对于的number++，继续找下一个
typedef struct theword {
	char word[70];
	int times;
}td;
td ci[100000];
int compare(const void* a, const void* b)
{
	td* pa = (td*)a;
	td* pb = (td*)b;
	return strcmp(pa->word,pb->word);
}
int getword(char* line, char ch[])
{
	int i = 0;
	while (line[i] != ' '&& line[i] != '\n'&&line[i]!='\0')
	{
		ch[i] = line[i];
		i++;
	}
	ch[i] = '\0';
	if (i)return 1;
	else return 0;
}
void correct(char* line)//大写字母变小写，去掉标点符号
{
	char* tmp = (char*)malloc(150);
	int i = 0,j = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] >= 'a' && line[i] <= 'z' || line[i] == ' ')
		{
			tmp[j] = line[i];
			j++;
			i++;
		}
		else if (line[i] >= 'A' && line[i] <= 'Z')
		{
			tmp[j] = tolower(line[i]);
			i++;
			j++;
		}
		else {
			tmp[j] = ' ';
			i++;
			j++;
		}
	}
	tmp[j] = '\n';
	tmp[j + 1] = '\0';
	strcpy(line, tmp);
}
int main()
{
	FILE* fp = fopen("article.txt", "r");
	char* line[10000];
	line[0] = (char*)malloc(150);
	int i = 0;
	char me[50];
	while (fgets(line[i], 150, fp))
	{
		correct(line[i]);
		i++;
		line[i] = (char*)malloc(150);
	}
	int num = i;
	int numci = 0;
	for ( i = 0; i < num; i++)
	{
		while (*(line[i]-1)!='\n')
		{
			if (getword(line[i], me))
			{
				for (int j = 0; j < 1000000; j++)
				{
					if (!ci[j].times)
					{
						strcpy(ci[j].word, me);
						ci[j].times++;
						numci++;
						break;
					}
					if (!strcmp(me, ci[j].word))
					{
						ci[j].times++;
						break;
					}
				}
			}
				line[i] += (strlen(me) + 1);
		}
	}
	qsort(ci, numci, sizeof(td), compare);
	int k = 0;
	while (ci[k].times)
	{
		printf("%s %d\n", ci[k].word, ci[k].times);
		k++;
	}
	fclose(fp);
	return 0;
}

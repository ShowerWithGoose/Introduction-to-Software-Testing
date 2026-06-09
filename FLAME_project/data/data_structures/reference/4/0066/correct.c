#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct article{
	char word[50];
	int num;
}art[500];

int cmp_word(const void* e1,const void* e2)
{
	struct article *a = (struct article*)e1;
	struct article *b = (struct article*)e2;
	return strcmp(a -> word,b -> word);	
}

int main()
{
	FILE *fp;
	fp = fopen("article.txt","r");
	struct article art[500];
	int i = 0;
	int q = 0;
	int t = 0;
	char str[50] = {0};
	while(1)
	{
		char c;
		c = fgetc(fp);
		if(feof(fp))
		{
			break;
		}
		else
		{
			if(c >= 'a' && c <= 'z')
			{
				str[q++] = c;
				t ++;
			}
			if(c >= 'A' && c <= 'Z')
			{
				str[q++] = c + 32;
				t ++;
			}
			if(c < 'a' && c > 'Z' && t != 0|| c > 'z' && t != 0||c < 'A' && t != 0)
			{
				art[i].num = 1;
				strcpy(art[i].word,str);
				q = 0;
				t = 0;
				i ++;
				memset(str,0,sizeof(str));
			}
		}
	}
	fclose(fp);
	int j;
	int flag = 0;
	for(j = 0;j < i-flag;j ++)
	{
		int k;
		for(k = j+1;k < i-flag;k ++)
		{
			int d = strcmp(art[j].word,art[k].word);
			if(d == 0)
			{
				art[j].num ++;
				art[k].num = -1;
				int l;
				for(l = k;l < i-flag;l ++)
				{
					strcpy(art[l].word,art[l+1].word);
					art[l].num = art[l+1].num;
				}
				k --;
				flag ++;
			}
		}
	}	
	
	qsort(art,j,sizeof(art[0]),cmp_word);
	for(j = 0;j < i-flag;j ++)
	{
		printf("%s %d\n",art[j].word, art[j].num);
	}
	return 0;
} 


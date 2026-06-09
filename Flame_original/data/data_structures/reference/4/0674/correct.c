#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct article
{
	char words[15];
	int count;
}result;

char process[100][15];
char str[100];

result out[100];

int Cmp(const void *pa, const void *pb);

int main()
{
	
	int num = 0;
	int nu = 0;
	int nump = 0;
	int i = 0;
	int j = 0;
	int flag = 0;
	int op = 0;
	FILE  *in;
	in = fopen("article.txt", "r");
	while(fgets(str, 100, in)!=NULL)
	{
		for(i = 0; i < strlen(str);i++)
		{
			flag = 0;
			if(str[i]>='a'&&str[i]<='z')
			{
				process[nu][nump++] = str[i];
				op = 1;
			}
			else if(str[i]>='A'&&str[i]<='Z')
			{
				process[nu][nump++] = str[i]-'A'+'a';
				op = 1;
			}
			else if(op)
			{
				process[nu][nump]= '\0';
				nump = 0;
				op = 0;
				if(num == 0)
				{
					strcpy(out[num].words,process[nu]);
					out[num].count++;
					num++;
				}
				else
				{
					for(j = 0; j<num; j++)
					{
						if(strcmp(out[j].words,process[nu])==0)
						{
							out[j].count++;
							flag = 1;
						}						
					}
					if(flag==0)
					{
						strcpy(out[num].words,process[nu]);
						out[num].count++;
						num++;
					}
				}
				nu++;				
			}
		}
	}
	fclose(in);
	qsort(out,num,sizeof(result),Cmp);
	for(i=0;i<num;i++)
	{
		printf("%s %d\n", out[i].words, out[i].count);
	}
	return 0;
} 

int Cmp(const void *pa, const void *pb)
{
	result a = *((result *)pa);
    result b = *((result *)pb);
    return strcmp(a.words, b.words);
}


#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

struct {
	char word[50];
	int count;
	int len;
}pra[1001],s;

int pan(char a)
{
	if(tolower(a)>='a'&&tolower(a)<='z')
	return 1;
	else
	return 0;
}

int main(){
	int i,j,k,a,b,c;
	char ti;
	char A[3001];
	int max =0;
	FILE *filein = fopen ("article.txt","r");
	ti = fgetc(filein);
	for (i=0;ti!=EOF;i++)
	{
		A[i] = ti;
		ti = fgetc(filein);
	}
	a = i;
	i = 0;
	k = 0;
	while (i<a) //拆分单词 
	{
		if(pan(A[i]) == 1)
		{
			for (j = i;pan(A[j]) != 0;j++)
			{
				pra[k].word[j-i] = tolower(A[j]);
			}
			pra[k].len = strlen(pra[k].word);
			if (pra[k].len>max)
			max = pra[k].len;
			i = j-1;
			k++;
		}
		i++;
	}
	for (i = 0;i<k;i++)
	{
		pra[i].count = 1;
	}
	
	for(i=0;i<k;i++)  //首字母排序段 
    {
 		for(j=i+1;j<k;j++)
        {
            if(strcmp(pra[j].word,pra[i].word)<0)
            {
                s=pra[j];
                pra[j]=pra[i];
                pra[i]=s;
            }
        }
	}


	for (i = 0;i<k;i++) //计数段 
	{
		for(j = i + 1;j<k;j++)
		{
			if(strcmp (pra[i].word,pra[j].word) == 0&& pra[j].count != 0)
			{
				pra[i].count++;
				//printf ("%d",pra[i].count);
				pra[j].count = 0;
			}
		}
	}
	
	for (i=0;i<k;i++)// 输出 
	{
		if(pra[i].count != 0)
		{
			for(j=0;pra[i].word[j] != '\0';j++)
			{
				printf("%c",pra[i].word[j]);
			}
			printf(" %d\n",pra[i].count);
		}
	}
	
	
	return 0;
}


#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

char lib[507][30];
struct rank
{
	char word[30];
	int fre;
}l[507];

int main()
{
    FILE *fp;
    fp = fopen("article.txt", "r");

    char ch;
    int i = 0, j = 0, n = 0;
	
	ch = fgetc(fp); //输入
    while (ch != EOF)
	{
		if(ch>='a' && ch<='z')
		{
			lib[i][j]=ch;
			j++;
		}
		
		else if(ch>='A' && ch<='Z')
		{
			lib[i][j]=ch+('a'-'A');
			j++;
		}
		
		else
		{
			i++;
			j=0;
		}
		ch = fgetc(fp);
	}
	
	for(i=0;i<507;i++)//为l[j]赋值 
	{
		if(lib[i][0]>='a' && lib[i][0]<='z')//lib中非空 
		{
			strcpy(l[j].word,lib[i]);
			l[j].fre++;
			j++; 
		}
	}
	
	//for(i=0;i<j;i++)
	//{
		//puts(l[i].word);
		//printf("%d",l[i].fre);
	//}
	int tempj=j;
	for(i=1;i<tempj;i++)//指向后端单词 
	{
		for(j=0;j<i;j++)
		{
			if(strcmp(l[i].word,l[j].word)==0 && l[j].fre!=0)
			{
				l[i].fre=0;
				l[j].fre++;
			} 
		}
	}
	
	
	char temp[30];
	int tempfreq;
	
	for (i = 0; i < tempj; i++)
    {
        for (j = i + 1; j < tempj; j++)
        {
            if (strcmp(l[i].word, l[j].word) > 0)
            {
                strcpy(temp, l[j].word);
                strcpy(l[j].word, l[i].word);
                strcpy(l[i].word, temp);
                tempfreq=l[j].fre;
                l[j].fre=l[i].fre;
                l[i].fre=tempfreq;
            }
        }
    }
    
	
	for(i=0;i<=j;i++)
	{
		if(l[i].fre!=0)
		{
			printf("%s",l[i].word);
			printf(" %d\n",l[i].fre);
		}
	}
	
	
	
    fclose(fp);
    return 0;
}





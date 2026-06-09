#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct wordci {
    char word[32];
    int ci;
};
int compare(const void *a, const void *b)
{
    struct wordci *wc1=(struct wordci *)a;
    struct wordci *wc2=(struct wordci *)b;
    return strcmp(wc1->word, wc2->word);
}
int getword(FILE *fp, struct wordci wc[],int num)
{
	char ch;
	int len=0;
	while((ch=fgetc(fp))!=EOF)
	{
	    if(isalpha(ch))
	    {
		    wc[num].word[len]=tolower(ch);
		    len++;
	    }
	    else if(!isalpha(ch)&&len>0)
	    {
		    wc[num].word[len]='\0';
		    return 1;
	    }
    }
	return 0;
}
int main()
{
    FILE *fp;
    char ch;
    struct wordci wc[10000];
    int num=0;
    int len=0;
    fp=fopen("article.txt","r");
    while(getword(fp,wc,num)==1)
	{
        int flag=0;
        for(int i=0;i<num;i++)
		{
            if(strcmp(wc[i].word,wc[num].word)==0)
			{
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
		{
            wc[num].ci=1;
            num++;
        }
    }
    fclose(fp);
    qsort(wc,num,sizeof(struct wordci),compare);
    for(int i=0;i<num;i++)
	{
        printf("%s %d\n", wc[i].word, wc[i].ci);
    }
    return 0;
}

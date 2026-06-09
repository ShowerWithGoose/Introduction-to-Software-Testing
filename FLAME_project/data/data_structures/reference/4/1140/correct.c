#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
int main()
{
    struct times
    {
        char word[50];
        int count;
        struct times *link;
    };
    struct times *pt,*pt2,*first;
    char words[50],ab;
    int cmp=0,flag=0,k=0;
    FILE *IN;
    if((IN=fopen("article.txt","r"))==NULL)
    {
        printf("open IN error!");
        return 0;
    }
    pt=first=(struct times *)malloc(sizeof(struct times));
    first->link=NULL;
	while ((ab=fgetc(IN))!=EOF)
    {
        if((ab<='Z' && ab>='A')||(ab<='z' && ab>='a'))
        {
            flag=1;
            ab=(ab<='Z' && ab>='A')?tolower(ab):ab;
            words[k++]=ab;
            continue;
        }
        else if(flag==0)
        {
            continue;
        }
        words[k]='\0';
        k=0;flag=0;
        pt=first;
        while (pt->link!=NULL && (cmp=strcmp(pt->link->word,words))<0)
        {
            pt=pt->link;
        }
        if (pt->link!=NULL && cmp==0)
        {
            pt->link->count++;
        }
        else
        {
            pt2=(struct times *)malloc(sizeof(struct times));
            strcpy(pt2->word,words);
            pt2->link=pt->link;
            pt->link=pt2;
            pt2->count=1;
        }
    }
    pt=first->link;
    while (pt!=NULL)
    {
        printf("%s %d\n",pt->word,pt->count);
        pt=pt->link;
    }
	return 0;
}


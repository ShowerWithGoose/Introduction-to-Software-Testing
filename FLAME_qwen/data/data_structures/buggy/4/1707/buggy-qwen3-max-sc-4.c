#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
    char word[50];
    int count;
}List;
List list[1000];
void GetArticle(FILE *fp);
void GetWord(FILE *fp);
void GetCount(FILE *fp);
int cmp(const void*p1,const void*p2);
char article[100000];
int num=0;
int main()
{
    FILE *fp=fopen("article.txt","r");
    int k;
    GetArticle(fp);
    GetWord(fp);
    GetCount(fp);
    int i;
    for(i=0;i<num;i++)
    {
        printf("%s %d\n",list[i].word,list[i].count);
    }
    return 0;
}
int cmp(const void*p1,const void*p2)
{
    List *a=(List*)p1;
    List *b=(List*)p2;
    return strcmp(a->word,b->word);
}
void GetArticle(FILE *fp)
{
    char ch;
    int i=0;
    while((ch=fgetc(fp))!=EOF)
    {
        if(isalpha(ch))
        ch=(tolower); // @@ [Incorrect usage of tolower; should be tolower(ch), not (tolower)]
        article[i]=ch;
        i++;
    }
    article[i]='\0';
}
void GetWord(FILE *fp)
{
    int i=0;
    int len=strlen(article);
    for(i=0;i<len;i++)
    {
        if(article[i]>='a'&&article[i]<='z')
        {
            int cnt=0;
            int j=0;
            for(;article[i]>='a'&&article[i]<='z';i++)
            {
                list[num].word[j]=article[i];
                j++;
            }
            list[num].word[j]='\0';
            num++;
        }
    }
    for(i=0;i<num;i++)
    {
        list[i].count=1;
    }
    qsort(list,num,sizeof(List),cmp);
}
void GetCount(FILE *fp)
{
    int i;
    for(i=0;i<num;i++)
    {
        if(!strcmp(list[i].word,list[i+1].word))
        {
            list[i+1].count+=list[i].count;
            memset(&list[i],0,sizeof(List));
            num--; // @@ [Modifying 'num' inside the loop while iterating up to original 'num' causes out-of-bounds access and logic errors]
        }
    }
    qsort(list,num,sizeof(List),cmp);
}
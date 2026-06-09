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
        ch=tolower(ch); // @@ [Syntax error: tolower is a function, needs argument. Also logic error: non-alpha chars are kept as is, but should be treated as separators or ignored. The current logic keeps punctuation in 'article' buffer which breaks word extraction later if not handled.]
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
            num--;
            i--; // @@ [Logic error: When an element is removed by shifting or marking, the index adjustment might be incorrect depending on how the removal is effectively handled in subsequent iterations or if the array isn't compacted. However, the bigger issue is that memset creates a "hole" with empty strings. The subsequent qsort will move these empty strings to the front. This logic is flawed for counting frequencies in place without proper compaction.]
        }
    }
    qsort(list,num,sizeof(List),cmp);
}
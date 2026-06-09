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
        ch=tolower(ch); // @@ [Syntax error: tolower is a function, it should be called with ch as argument. The original code `ch=(tolower)` assigns the function pointer address or causes undefined behavior instead of converting the character to lowercase.]
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
            i--; // @@ [Logical error: When an element is removed (by shifting or marking as empty and decrementing count), the index i should be decremented to re-check the current position which now holds the next element. Without this, if there are three identical words in a row, the middle one might be skipped or processing order gets messed up relative to the shrinking array. Also, the logic of removing elements by memset and decrementing num without shifting the array leaves "holes" (zeroed structs) in the sorted array, which will break the subsequent sort and output. A standard approach is to shift elements left or use a two-pointer technique to compact the array.]
        }
    }
    qsort(list,num,sizeof(List),cmp);
}
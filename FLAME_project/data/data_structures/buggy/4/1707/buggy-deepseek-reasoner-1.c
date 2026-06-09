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
        ch=(tolower); // @@ [Error: This should be 'ch = tolower(ch);' but instead assigns the address of function tolower to ch, not converting to lowercase. This causes ch to become garbage and uppercase letters remain uppercase, later failing to be recognized as words.]
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
        if(article[i]>='a'&&article[i]<='z') // @@ [Error: Because GetArticle did not convert uppercase letters to lowercase, this condition will not match uppercase letters (e.g., 'I', 'E'), causing them to be omitted from word extraction.]
        {
            int cnt=0;
            int j=0;
            for(;article[i]>='a'&&article[i]<='z';i++) // @@ [Error: Same issue as above; uppercase letters inside a word are also missed due to failed conversion in GetArticle.]
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
    for(i=0;i<num;i++) // @@ [Error: This loop uses list[i+1] which will be out-of-bounds when i = num-1. Also the merging logic is flawed: it does not shift array after removing duplicates, zeros out entries, and then sorts again, leading to empty words and incorrect counts.]
    {
        if(!strcmp(list[i].word,list[i+1].word))
        {
            list[i+1].count+=list[i].count; // @@ [Error: Added counts correctly but the array is not shifted; subsequent merge steps may produce duplicate words.]
            memset(&list[i],0,sizeof(List)); // @@ [Error: Zeroing the entry leaves an empty word in the list, which will be sorted to the front and printed with count 0 (or incorrect).]
            num--; // @@ [Error: Decrement num without shifting later elements up; this causes gaps and the loop will skip checking the element that moved into list[i] after decrement.]
        }
    }
    qsort(list,num,sizeof(List),cmp); // @@ [Error: Sorting after zeroing out entries introduces empty strings, disrupting lexicographic order and output.]
}
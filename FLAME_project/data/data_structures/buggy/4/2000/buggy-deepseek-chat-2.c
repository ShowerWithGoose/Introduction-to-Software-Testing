#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000],tmp[100],ch;
int cnt=0;    
FILE *file;
struct word
{
    char word[100];
    int count;
};
typedef struct word word;
word w[100];

int cmp(const void *a,const void *b);
void readArticle();
void wordCount();
void printFrenquency();


int main()
{
    readArticle();
    wordCount();
    printFrenquency();
    return 0;
}

void readArticle()
{
    int i=0;
    file=fopen("file.txt","r"); // @@ [Error: The file should be "article.txt" according to the problem description, not "file.txt". This will cause the file to not open correctly, leading to no output.]
    ch=fgetc(file);
    while(ch!=EOF)
    {
        if(ch<'a')
            s[i++]=ch+32; // @@ [Error: This conversion is incorrect. It only converts characters with ASCII code less than 'a' (97) to lowercase by adding 32, but this will incorrectly modify non-letter characters like punctuation and digits. It also fails to handle uppercase letters properly (e.g., 'A' is 65, adding 32 gives 'a', but 'Z' is 90, adding 32 gives 'z', which works for uppercase letters but also affects other characters. The correct approach is to use tolower() or check if ch is an uppercase letter first.]
        else
            s[i++]=ch;
        ch=fgetc(file);
    }
}
void wordCount()
{
    int i=0,len=strlen(s);
    for (int j=0;j<len;j++)
    {
        if (s[j]>='a' && s[j]<='z')
        {
            tmp[i++]=s[j];
        }
        else
        {
            if (i)
            {
            i=0;
            strcpy(w[cnt].word,tmp);
            memset(tmp,0,sizeof(tmp));
            w[cnt].count=1;
            cnt++;
            }
            else continue;
        }
    }
}
int cmp(const void *a,const void *b)
{
    word *x=(word *)a;
    word *y=(word *)b;
    return strcmp(x->word,y->word);
}
void printFrenquency()
{
    qsort(w,cnt,sizeof(word),cmp);
    for (int k=0;k<cnt;k++)
    {
        if (strcmp(w[k].word,w[k+1].word)==0) // @@ [Error: This line accesses w[k+1] when k = cnt-1, which is out of bounds. This causes undefined behavior and may lead to a runtime error or incorrect output.]
        {
            w[k+1].count+=w[k].count;
            w[k].count=0;
        }
    }
    for (int k=0;k<cnt;k++)
    {
        if (w[k].count)
        {
            printf("%s %d\n",w[k].word,w[k].count);
        }
    }
}
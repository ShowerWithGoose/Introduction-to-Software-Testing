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
    file=fopen("file.txt","r"); // @@ [Error: The file should be "article.txt" according to the problem description, not "file.txt". This will cause the file to not be found, leading to runtime error or empty output.]
    ch=fgetc(file);
    while(ch!=EOF)
    {
        if(ch<'a')
            s[i++]=ch+32; // @@ [Error: This incorrectly converts all characters with ASCII value less than 'a' to lowercase by adding 32, but this includes non-letter characters like punctuation and digits, corrupting the string. Only letters should be converted using tolower().]
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
        if (strcmp(w[k].word,w[k+1].word)==0) // @@ [Error: When k = cnt-1, w[k+1] accesses out-of-bounds memory, causing undefined behavior. Also, this merging logic is flawed because it doesn't handle multiple consecutive duplicates correctly and modifies counts in place, potentially skipping words.]
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
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
    file=fopen("file.txt","r"); // @@ [The problem specifies the input file should be "article.txt", but the code opens "file.txt". This will cause a runtime error (e.g., segmentation fault) if "file.txt" doesn't exist, but more critically, it's a logic error. However, the reported error is "gcc: not found", which suggests a compilation environment issue. But since the prompt says to find errors in the program based on the given info and the reference, this filename mismatch is a critical bug.]
    ch=fgetc(file);
    while(ch!=EOF)
    {
        if(ch<'a')
            s[i++]=ch+32; // @@ [This condition `ch<'a'` incorrectly assumes all non-lowercase letters should be lowercased. It will convert digits, punctuation, etc., into invalid characters (e.g., '0'+32 = '@'). Only uppercase letters (A-Z) should be converted to lowercase. This leads to non-letter characters being treated as part of words later.]
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
    // @@ [Missing handling for the last word if the file doesn't end with a non-letter character. If the text ends with a word, it won't be added to the array because the loop ends without triggering the `else` block.]
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
        if (strcmp(w[k].word,w[k+1].word)==0) // @@ [When k == cnt-1, w[k+1] accesses out-of-bounds memory, leading to undefined behavior (likely crash or garbage comparison).]
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
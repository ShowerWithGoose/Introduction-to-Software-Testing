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
    file=fopen("file.txt","r"); // @@ The problem states the file name is "article.txt", but here it opens "file.txt". This will likely cause a NULL pointer dereference or failure to read, leading to Runtime Error or incorrect output.
    ch=fgetc(file);
    while(ch!=EOF)
    {
        if(ch<'a') // @@ This logic for converting to lowercase is flawed. It converts any character with ASCII value less than 'a' (including digits, punctuation, and control characters) by adding 32, which is incorrect. It should only convert uppercase letters ('A'-'Z') to lowercase. Also, it doesn't handle non-alpha characters correctly for storage (they are stored as garbage/modified chars instead of being skipped or acting as delimiters properly in the subsequent step).
            s[i++]=ch+32;
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
            tmp[i]='\0'; // @@ Missing null terminator for the string in tmp before copying. strcpy requires a null-terminated string. Without this, strcpy may read out of bounds.
            i=0;
            strcpy(w[cnt].word,tmp);
            memset(tmp,0,sizeof(tmp));
            w[cnt].count=1;
            cnt++;
            }
            else continue;
        }
    }
    if (i > 0) { // @@ If the file ends with a letter, the last word is not processed because the loop finishes without hitting the 'else' block to flush the buffer.
        tmp[i] = '\0';
        strcpy(w[cnt].word, tmp);
        w[cnt].count = 1;
        cnt++;
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
        if (strcmp(w[k].word,w[k+1].word)==0) // @@ Accessing w[k+1] when k is cnt-1 leads to out-of-bounds access (Runtime Error). Also, the logic for merging counts is flawed for sorted arrays where duplicates might be adjacent but not necessarily just k and k+1 in a simple single-pass without careful index management or using a different approach. However, the immediate crash is due to out-of-bounds access.
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
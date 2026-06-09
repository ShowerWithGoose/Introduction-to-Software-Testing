#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct Key
{
    char word[20];
    int count;
};
typedef struct Key key;
key keytab[100];
char temp[20];
int cmp(const void*p1,const void*p2);
int Alpha(char ch);

int main()
{
    freopen("article.txt","r",stdin);
    
    char ch;
    int i=0,j=0,k=0;
    while((ch=getchar())!=EOF) // @@ The original code `ch=getchar()!=EOF` assigns the boolean result of the comparison (0 or 1) to ch, instead of the character itself. Parentheses are needed to assign the character first, then compare with EOF.
    {
        if(Alpha(ch)==1)
        {
            ch=tolower(ch);
            temp[i]=ch;
            i++;
        }
        else
        {
            if(i==0)
            {
                continue;
            }
            else
            {
                for(j=0;j<i;j++)
                {
                    keytab[k].word[j]=temp[j];
                }
                keytab[k].word[i] = '\0'; // @@ The word string in keytab is not null-terminated after copying characters from temp. This leads to undefined behavior when using strcmp or printf later.
                k++;
                i=0;
            }
        }
    }
    
    qsort(keytab,k,sizeof(key),cmp);
    
    for(i=0;i<k;i++)
    {
        keytab[i].count++; // @@ The count is initialized to 0 (global variable), so incrementing it here sets it to 1. This logic is flawed because it assumes every entry is unique initially, but the subsequent merge logic is also incorrect. A standard approach is to initialize counts to 1 during insertion or handle accumulation differently. However, the primary logical error is in the next lines.
        if(i < k - 1 && strcmp(keytab[i].word,keytab[i+1].word)==0) // @@ Accessing keytab[i+1] when i is k-1 causes out-of-bounds access. Also, the logic below attempts to merge counts but leaves gaps and zeros which complicates printing.
        {
            keytab[i+1].count+=keytab[i].count;
            keytab[i].count=0;
        }
    }
    
    for(i=0;i<k;i++)
    {
        if(keytab[i].count!=0)
        {
            printf("%s %d\n",keytab[i].word,keytab[i].count);
        }
    }
    
    return 0;
}

int cmp(const void*p1,const void*p2)
{
    key *a=(key*)p1;
    key *b=(key*)p2;
    return strcmp(a->word,b->word);
}

int Alpha(char ch)
{
    if(ch>='A' && ch<='Z')
    {
        return 1;
    }
    else if(ch>='a' && ch<='z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
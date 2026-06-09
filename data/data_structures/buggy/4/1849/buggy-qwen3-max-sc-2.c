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
    while(ch=getchar()!=EOF) // @@ [Operator precedence error: assignment 'ch=getchar()' happens after comparison with EOF due to '!=' having higher precedence than '='. Should be '(ch=getchar())!=EOF'. Also, 'ch' should be declared as int to properly handle EOF.]
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
                keytab[k].word[i]='\0'; // @@ [Missing null terminator for the word string, leading to undefined behavior when using string functions like strcmp later.]
                k++;
                i=0;
            }
        }
    }
    if(i>0) // @@ [Missing handling of the last word in the file if it is not followed by a non-alphabetic character (e.g., file ends with a word).]
    {
        for(j=0;j<i;j++)
        {
            keytab[k].word[j]=temp[j];
        }
        keytab[k].word[i]='\0';
        k++;
    }
    
    qsort(keytab,k,sizeof(key),cmp);
    
    for(i=0;i<k;i++) // @@ [Incorrect frequency counting logic: initializes count to garbage (uninitialized), increments every entry once, then tries to merge duplicates only with next element. This fails for non-consecutive duplicates and doesn't correctly aggregate counts.]
    {
        keytab[i].count++; // @@ [count is uninitialized; should initialize all counts to 0 before this loop. Also, incrementing before checking duplicates leads to wrong counts.]
        if(strcmp(keytab[i].word,keytab[i+1].word)==0) // @@ [Accesses keytab[i+1] when i == k-1, causing out-of-bounds read (undefined behavior).]
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
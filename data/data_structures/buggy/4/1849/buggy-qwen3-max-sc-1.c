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
    while(ch=getchar()!=EOF) // @@ [Operator precedence error: '=' has lower precedence than '!=', so it evaluates as ch = (getchar() != EOF), making ch a boolean (0 or 1), not the actual character. Should be: while((ch=getchar())!=EOF)]
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
                keytab[k].word[i]='\0'; // @@ [Missing null terminator: after copying characters into keytab[k].word, the string is not null-terminated, leading to undefined behavior in strcmp and printf]
                k++;
                i=0;
            }
        }
    }
    
    // @@ [Missing handling of last word: if the file ends without a non-alphabetic character, the final word in temp is never flushed to keytab]
    
    qsort(keytab,k,sizeof(key),cmp);
    
    for(i=0;i<k;i++) // @@ [Incorrect frequency counting logic: initializes count by incrementing (from uninitialized value), then tries to merge adjacent duplicates, but fails because counts start uninitialized and merging only checks next element once]
    {
        keytab[i].count++; // @@ [Using uninitialized count field: keytab[i].count was never initialized to 0, so incrementing leads to undefined behavior]
        if(strcmp(keytab[i].word,keytab[i+1].word)==0) // @@ [Out-of-bounds access: when i == k-1, keytab[i+1] accesses beyond the array]
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
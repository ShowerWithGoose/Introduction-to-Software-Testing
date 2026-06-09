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
    while(ch=getchar()!=EOF) // @@ [Operator precedence error: '!=' has higher precedence than '=', so 'ch' is assigned the result of (getchar() != EOF), which is 0 or 1, not the character. Should be: while((ch=getchar())!=EOF)]
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
                keytab[k].word[i]='\0'; // @@ [Missing null terminator after copying word into keytab[k].word, leading to undefined behavior when using string functions like strcmp]
                keytab[k].count=0; // @@ [count is never initialized properly; it should start at 1 for a new word, but here it's uninitialized and later incremented unconditionally]
                k++;
                i=0;
            }
        }
    }
    
    // @@ [Missing handling of last word if file doesn't end with non-alphabetic character]
    
    qsort(keytab,k,sizeof(key),cmp);
    
    for(i=0;i<k;i++) // @@ [Loop accesses keytab[i+1] when i = k-1, causing out-of-bounds read]
    {
        keytab[i].count++; // @@ [Incorrectly increments count for every entry before checking duplicates; should only set initial count once during word extraction]
        if(strcmp(keytab[i].word,keytab[i+1].word)==0)
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
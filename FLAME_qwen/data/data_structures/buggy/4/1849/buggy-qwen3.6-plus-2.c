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
    while(ch=getchar()!=EOF) // @@ Operator precedence error: != has higher precedence than =, causing ch to be assigned 0 or 1 instead of the actual character read. It should be (ch=getchar())!=EOF. Also, ch should be int to correctly handle EOF.
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
                k++; // @@ Missing null terminator '\0' assignment for keytab[k].word[i] before incrementing k. This leaves strings unterminated, causing strcmp to read out of bounds.
                i=0;
            }
        }
    }
    
    qsort(keytab,k,sizeof(key),cmp);
    
    for(i=0;i<k;i++)
    {
        keytab[i].count++;
        if(strcmp(keytab[i].word,keytab[i+1].word)==0) // @@ Out-of-bounds array access when i equals k-1, accessing keytab[k]. The loop should iterate up to k-1 to avoid reading uninitialized memory and incorrect counting.
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
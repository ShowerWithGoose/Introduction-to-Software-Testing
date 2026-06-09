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
    while((ch=getchar())!=EOF) // @@ Operator precedence error: != has higher precedence than =, so ch gets assigned 0 or 1 instead of the character. Also added parentheses to fix logic.
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
                keytab[k].word[j] = '\0'; // @@ Missing null terminator for the string in keytab[k].word, which will cause undefined behavior when printing or comparing strings.
                k++;
                i=0;
            }
        }
    }
    
    qsort(keytab,k,sizeof(key),cmp);
    
    for(i=0;i<k;i++)
    {
        keytab[i].count++; // @@ Logic error: This increments count for every element initially, but the subsequent logic relies on accumulating counts from duplicates. It should likely be initialized to 1 before accumulation or handled differently. However, the bigger issue is below.
        if(i < k - 1 && strcmp(keytab[i].word,keytab[i+1].word)==0) // @@ Added boundary check i < k - 1 to prevent accessing keytab[k] which is out of bounds.
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
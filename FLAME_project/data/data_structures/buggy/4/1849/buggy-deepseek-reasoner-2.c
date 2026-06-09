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
    while(ch=getchar()!=EOF) // @@ Operator precedence error: should be (ch=getchar())!=EOF, causing ch to be 1 or 0 instead of the character
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
                // @@ Missing null terminator: need keytab[k].word[i]='\0';
                // @@ Missing initialization: keytab[k].count should be set to 1
                k++;
                i=0;
            }
        }
    }
    
    // @@ Missing handling of last word when EOF is reached without a delimiter: if(i>0) ... same as in the else block
    
    qsort(keytab,k,sizeof(key),cmp);
    
    for(i=0;i<k;i++)
    {
        keytab[i].count++; // @@ Wrong: counts were never initialized, so this adds to garbage. Should have been set to 1 earlier.
        if(strcmp(keytab[i].word,keytab[i+1].word)==0) // @@ Potential out-of-bounds when i==k-1, accessing keytab[k] which is invalid
        {
            keytab[i+1].count+=keytab[i].count; // @@ Logic error: accumulates incorrectly; reference program uses separate array for unique words
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
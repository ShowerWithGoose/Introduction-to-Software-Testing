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
                keytab[k].word[i]='\0'; // @@ [Missing null terminator after copying word into keytab[k].word, leading to undefined behavior in strcmp and printf]
                k++;
                i=0;
            }
        }
    }
    if(i>0) // @@ [Missing handling of last word in file if file doesn't end with non-alphabetic character; the final word may not be added to keytab]
    {
        for(j=0;j<i;j++)
        {
            keytab[k].word[j]=temp[j];
        }
        keytab[k].word[i]='\0';
        k++;
    }
    
    qsort(keytab,k,sizeof(key),cmp);
    
    for(i=0;i<k;i++) // @@ [Logic error: initializing count inside loop after sorting instead of during word collection; also comparing keytab[i+1] when i=k-1 leads to out-of-bounds access]
    {
        keytab[i].count++; // @@ [Incorrectly initializing count here; should have been initialized to 1 when word was first stored, or better yet, counted properly during input processing]
        if(i+1 < k && strcmp(keytab[i].word,keytab[i+1].word)==0) // @@ [Without bounds check, keytab[i+1] is invalid when i == k-1]
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
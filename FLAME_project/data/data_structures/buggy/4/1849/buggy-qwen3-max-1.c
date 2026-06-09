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
    while(ch=getchar()!=EOF) // @@ [The assignment 'ch=getchar()!=EOF' is evaluated as 'ch = (getchar() != EOF)', which assigns 0 or 1 to ch, not the actual character. This causes incorrect character processing.]
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
                keytab[k].word[i]='\0'; // @@ [Missing null terminator after copying word into keytab[k].word, leading to undefined behavior when using string functions like strcmp.]
                keytab[k].count=0; // @@ [count is never initialized properly before incrementing later; should be set to 1 here for the first occurrence.]
                k++;
                i=0;
            }
        }
    }
    
    // @@ [Missing handling of the last word in the file if the file doesn't end with a non-alphabetic character. The final word may not be added to keytab.]
    
    qsort(keytab,k,sizeof(key),cmp);
    
    for(i=0;i<k;i++) // @@ [This loop accesses keytab[i+1] when i = k-1, causing out-of-bounds read and undefined behavior.]
    {
        keytab[i].count++; // @@ [Incrementing count here assumes it was zero-initialized, but it wasn't properly set during word insertion. Also, logic for merging duplicates is flawed.]
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
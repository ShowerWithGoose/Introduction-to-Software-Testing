#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
typedef struct word{
    char s[20];
    int x;
}word;
int cmp(const void *a, const void *b);
int main()
{
    struct word tj[100];
    freopen("article.txt","r",stdin);
    int i=0,j=0;
    char ch;
    while(scanf("%c",&ch)!=EOF)
    {
        if(isalpha(ch))
        {
            if(ch>='A'&&ch<='Z')
            {
                ch=ch+'a'-'A';
            }
            tj[i].s[j]=ch;
            tj[i].x=1;
            j++;
        }
        else if(ch==' '||ch=='\n'||ch=='.'||ch==';'||ch=='\"')
        {
            tj[i].x=1;
            tj[i].s[j]='\0';
            i++;
            j=0;
        }
    }
    qsort(tj,i,sizeof(word),cmp); // @@ [The program does not handle the case where the file ends without a delimiter, so the last word may not be null-terminated or stored properly. Also, array bounds are not checked, risking buffer overflow.]
    int n=0;
    while(n<i)
    {
        if(strcmp(tj[n].s,tj[n+1].s)!=0) // @@ [Accesses tj[n+1] when n == i-1, leading to out-of-bounds read and undefined behavior.]
        {
            if(strlen(tj[n].s)>=1)
            {
                printf("%s %d\n",tj[n].s,tj[n].x);
            } 
        }
        else
        {
            tj[n+1].x=tj[n].x+tj[n+1].x; // @@ [Same out-of-bounds access when n == i-1; also, this merging logic is flawed because it doesn't skip zero-count entries and doesn't accumulate counts correctly across multiple duplicates.]
        }
        n++;
    }
    return 0;
}
int cmp(const void *a, const void *b)
{
    word *a1=(word *)a;
    word *b1=(word *)b;
    return(strcmp(a1->s,b1->s));
}
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
        else if(ch==' '||ch=='\n'||ch=='.'||ch==';'||ch=='\"') // @@ Incomplete delimiter set; non‑alphabetic characters like parentheses, commas, digits, and curly quotes are not handled, causing words to be concatenated.
        {
            tj[i].x=1;
            tj[i].s[j]='\0';
            i++;
            j=0;
        }
    }
    qsort(tj,i,sizeof(word),cmp);
    int n=0;
    while(n<i) // @@ Loop condition leads to out‑of‑bounds access when n = i-1 because the loop body accesses tj[n+1] which is tj[i] (beyond the actual array).
    {
        if(strcmp(tj[n].s,tj[n+1].s)!=0) // @@ Accesses tj[i] when n = i-1 (out‑of‑bounds); also the merging logic does not handle the last element properly.
        {
            if(strlen(tj[n].s)>=1)
            {
                printf("%s %d\n",tj[n].s,tj[n].x);
            } 
        }
        else
        {
            tj[n+1].x=tj[n].x+tj[n+1].x;
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
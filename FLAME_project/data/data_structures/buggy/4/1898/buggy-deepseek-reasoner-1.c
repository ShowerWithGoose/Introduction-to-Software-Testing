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
        else if(ch==' '||ch=='\n'||ch=='.'||ch==';'||ch=='\"') // @@ This condition only ends a word on specific delimiters, causing words to be concatenated across other non‑alphabetic characters (e.g., digits, parentheses, commas). All non‑letters should trigger the end of the current word.
        {
            tj[i].x=1;
            tj[i].s[j]='\0';
            i++;
            j=0;
        }
    }
    qsort(tj,i,sizeof(word),cmp);
    int n=0;
    while(n<i)
    {
        if(strcmp(tj[n].s,tj[n+1].s)!=0) // @@ When n equals i-1, tj[n+1] accesses memory beyond the array, causing undefined behavior.
        {
            if(strlen(tj[n].s)>=1)
            {
                printf("%s %d\n",tj[n].s,tj[n].x);
            } 
        }
        else
        {
            tj[n+1].x=tj[n].x+tj[n+1].x; // @@ This accumulation is flawed for runs of more than two identical words and does not preserve correct final counts.
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
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
            tj[i].x=1; // @@ This line incorrectly resets the count to 1 for every character added to the current word, instead of initializing it only when a new word starts. It should be removed or moved to the word initialization block.
            j++;
        }
        else if(ch==' '||ch=='\n'||ch=='.'||ch==';'||ch=='\"') // @@ The condition for delimiters is incomplete. It misses other non-alphabetic characters like ',', '(', ')', digits, etc., which causes words to merge incorrectly (e.g., "language" and "C" merging into "languagec" because '(' is not handled). It should use !isalpha(ch) or a more comprehensive check.
        {
            tj[i].x=1; // @@ This line sets the count to 1 again, overwriting any previous logic. More importantly, if j==0 (consecutive delimiters), this creates an empty word entry which might cause issues later. It should only finalize the word if j > 0.
            tj[i].s[j]='\0';
            i++;
            j=0;
        }
    }
    qsort(tj,i,sizeof(word),cmp);
    int n=0;
    while(n<i)
    {
        if(strcmp(tj[n].s,tj[n+1].s)!=0)
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
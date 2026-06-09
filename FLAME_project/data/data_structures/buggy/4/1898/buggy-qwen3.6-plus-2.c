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
            tj[i].x=1; // @@ [Logic Error: This line resets the count to 1 for every character added to the current word. It should only initialize the count when a new word starts (i.e., when j==0). Furthermore, the final count logic in the output loop is flawed because it doesn't correctly aggregate duplicates if the initial counts are messed up or if the aggregation logic skips printing.]
            j++;
        }
        else if(ch==' '||ch=='\n'||ch=='.'||ch==';'||ch=='\"') // @@ [Logic Error: The condition for delimiters is incomplete. It misses other non-alphabetic characters like commas ',', parentheses '(', ')', and digits which act as word boundaries. For example, "since1972" fails to separate "since" because '1' is not handled here, causing "since" to merge with subsequent letters if any, or just fail to terminate the word properly before digits. More critically, digits are not treated as delimiters, so "since1972" will treat "since" as part of a longer sequence if not handled. Actually, looking at the input "since1972.", '1' is not alpha, and not in this delimiter list. So the word "since" is never terminated before '1'. The code falls through to nothing, effectively ignoring '1' but keeping j incremented? No, if it's not alpha and not in this specific delimiter list, it does nothing. So 's','i','n','c','e' are stored. Then '1' comes. It is not alpha. It is not ' ', '\n', '.', ';', '"'. So the else-if block is skipped. The loop continues. The word buffer tj[i].s is not null-terminated, and j is not reset. Then '9' comes, same thing. Then '7', same. Then '2', same. Then '.' comes. It IS in the list. So tj[i].s[j] (where j is 5) is set to '\0'. So "since" is stored. BUT, the next character is EOF or newline? If the file ends, the last word might not be processed if it doesn't end with a delimiter. In the test case "since1972.", the period triggers the termination. So "since" is saved. However, the digit handling is risky. A better approach is `else` block to handle any non-alpha as a delimiter.]
        {
            tj[i].x=1; // @@ [Redundant/Confusing Logic: Setting x=1 here again is confusing since it was set inside the alpha block. The main issue is that this block assumes a word has just finished. But if multiple delimiters appear consecutively, this will create empty words or overwrite state incorrectly.]
            tj[i].s[j]='\0';
            i++;
            j=0;
        }
        // @@ [Logic Error: Missing an `else` clause to handle other non-alphabetic characters (like digits, commas, parentheses) which should also act as word terminators. Without this, words adjacent to digits or unlisted punctuation are not terminated correctly.]
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
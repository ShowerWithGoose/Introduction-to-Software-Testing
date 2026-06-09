#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void turnword(char c[]);
int cmp(const void *p1, const void *p2);
struct dic
{
    char word[1000];
    int fre;
};
int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    struct dic a[1000]={};
    int n = 0;
    int find = 0;
    char s[1000];
    char c;
    int k = 0;
    while ((c = fgetc(in)) != EOF)
    {
        if(c>='a'&&c<='z'||c=='-') // @@ The condition incorrectly includes hyphens as part of words and excludes other valid letters if locale differs, but more importantly, it fails to handle the end of a word correctly when a non-letter is encountered. It resets k=0 but doesn't process the accumulated word if the current char is not a letter. The logic for word boundary detection is flawed because it only processes a word when a non-letter is found, but if the file ends with a letter, the last word is lost. Also, the condition `c=='-'` treats hyphens as part of the word, which contradicts the definition "consisting only of letters".
        {
            s[k] = c;
            k++;
            continue;
        }
        else if(c>='A'&&c<='Z')
        {
            s[k] = tolower(c);
            k++;
            continue;
        }
        else
        {
            k = 0; // @@ This resets the index but does not process the word stored in s before resetting. If a word was being built, it is now lost because k is reset to 0 without saving the word. The word processing logic below relies on s[0]!=0, but s is not null-terminated properly before this point in all paths, and the reset happens before the check.
        }
        if(s[0]==0) // @@ This check is insufficient. s is not guaranteed to be null-terminated. It should check if k > 0 to see if a word was accumulated.
            continue;
        find = 0;
        for (int i = 0; i < n; i++)
        {
            if(strcmp(s,a[i].word)==0)
            {
                find = 1;
                a[i].fre++;
                break;
            }
        }
        if(find==0)
        {
            strcpy(a[n].word, s); // @@ s is not null-terminated, so strcpy may read beyond the intended word length, leading to undefined behavior or incorrect words.
            a[n].fre = 1;
            n++;
        }
        memset(s, 0, sizeof(s));
    }
    qsort(a, n, sizeof(a[1]), cmp); // @@ Using sizeof(a[1]) is technically correct for the element size, but standard practice is sizeof(a[0]). More critically, if the last word in the file is not followed by a non-letter character, it is never processed because the loop exits. The word accumulation logic is fundamentally broken regarding when a word is considered "complete".
    for (int i = 0; i < n; i++)
    {
        if(a[i].word[0]!=0)
        printf("%s %d\n", a[i].word, a[i].fre);
    }
        return 0;
}


int cmp(const void *p1,const void *p2)
{
    if(strcmp(((struct dic *)p1)->word,((struct dic *)p2)->word)>0)
    return 1;
    else if(strcmp(((struct dic *)p1)->word,((struct dic *)p2)->word)<0)
    return -1;
    else
    return 0;
    
}
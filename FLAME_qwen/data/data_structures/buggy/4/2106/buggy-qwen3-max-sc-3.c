#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void turnword(char c[]); // @@ [Function 'turnword' is declared but never defined or used; however, this alone wouldn't cause a compilation error. The real issue is missing #include <ctype.h> for 'tolower'.]
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
        if(c>='a'&&c<='z'||c=='-') // @@ [According to problem description, words consist only of letters. Hyphen '-' should not be considered part of a word. This causes incorrect word parsing. Also, using character range checks instead of isalpha() is less portable and misses non-ASCII letters (though likely acceptable here). However, the bigger issue is that '-' is included as part of a word, violating spec.]
        {
            s[k] = c;
            k++;
            continue;
        }
        else if(c>='A'&&c<='Z')
        {
            s[k] = tolower(c); // @@ [Missing #include <ctype.h>, so tolower may not be recognized, leading to compilation warning or error depending on compiler settings. This is likely the root cause of the compilation error.]
            k++;
            continue;
        }
        else
        {
            k = 0; // @@ [This resets k to 0 without processing the current word in s. It should process the word before resetting. Also, setting k=0 here discards the word just read. The logic for word termination is flawed: it only processes when hitting a non-letter, but then sets k=0 BEFORE processing, and also doesn't null-terminate s properly before use. Moreover, after setting k=0, it proceeds to check s[0]==0, which may skip processing, but the word was already lost.]
        }
        if(s[0]==0)
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
            strcpy(a[n].word, s);
            a[n].fre = 1;
            n++;
        }
        memset(s, 0, sizeof(s));
    }
    qsort(a, n, sizeof(a[1]), cmp); // @@ [sizeof(a[1]) is correct, but typically sizeof(struct dic) or sizeof(*a) is clearer. Not an error, but note: if n is 0, qsort is safe. However, the main issue is that the last word in the file may not be processed if the file doesn't end with a non-letter character.]
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
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
        if(c>='a'&&c<='z'||c=='-')
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
            k = 0; // @@ [This resets k to 0 but does not process the word collected so far. Words are only processed after non-alphabetic characters, but resetting k here discards the current word without saving it. Also, hyphen '-' is incorrectly treated as part of a word, which violates the problem's definition that words consist only of letters.]
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
    qsort(a, n, sizeof(a[1]), cmp); // @@ [sizeof(a[1]) should be sizeof(struct dic) or sizeof(a[0]). Using a[1] is misleading and may cause issues if array indexing changes, though it works here. However, more critically, the program fails to handle the last word in the file if the file doesn't end with a non-alphabetic character, because word processing only occurs when a non-letter is encountered.]
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
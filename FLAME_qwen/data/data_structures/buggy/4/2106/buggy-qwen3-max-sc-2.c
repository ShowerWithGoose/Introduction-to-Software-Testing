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
            k = 0; // @@ [This resets k to 0 but does not null-terminate s or process the word collected so far. Also, words are only processed when a non-letter is encountered, but if the file ends with a letter, the last word is never processed. Additionally, '-' is incorrectly treated as part of a word, violating the problem's definition that words consist only of letters.]
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
    qsort(a, n, sizeof(a[1]), cmp); // @@ [sizeof(a[1]) is equivalent to sizeof(struct dic), which is correct, but using sizeof(*a) or sizeof(struct dic) would be clearer. However, this is not the cause of the compilation error.]
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
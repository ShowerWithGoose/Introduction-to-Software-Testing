#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N;  //count
struct wordcount{
    char word[30];
    int count;
}a[1024];
char s[30], scmp[30];
char c;
int getWord(FILE *in)   //get word
{
    if(c == EOF)
        return -1;
    memset(s, '\0', 30);
    while((c = fgetc(in)) != EOF && (c < 'A' || c > 'z' || (c > 'Z' && c < 'a')))
        ;
    if(c == EOF)
        return -1;
    s[0] = (c <= 'Z' ? c - 'A' + 'a' : c);
    int i;
    for(i = 1; ((c = fgetc(in)) >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); i++)
        s[i] = (c <= 'Z' ? c - 'A' + 'a' : c);
    return 0;
}
int search()
{
    int i;
    for(i = 0; i < N && strcmp(a[i].word, s) != 0; i++)
        ;
    return i;
}
int cmp(const void *a1, const void *a2)
{
    struct wordcount *q1 = (struct wordcount *)a1;
    struct wordcount *q2 = (struct wordcount *)a2;
    return strcmp(q1->word, q2->word);
}
int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    while(getWord(in) != -1)
    {
        int pos = 0;
        if((pos = search()) == N)   //new word
        {
            a[N].count = 1;
            strcpy(a[N].word, s);
            N++;
        }
        else
            a[pos].count++;
    }
    qsort(a, N, sizeof(struct wordcount), cmp);
    int j = 0;
    for(j = 0; j < N; j++)
        printf("%s %d\n", a[j].word, a[j].count);
    return 0;
}

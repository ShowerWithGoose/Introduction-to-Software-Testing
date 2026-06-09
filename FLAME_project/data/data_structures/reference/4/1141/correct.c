#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct list{
    char word[20];
    int cnt;
}wordlist[500];
int n=0;
int cmp(const void *p1, const void *p2)
{
    struct list *x = (struct list *)p1;
    struct list *y = (struct list *)p2;
    return strcmp(x->word, y->word);
};
void searchword(char wor[20])
{
    int i;
    if(n==0)
    {
        strcpy(wordlist[n].word,wor);
        wordlist[n].cnt=1;
        n++;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(strcmp(wordlist[i].word,wor)==0)
            {
                wordlist[i].cnt++;
                break;
            }
        }
        if(i==n)
        {
            wordlist[n].cnt=1;
            strcpy(wordlist[n].word,wor);
            n++;
        }
    }
}
void to_lower(char wor[200])
{
    int i=0;
    for(i=0;i<strlen(wor);i++)
    {
        if(wor[i]<='Z'&&wor[i]>='A')
        wor[i]+=32;
    }
}
int main()
{
    FILE *fp;
    fp=fopen("article.txt","r");
    char s[200];
    while(fgets(s,1023,fp)!=NULL)
    {
        int i=0,j=0,k=0;
        char wor[20];
        to_lower(s);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                for(j=i;s[j]>='a'&&s[j]<='z';j++)
                {
                     wor[k]=s[j];
                     k++;
                }
                wor[k]='\0';
                i=j;
                k = 0;
                searchword(wor);
            }
        }
    }
    qsort(wordlist, n, sizeof(wordlist[0]), cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s %d\n",wordlist[i].word,wordlist[i].cnt);
    }
    return 0;
}

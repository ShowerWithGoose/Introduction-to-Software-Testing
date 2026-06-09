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
    int flag;
    if(n==0)
    {
        strcpy(wordlist[n].word,wor);
        wordlist[n].cnt=1;
        n++;
    }
    else
    {
        for(flag=0;flag<n;flag++)
        {
            if(strcmp(wordlist[flag].word,wor)==0)
            {
                wordlist[flag].cnt++;
                break;
            }
        }
        if(flag==n)
        {
            wordlist[n].cnt=1;
            strcpy(wordlist[n].word,wor);
            n++;
        }
    }
}
void to_lower(char wor[200])
{
    int flag=0;
    for(flag=0;flag<strlen(wor);flag++)
    {
        if(wor[flag]<='Z'&&wor[flag]>='A')
        wor[flag]+=32;
    }
}
int main()
{
    FILE *fp;
    fp=fopen("article.txt","r");
    char ch[200];
    while(fgets(ch,1023,fp)!=NULL)
    {
        int flag=0,j=0,k=0;
        char wor[20];
        to_lower(ch);
        for(flag=0;flag<strlen(ch);flag++)
        {
            if(ch[flag]>='a'&&ch[flag]<='z')
            {
                for(j=flag;ch[j]>='a'&&ch[j]<='z';j++)
                {
                     wor[k]=ch[j];
                     k++;
                }
                wor[k]='\0';
                flag=j;
                k = 0;
                searchword(wor);
            }
        }
    }
    qsort(wordlist, n, sizeof(wordlist[0]), cmp);
    for(int flag=0;flag<n;flag++)
    {
        printf("%s %d\n",wordlist[flag].word,wordlist[flag].cnt);
    }
    return 0;
}

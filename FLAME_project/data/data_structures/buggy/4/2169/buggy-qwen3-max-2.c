#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *in,*out;
char line[101];
struct Word
{
    char word[101];
    int len;
}words[1000001];
int sum;
int compare(const void *p1,const void *p2)
{
    struct Word* e1=p1; // @@ [Discards 'const' qualifier; should be 'const struct Word* e1 = (const struct Word*)p1;']
    struct Word* e2=p2; // @@ [Discards 'const' qualifier; should be 'const struct Word* e2 = (const struct Word*)p2;']
    return strcmp(e1->word,e2->word);
}
int main()
{
    in=fopen("article.txt","r");
    int t=0;
    while(fgets(line,81,in)!=NULL)
    {
        //printf("%s\n",line);
        int len=strlen(line);
        for(int i=0;i<len;i++)
        {
            if(line[i]>='A'&&line[i]<='Z')
            line[i]=line[i]+'a'-'A';
        }
        for(int i=0;i<len;i++)
        {
            if((line[i]>='a'&&line[i]<='z')&&(line[i-1]<'a'||line[i-1]>'z'))
            {
                t=1;
                words[sum].word[words[sum].len++]=line[i];
                if((line[i+1]<'a'||line[i+1]>'z')&&line[i+1]!='\0')
                {
                    words[sum].word[words[sum].len]='\0';
                    t=0;
                    sum++;
                }
            }
            else if(t==1)
            {
                if(line[i]>='a'&&line[i]<='z')
                {
                    words[sum].word[words[sum].len++]=line[i];
                }
                if((line[i+1]<'a'||line[i+1]>'z')&&line[i+1]!='\0')
                {
                    words[sum].word[words[sum].len]='\0';
                    t=0;
                    sum++;
                }
            }
        }
    }
    qsort(words,sum,sizeof(w[0]),compare); // @@ ['w' is undeclared; should be 'words' instead of 'w']
    int ans=1;
    for(int i=0;i<sum;i++)
    {
        if(strcmp(words[i+1].word,words[i].word)!=0)
        {
            printf("%s %d\n",w[i].word,ans); // @@ ['w' is undeclared; should be 'words' instead of 'w']
            ans=1;
        }
        else
        {
            ans++;
        }
    }
    return 0;
}
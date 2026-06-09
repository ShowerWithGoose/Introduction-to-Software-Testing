#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct list{
    int cnt;
    char word[100];
}list, *listptr;
list wordlist[100000];
int cmp(const void *p1,const void *p2)
{
    listptr p=(listptr)p1;
    listptr q=(listptr)p2;
    return strcmp(p->word,q->word);
}
int main()
{
    FILE *fp;
    fp=fopen("article.txt","r");
    char ch;
    int n=0,flag=-1;
    while((ch=fgetc(fp))!=EOF)
    {
        if((ch<='z'&&ch>='a')||(ch<='Z'&&ch>='A'))
        {
            flag++;
            wordlist[n].word[flag]=tolower(ch);
        }
        else if(flag>=0)
        {
            wordlist[n].word[++flag]='\0'; // @@ [missing null-termination of the word string after reading a complete word]
            n++;
            flag=-1;
        }
    }
    //文件单词读取完毕
    //下面进行排序
    qsort(wordlist,n,sizeof(list),cmp) ;
    //排序完毕
    for(int i=0;i<n;i++) 
    {
        wordlist[i].cnt=1; // @@ [cnt is uninitialized; must initialize to 1 before counting duplicates]
    }
    for(int i=0;i<n;i++) 
    {
        for(int j=i+1;j<n;j++) // @@ [loop condition j<=n causes out-of-bounds access; should be j < n]
        {
            if(strcmp(wordlist[i].word,wordlist[j].word)==0)
            {
                wordlist[i].cnt++;
                wordlist[j].cnt=0; // @@ [mark duplicate entries with cnt=0 instead of decrementing; original logic flawed]
            }
            else
            break; // @@ [cannot jump i inside inner loop like this; breaks control flow and skips words]
        }
    }
    for(int i=0;i<n;i++)
    {
        if(wordlist[i].cnt>0)
        printf("%s %d\n",wordlist[i].word,wordlist[i].cnt);
    }
    fclose(fp);
    return 0;
}
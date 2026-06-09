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
            n++; @@ // Missing null terminator for the word; also fails to handle last word if file ends with a letter.
            flag=-1;
        }
    }
    //文件单词读取完毕
    //下面进行排序
    qsort(wordlist,n,sizeof(list),cmp) ;
    //排序完毕
    for(int i=0;i<n;i++) 
    {
        for(int j=i;j<=n;j++) @@ // j loops to n inclusive, out-of-bounds access (max index n-1).
        {
            if(strcmp(wordlist[i].word,wordlist[j].word)==0) @@ // When j==n, wordlist[n] is uninitialized or garbage.
            {
                wordlist[i].cnt++; @@ // cnt not initialized, using garbage value.
                if(i!=j)
                wordlist[j].cnt--; @@ // Same uninitialized cnt issue.
            }
            else
            i=j+1; @@ // Modifying loop variable i inside inner loop leads to skipping words and incorrect counting.
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
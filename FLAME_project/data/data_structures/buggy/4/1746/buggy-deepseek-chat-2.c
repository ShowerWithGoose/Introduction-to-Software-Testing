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
            n++; // @@ Error: The word count `n` is incremented here, but the `cnt` field of the wordlist entry is never initialized to 0. Also, when a new word starts, `flag` is reset to -1, but the previous word's `cnt` remains uninitialized, leading to undefined behavior.
            flag=-1;
        }
    }
    //文件单词读取完毕
    //下面进行排序
    qsort(wordlist,n,sizeof(list),cmp) ;
    //排序完毕
    for(int i=0;i<n;i++) 
    {
        for(int j=i;j<=n;j++) // @@ Error: The inner loop condition `j<=n` accesses `wordlist[n]` which is out of bounds (valid indices are 0 to n-1). This causes undefined behavior.
        {
            if(strcmp(wordlist[i].word,wordlist[j].word)==0)
            {
                wordlist[i].cnt++;
                if(i!=j)
                wordlist[j].cnt--;
            }
            else
            i=j+1; // @@ Error: This modifies the outer loop variable `i` inside the inner loop, causing incorrect iteration and skipping words. The logic for counting frequencies is fundamentally flawed.
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
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
            wordlist[n].word[++flag]='\0'; // @@ [Missing null-termination of the current word; without this, strcmp may read garbage beyond the word]
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
        wordlist[i].cnt = 0; // @@ [cnt is never initialized to 0, leading to undefined behavior when incrementing]
    }
    for(int i=0;i<n;i++) 
    {
        for(int j=i;j<=n;j++) // @@ [Loop condition j<=n accesses wordlist[n], which is out of bounds (valid indices are 0 to n-1)]
        {
            if(strcmp(wordlist[i].word,wordlist[j].word)==0)
            {
                wordlist[i].cnt++;
                if(i!=j)
                wordlist[j].cnt--; // @@ [This logic is flawed: it tries to deduplicate by decrementing others, but doesn't skip already processed duplicates correctly]
            }
            else
            i=j+1; // @@ [Modifying loop variable i inside inner loop causes unpredictable iteration and skips words]
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
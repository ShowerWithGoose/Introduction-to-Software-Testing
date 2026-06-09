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
    char ch; // @@ [fgetc returns int, storing in char can cause EOF comparison failure on some implementations]
    int n=0,flag=-1;
    while((ch=fgetc(fp))!=EOF) // @@ [ch should be int to correctly compare with EOF]
    {
        if((ch<='z'&&ch>='a')||(ch<='Z'&&ch>='A'))
        {
            flag++;
            wordlist[n].word[flag]=tolower(ch);
        }
        else if(flag>=0) // @@ [no null terminator added after completing the word; also need to handle the last word after the loop]
        {
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
        for(int j=i;j<=n;j++) // @@ [j goes out of bounds when j == n; should be j < n]
        {
            if(strcmp(wordlist[i].word,wordlist[j].word)==0) // @@ [access to wordlist[n] is out of bounds when j == n]
            {
                wordlist[i].cnt++; // @@ [cnt uninitialized, leads to undefined behavior]
                if(i!=j)
                wordlist[j].cnt--; // @@ [cnt uninitialized and logic flawed; decrementing is not the correct way to deduplicate]
            }
            else
            i=j+1; // @@ [modifying loop control variable i inside the loop disrupts the outer loop logic]
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
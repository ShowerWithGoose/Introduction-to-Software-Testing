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
            wordlist[n].word[++flag]='\0'; // @@ [Missing null-termination of the current word when a non-letter is encountered; without this, the string is not properly terminated, leading to undefined behavior during strcmp and printing. Also, 'flag' should be incremented before setting '\0'.]
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
        for(int j=i;j<=n;j++) // @@ [Loop condition 'j<=n' accesses wordlist[n], which is out of bounds (valid indices are 0 to n-1). This causes undefined behavior. Should be 'j < n'.]
        {
            if(strcmp(wordlist[i].word,wordlist[j].word)==0)
            {
                wordlist[i].cnt++; // @@ [cnt is never initialized to 0 or 1, so incrementing uninitialized memory leads to garbage counts. Each word's cnt should start at 1 upon creation.]
                if(i!=j)
                wordlist[j].cnt--; // @@ [This logic is flawed: decrementing other entries doesn't correctly aggregate counts and may result in negative or incorrect values. Standard approach is to count duplicates then skip them, not manipulate counts of others.]
            }
            else
            i=j+1; // @@ [Modifying loop variable 'i' inside inner loop disrupts outer loop control flow, causing skipped words or infinite loops. This is incorrect logic for grouping identical words after sorting.]
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
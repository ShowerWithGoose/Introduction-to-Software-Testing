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
            wordlist[n].word[++flag]='\0'; // @@ [The null terminator is not added when a word ends, causing undefined behavior during string operations like strcmp. Also, 'flag' is used as index but not reset properly before next word.]
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
        wordlist[i].cnt=1; // @@ [The 'cnt' field is never initialized to 1 before counting, leading to garbage values being used in frequency calculation.]
    }
    for(int i=0;i<n;i++) 
    {
        for(int j=i+1;j<n;j++) // @@ [The inner loop condition 'j<=n' goes out of bounds (index n is invalid). Also, the logic for grouping duplicates and skipping processed words is flawed due to incorrect control flow with 'i=j+1' inside the inner loop.]
        {
            if(strcmp(wordlist[i].word,wordlist[j].word)==0)
            {
                wordlist[i].cnt++;
                wordlist[j].cnt=0; // @@ [Instead of decrementing, set duplicate entries' count to 0 so they can be skipped later. The current logic with 'cnt--' doesn't correctly handle initial uninitialized counts.]
            }
            else
                break; // @@ [Since the array is sorted, once a different word is found, we can break early. The original 'i=j+1' modifies outer loop variable inside inner loop, causing unpredictable iteration behavior.]
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
#include <stdio.h>
#include <math.h>
#include <string.h>
//#define NULL 0
#include <ctype.h>

//typedef struct code{
//    char a;
//    struct code *next;
//}co;
//co *headzhizhen(int N)
//{
//    co *first=NULL,*p=NULL;
//    first=(co*)malloc(sizeof(co));
//    first=p;
//    for(int i=0;i<N;i++)
//    {
//        co *q=(co *)malloc(sizeof(co));
//        q->a=ch[i];
//        q->next=NULL;
//        p->next=q;
//        p=q;
//    }
//    p=first->next;
//    free(first);
//    return p;
//}
//单向链表建立，若为循环链表最后几步需要替换
//p->next=first->next;串联起来
//first=first->next;将first从第一个空的节点挪向头节点
//free(p);
//return first;
typedef struct Word
{
    char s[100];
    int cs;
}word;
int main() 
{
    word w[100]={0};
    FILE *inp;
    inp = fopen("article.txt", "r");
    if (inp==NULL)
    {
        printf("wrong");
        return 0;
    }
    
    
    char ch;
    int flag=0;
    int op=0;
    while((ch=fgetc(inp))!=EOF)
    {
        if(ch<65||(ch>90&&ch<97)||ch>122) // @@ [Logic error: This condition treats non-letter characters as delimiters but incorrectly increments 'op' (word index) when encountering them if flag is 0, leading to empty or invalid words being created. It also fails to properly reset state or handle word boundaries correctly compared to the reference logic.]
        {
            if(flag==1)
            {
                continue; // @@ [Logic error: When a delimiter is found after a word (flag==1), the code should finalize the current word (e.g., null-terminate it) and reset flag. Instead, it just continues, leaving the word buffer potentially unterminated or improperly handled for the next word.]
            }
            else
            {
                op++; // @@ [Logic error: Incrementing op here creates a new word entry for every non-letter character sequence at the start or between words, leading to many empty or garbage entries in the array.]
                flag++;
            }
        }
        else if(ch>=65&&ch<=90)
        {
            ch=ch+32;
            int num;
            num=strlen(w[op].s);
            w[op].s[num]=ch;
            flag=0; // @@ [Logic error: Setting flag=0 here is confusing. Flag seems to be used to track if we are inside a word, but it's set to 0 when adding letters. The logic for 'flag' is inverted or misused compared to standard parsing.]
        }
        else if(ch>=97&&ch<=122)
        {
            int num;
            num=strlen(w[op].s);
            w[op].s[num]=ch;
            flag=0; // @@ [Logic error: Same as above. The flag management is incorrect, making it hard to detect word boundaries properly.]
        }
        else
        {
            continue;
        }
    }
    
    
    
    for(int i=0;i<=op;i++)
    {
        for(int j=i+1;j<=op;j++)
        {
            int cmp=strcmp(w[i].s,w[j].s);
            if(cmp>0)
            {
                char s[100]={0};
                char ss[100]={0};
                strcpy(s,w[i].s);
                strcpy(ss,w[j].s);
                memset(w[i].s,0,sizeof(w[i].s));
                memset(w[j].s,0,sizeof(w[j].s));
                strcpy(w[j].s,s);
                strcpy(w[i].s,ss);
            }
        }
    }
    
    
    
    for(int i=0;i<=op;i++)
    {
        w[i].cs=1; // @@ [Logic error: Initializing count to 1 for all entries, including empty/invalid ones created by the parsing logic. This will lead to incorrect counts for empty strings or garbage data.]
    }
    
    
    
    for(int k=0;k<=op;k++)
    {
        if(w[k].cs==0)
        {
            continue;
        }
        else
        {
            for(int i=k+1;i<=op;i++)
            {
                if(w[i].cs!=0)
                {
                    int num=strcmp(w[k].s,w[i].s);
                    if(num==0)
                    {
                        w[k].cs++;
                        w[i].cs=0;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
    }
    
    
    
    for(int i=0;i<=op;i++)
    {
        if(w[i].cs==0)
        {
            continue;
        }
        else
        {    
            if(islower(w[i].s[0]))
            {        
            int lenth=strlen(w[i].s);
            printf("%s:%d\n",w[i].s,w[i].cs); // @@ [Format error: The output format requires a space between the word and the count (e.g., "word 1"), but this line prints a colon (e.g., "word:1").]
            }
        }
    }
    fclose(inp);
}
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
    
    
    char ch; // @@ [Error: fgetc returns int, assigning to char may cause EOF comparison to fail if char is unsigned. Should be int ch;]
    int flag=0;
    int op=0;
    while((ch=fgetc(inp))!=EOF)
    {
        if(ch<65||(ch>90&&ch<97)||ch>122)
        {
            if(flag==1)
            {
                continue;
            }
            else
            {
                op++; // @@ [Error: Increments on every non-alphabetic character when flag==0, causing empty word entries or skipping w[0]. Index should only increment when a word actually ends.]
                flag++;
            }
        }
        else if(ch>=65&&ch<=90)
        {
            ch=ch+32;
            int num;
            num=strlen(w[op].s);
            w[op].s[num]=ch;
            flag=0;
        }
        else if(ch>=97&&ch<=122)
        {
            int num;
            num=strlen(w[op].s);
            w[op].s[num]=ch;
            flag=0;
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
        w[i].cs=1;
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
            if(islower(w[i].s[0])) // @@ [Error: Unnecessary and potentially incorrect check. May skip valid words or fail on empty strings. Words are already converted to lowercase.]
            {        
            int lenth=strlen(w[i].s);
            printf("%s:%d\n",w[i].s,w[i].cs); // @@ [Error: Output format mismatch. Problem requires space separation "%s %d\n", not colon "%s:%d\n".]
            }
        }
    }
    fclose(inp);
}
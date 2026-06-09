#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s1[10000000];
typedef struct word_frequency
{
    int index;
    char s[20];
    struct word_frequency* next;
}*node;
/*int strcmp_modify(char s1[],char s2[])
{
    int n1=strlen(s1),n2=strlen(s2);
    for(int i=0;i<(n1<n2?n1:n2);i++)
    {
        if(tolower(s1[i])!=tolower(s2[i]))
        return tolower(s1[i])-tolower(s2[i]);//当前一个单词比后一个小的时候返回复数
    }
    return 0;
}*/
node p,q,head;
int main()
{
    int n,k;
    FILE *IN;
    IN=fopen("article.txt","r");
    while(fgets(s1,10000000,IN)!=NULL)
    {
        n=strlen(s1);
        for(int i=0;i<n;i++)//处理这一行读入的数据
        {
            if(isalpha(s1[i]))
            {
            p=(node)malloc(sizeof(struct word_frequency));
            p->next=NULL;
            p->index=1;
            for(k=0;isalpha(s1[i]);i++,k++)
                p->s[k]=tolower(s1[i]);//这是给节点赋予单词的操作
            p->s[k]='\0';
            if(head==NULL)
                head=p;
            else if(strcmp(head->s,p->s)>0)
            {
                p->next=head;
                head=p;
            }
            else
            {
                for(q=head;q!=NULL;q=q->next)
                {
                    if(strcmp(q->s,p->s)==0)
                    {
                        q->index++;
                        free(p);
                        break;
                    }
                    else if((q->next==NULL)||(strcmp(q->next->s,p->s)>0))
                    {
                        p->next=q->next;
                        q->next=p;
                        break;
                    }
                }//插入节点
            }
        }
            else if(s1[i]=='\n')
            break;
        }
        memset(s1,0,n);
    }
    for(q=head;q!=NULL;q=q->next)
        printf("%s %d\n",q->s,q->index);
    fclose(IN);
    return 0;
}

//
//  main.c
//  word
//
//  Created by  on 2022/3/30.
//

/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1005

typedef struct node{
    char word[MAXN];
    int cnt;
    struct node *next;//, *previous;
}node, *node_ptr;

node_ptr create(node_ptr, char[]);
node_ptr add(node_ptr *, node_ptr, char[]);
int my_strcmp(char [], char []);

int main()
{
    char s[MAXN], tmp[MAXN]; //save[MAXN][MAXN];
    int i, j, flag;
    node_ptr list=NULL, end=NULL, p, q=NULL;
    FILE *IN;
    if ((IN=fopen("article.txt", "r"))==NULL)
        return -1;
    while (fgets(s, MAXN, IN)!=NULL)
    {
        i=j=flag=0;
        while (s[i]!='\0')
        {
            if (isupper(s[i]))
                s[i]=tolower(s[i]);
            if (islower(s[i]))
            {
                tmp[j++]=s[i];//把这个词存到tmp[]这个字符串里
                flag=1;
            }
            else
            {
                if (flag)
                {
                    tmp[j]='\0';//tmp[]存好了
                    if (list==NULL)
                        list=end=create(list, tmp);
                    else
                        end=add(&list, end, tmp);
                    j=flag=0;
                    memset(tmp, '\0', MAXN);
                }
            }
            i++;
        }
    }
    p=list;
    while(p!=NULL)
    {
        printf("%s %d\n", p->word, p->cnt);
        q=p;
        p=p->next;
        free(q);
    }
    fclose(IN);
    return 0;
}

node_ptr create(node_ptr l, char tmp[])
{
    node_ptr p=(node_ptr)malloc(sizeof(node));
    strcpy(p->word,tmp);
    p->cnt=1;
    p->next=NULL;
    l=p;
    return l;
}

node_ptr add(node_ptr *start, node_ptr end, char tmp[])//把tmp按顺序加到链表中
{
    node_ptr p, pre, q=NULL;
    int flag=0;
    if (my_strcmp((*start)->word, tmp)==1)//start->word比tmp大，所以要在开头前插入一个新的含tmp的链结点
    {
        q=(node_ptr)malloc(sizeof(node));
        strcpy(q->word, tmp);
        q->cnt=1;
        q->next=*start;
        *start=q;
        return end;
    }
    else if (my_strcmp((*start)->word, tmp)==0)//start->word与tmp相同
    {
        ((*start)->cnt)++;
        return end;
    }
    //以下是start->word比tmp小的情况
    p=(*start)->next;
    pre=(*start);//pre指向p的前驱链结点
    while(p!=NULL)
    {
        if (my_strcmp(p->word, tmp)==0)
        {
            flag=2;
            break;
        }
        else if(my_strcmp(p->word, tmp)==1)//p->word比tmp大了
        {
            flag=1;
            break;
        }
        pre=p;
        p=p->next;
    }
    
    if (flag==2)//若tmp和p->word相同
    {
        p->cnt++;//优先级？？？
    }
    else if (flag==1)//要在pre和p之间插入一个新的含tmp的链结点
    {
        q=(node_ptr)malloc(sizeof(node));
        strcpy(q->word, tmp);
        q->cnt=1;
        q->next=p;
        pre->next=q;
    }
    else//flag==0，即tmp比现在链表中的所有链结点的word都大，所以要在最后加一个
    {
        q=(node_ptr)malloc(sizeof(node));
        strcpy(q->word, tmp);
        q->cnt=1;
        q->next=NULL;
        end->next=q;
        end=q;
    }
    return end;
}

int my_strcmp(char a[], char b[])
{
    if (strcmp(a, b)==0)//a与b相同
        return 0;
    else
    {
        int i;
        for (i=0; a[i]!='\0' && b[i]!='\0'; i++)
        {
            if (a[i]<b[i])//按字母顺序 a在前
                return -1;
            else if (a[i]>b[i])//按字母顺序 a在后
                return 1;
        }
        if (a[i]=='\0')//a比b短
            return -1;
        else//a比b长
            return 1;
    }
}




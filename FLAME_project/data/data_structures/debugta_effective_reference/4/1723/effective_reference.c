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
    char s[MAXN];
    int num;
    struct node *next;//, *previous;
}node, *node_ptr;

node_ptr create(node_ptr, char[]);
node_ptr add(node_ptr *, node_ptr, char[]);
int my_strcmp(char [], char []);

int main()
{
    char s[MAXN], word[MAXN]; //save[MAXN][MAXN];
    int i, j, a;
    node_ptr list=NULL, end=NULL, m, q=NULL;
    FILE *IN;
    if ((IN=fopen("article.txt", "r"))==NULL)
        return -1;
    while (fgets(s, MAXN, IN)!=NULL)
    {
        i=j=a=0;
        while (s[i]!='\0')
        {
            if (isupper(s[i]))
                s[i]=tolower(s[i]);
            if (islower(s[i]))
            {
                word[j++]=s[i];//把这个词存到tmp[]这个字符串里
                a=1;
            }
            else
            {
                if (a)
                {
                    word[j]='\0';//tmp[]存好了
                    if (list==NULL)
                        list=end=create(list, word);
                    else
                        end=add(&list, end, word);
                    j=a=0;
                    memset(word, '\0', MAXN);
                }
            }
            i++;
        }
    }
    m=list;
    while(m!=NULL)
    {
        printf("%s %d\n", m->s, m->num);
        q=m;
        m=m->next;
        free(q);
    }
    fclose(IN);
    return 0;
}

node_ptr create(node_ptr l, char word[])
{
    node_ptr m=(node_ptr)malloc(sizeof(node));
    strcpy(m->s,word);
    m->num=1;
    m->next=NULL;
    l=m;
    return l;
}

node_ptr add(node_ptr *start, node_ptr end, char word[])//把tmp按顺序加到链表中
{
    node_ptr m, base, q=NULL;
    int a=0;
    if (my_strcmp((*start)->s, word)==1)//start->word比tmp大，所以要在开头前插入一个新的含tmp的链结点
    {
        q=(node_ptr)malloc(sizeof(node));
        strcpy(q->s, word);
        q->num=1;
        q->next=*start;
        *start=q;
        return end;
    }
    else if (my_strcmp((*start)->s, word)==0)//start->word与tmp相同
    {
        ((*start)->num)++;
        return end;
    }
    //以下是start->word比tmp小的情况
    m=(*start)->next;
    base=(*start);//pre指向p的前驱链结点
    while(m!=NULL)
    {
        if (my_strcmp(m->s, word)==0)
        {
            a=2;
            break;
        }
        else if(my_strcmp(m->s, word)==1)//p->word比tmp大了
        {
            a=1;
            break;
        }
        base=m;
        m=m->next;
    }
    
    if (a==2)//若tmp和p->word相同
    {
        m->num++;//优先级？？？
    }
    else if (a==1)//要在pre和p之间插入一个新的含tmp的链结点
    {
        q=(node_ptr)malloc(sizeof(node));
        strcpy(q->s, word);
        q->num=1;
        q->next=m;
        base->next=q;
    }
    else//flag==0，即tmp比现在链表中的所有链结点的word都大，所以要在最后加一个
    {
        q=(node_ptr)malloc(sizeof(node));
        strcpy(q->s, word);
        q->num=1;
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




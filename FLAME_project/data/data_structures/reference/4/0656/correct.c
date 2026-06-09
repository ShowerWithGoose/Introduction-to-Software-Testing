#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
    char word[100];
    int fre;//词频
    struct node *next;
};

int main()
{
    char *li,*wo,*w;//读入的行的指针，读入的单词的指针，将单词转化为小写用的指针
    char wordin[100];//存储读入的单词
    char linein[10000];//存储读入的行
    FILE *in;
    struct node *p=NULL,*q=NULL,*head=NULL;
    in=fopen("article.txt","r");
    if(in==NULL)    printf("file open fail");//判断是否成功打开文件
    while(1)
    {
        if(feof(in))
        {
            break;
        }
        if(fgets(linein,10000,in)==NULL)	break;//将文本的一行录入linein
        li=linein;///以*li作为这一行的指针
        while(1)
        {
            wo=wordin;//wo为单词的指针
            while((!isalpha(*li))&&*li!='\n'&&*li!='\0')   li++;//找到第一个字母
            if(*li=='\n'||*li=='\0')   break;//到'\n'则退出
            while(isalpha(*li))     *(wo++)=*(li++);//录入单词
            *wo='\0';//单词结尾
            w=wordin;//用*w将单词转化为小写
            while(*w!='\0')
            {
                *(w)=tolower(*w);
                w++;
            }
            if(head==NULL)//如果是第一个单词
            {
                p=(struct node *)malloc(sizeof(struct node));
                strcpy(p->word,wordin);
                p->fre=1;
                p->next=NULL;
                q=p;
                head=p;
            }
            else
            {
                p=head;
                while(p!=NULL)//遍历链表
                {
                    if(strcmp(p->word,wordin)>=0)
                    {
                        if(strcmp(p->word,wordin)==0)//如果已有此单词
                        {
                            p->fre++;
                        }
                        else//wordin<p->word
                        {
                            if(p==head)//如果wordin比链表第一个单词小
                            {
                                p=(struct node *)malloc(sizeof(struct node));
                                strcpy(p->word,wordin);
                                p->fre=1;
                                p->next=head;
                                head=p;
                            }
                            else//否则插入p q之间
                            {
                                p=(struct node *)malloc(sizeof(struct node));
                                strcpy(p->word,wordin);
                                p->fre=1;
                                p->next=q->next;
                                q->next=p;
                            }
                        }
                        break;
                    }
                    q=p;
                    p=p->next;
                }
                if(p==NULL)//插入链表末尾
                {
                    p=(struct node *)malloc(sizeof(struct node));
                    strcpy(p->word,wordin);
                    p->fre=1;
                    p->next=NULL;
                    q->next=p;
                }
            }
        }
    }
    p=head;//遍历读出链表
    while(p!=NULL)
    {
        printf("%s %d\n",p->word,p->fre);
        p=p->next;
    }
    fclose(in);
    return 0;
}


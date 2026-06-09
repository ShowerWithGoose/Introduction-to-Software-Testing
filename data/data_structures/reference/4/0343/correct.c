#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct node *ptr;
struct node
{
    char word[30];
    int times;
    ptr next;
};
ptr list;

int func(char a[]);//对传入的字符串识别拆分单词并小写化,输出到templist内
int search(char a[]);//在链表中查找单词，找到则次数加一；未找到则插入到相应位置，次数置1
int insert(ptr p,char a[]);//在p后插入包含给定单词的节点，次数置为1
int pputs(char ss[]);

char s[100];
struct node templist[100];
char temp[30];

int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    int tempcnt=0;
    int i=0;
    for(i=0;i<=99;i++)
    {
        memset(templist[i].word,0,strlen(templist[i].word));
        templist[i].times=0;
    }
    while(fgets(s,99,in)!=NULL)
    {
        if(strlen(s)==0 || (s[0]=='\n'))
            continue;
        s[strlen(s)-1]='\0';
        tempcnt=func(s);
        for(i=0;i<=tempcnt-1;i++)
        {
            search(templist[i].word);
        }
        memset(s,0,strlen(s));
        for(i=0;i<=99;i++)
        {
            memset(templist[i].word,0,strlen(templist[i].word));
            templist[i].times=0;
        }
    }
    ptr p;
    for(p=list;p!=NULL;p=p->next)
    {
        pputs(p->word);
        if(p->next==NULL)
            printf(" %d",p->times);
        else
            printf(" %d\n",p->times);
    }
    system("pause");
    return 0;
}

int func(char a[])
{
    int len=strlen(a);
    int i=0,j=0;
    int cnt=0;
    memset(temp,0,strlen(temp));
    int flag=0;
    for(i=0;i<=len-1;i++)
    {
        if((a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z'))
        {
            flag=1;
            if(a[i]>='A' && a[i]<='Z')
                a[i]=a[i]-'A'+'a';
            temp[j]=a[i];
            j++;
            if(i==len-1)//若还未读到单词则不做处理
            {
                strcpy(templist[cnt].word,temp);
                templist[cnt].times++;
                cnt++;//cnt代表了当前暂时单词表内的单词数量,最后一个的单词的下标为cnt-1
                memset(temp,0,strlen(temp));
                j=0;
            }
        }
        else
        {
            if((a[i+1]>='a' && a[i+1]<='z')||(a[i+1]>='A' && a[i+1]<='Z')||(a[i+1]=='\0'))
            {
                if(flag==1)//若还未读到单词则不做处理
                {
                    strcpy(templist[cnt].word,temp);
                    templist[cnt].times++;
                    cnt++;//cnt代表了当前暂时单词表内的单词数量,最后一个的单词的下标为cnt-1
                    memset(temp,0,strlen(temp));
                    j=0;
                }
            }
        }
    }
    return cnt;
}

int search(char a[])
{
    ptr p=list,q=NULL;
    for(p=list;p!=NULL;q=p,p=p->next)
    {
        if(strcmp(a,p->word)<0)
            break;
        else if(strcmp(a,p->word)==0)
        {
            p->times++;
            return 0;
        }
    }
    return insert(q,a);
}

int insert(ptr p,char a[])
{
    ptr q=malloc(sizeof(struct node));
    q->times=1;
    memset(q->word,0,sizeof(q->word));
    strcpy(q->word,a);
    q->next=NULL;
    if(list==NULL)
    {
        list=q;
    }
    else if(p==NULL)
    {
        q->next=list;
        list=q;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    }
    else
    {
        q->next=p->next;
        p->next=q;
    }
    return 0;
}

int pputs(char ss[])
{
    int i=0;
    int len=strlen(ss);
    for(i=0;i<=len-1;i++)
    {
        if(ss[i]>='a' && ss[i]<='z')
            printf("%c",ss[i]);
    }
    return 0;
}

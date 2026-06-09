#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct link
{
    int times;
    char word[70];
    struct link*nestdot;
}*count;
count first,p;
char Tolower(char c)
{
    if(c>='A'&&c<='Z')return c+32;
    else return c;
}
int scan(char *s)
{
    int si=1,sign=0,i=0,flag=0;
    while(1)
    {
        flag=scanf("%c",&s[i]);
        if(flag==-1)
        {
            s[i]='\0';
            if(si==1)return 0;
            else return 1;
        }    
        s[i]=Tolower(s[i]);
        if((s[i]<'a'||s[i]>'z')&&sign==1)
        {
            si=1;
            s[i]='\0';
            return flag;
        }
        else if (s[i]>='a'&&s[i]<='z')
        {
            si=0;
            sign=1;
        }
        else
        {
            i--;
        }
        i++;
    }
}
int check(char s[],count p)
{
    count q=first;
    while(q!=p)
    {
        if(strcmp(q->word,s)==0)
        {
            q->times++;
            return 1;
        }
        q=q->nestdot;
    }
    return 0;
}
void make_link()
{
    first=(struct link*)malloc(sizeof(struct link));
    first->nestdot=NULL;
    p=first;
    count q=p;
    p->times=1;
    while(1)
    {
        if(scan(p->word))
        {
            if(!check(p->word,p))
            {
                q=p;
                p=p->nestdot=(struct link*)malloc(sizeof(struct link));
                p->times=1;
            }
        }
        else
        {
            q->nestdot=NULL; 
            break;
        }
    }
    if(first->word[0]==0)
        first=NULL;
}
void permu()
{
    p=first;
    char temp[50];
    while(p!=NULL)
    {
        count q=p->nestdot;
        while(q!=NULL)
        {
            if(strcmp(p->word,q->word)==1) // @@ [Using ==1 for strcmp is incorrect; strcmp returns >0 when first string is lexicographically greater, not necessarily 1. This causes incomplete sorting.]
            {
                strcpy(temp,p->word);
                strcpy(p->word,q->word);
                strcpy(q->word,temp);
                p->times=p->times^q->times;
                q->times=p->times^q->times;
                p->times=p->times^q->times;
            }
            q=q->nestdot;
        }
        p=p->nestdot;
    }
}
void prn()
{
    p=first;
    while(p!=NULL)
    {
        printf("%s %d\n",p->word,p->times);
        p=p->nestdot;
    }
}
int main()
{
    freopen("article.txt","r",stdin);
    make_link();
    permu();
    prn();
    fclose(stdin);
}
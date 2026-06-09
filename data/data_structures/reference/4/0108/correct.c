#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct phrase
{
    char word[20];
    int times;
    struct phrase *link;
}word,*word_point;
int getin(char str[])
{
    int i=0;
    char ch=',';
    while(!isalpha(ch))
    {
        if((ch=getchar())==EOF)
            return 1;
    }  
    while(isalpha(ch))
    {
        if(isupper(ch))
            str[i++]=ch+32;
        else str[i++]=ch;
        if((ch=getchar())==EOF)
            return 1;
    }  
    str[i]='\0';
    return 0;
}
int main(void)
{
    freopen("article.txt","r",stdin);
    word_point current=NULL;
    word_point list=NULL;
    word_point tool=NULL;
    while(1)
    {
        current=(word_point)malloc(sizeof(word));
        if(getin(current->word))
            break;
        current->times=1;
        current->link=NULL;
        if(list==NULL)
            list=current;
        else
        {
            tool=list;
            while(1)
            {
                if(strcmp(current->word,list->word)<0)
                {
                    current->link=list;
                    list=current;
                    break;
                }
                else if(strcmp(current->word,tool->word)>0&&tool->link==NULL)
                {
                    tool->link=current;
                    break;
                }
                else if(strcmp(current->word,tool->word)==0)
                {
                    tool->times++;
                    break;
                }
                else if(strcmp(current->word,tool->word)>0&&strcmp(current->word,tool->link->word)<0)
                {
                    current->link=tool->link;
                    tool->link=current;
                    break;
                }
                else tool=tool->link;
            }
        }
    }
    while(list!=NULL)
    {
        printf("%s %d\n",list->word,list->times);
        list=list->link;
    }
}

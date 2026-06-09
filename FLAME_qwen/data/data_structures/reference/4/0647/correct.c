#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXLINE 1024
char FILEIN[MAXLINE]; 
FILE *in;
/*scanf("%d",&a)、scanf("%s",&a)等不能接受空格、Tab、回车等。
对于末位回车符，会把其保存在输入缓冲区，
保存在输入缓冲区中的末位回车符能否为下次scanf（）所接收。
要视scanf()中输入类型决定。仅字符型变量scanf("%c",&a)可以接收回车。*/
struct ENGLISH
{
    char word[30];
    int num;
}english;
struct ENGLISH head[10000];

int input(char *str)
{
    int i=0;
    char c;
    while(1)
    {
        c = fgetc(in);
        if(c == EOF) 
            return 0;
        if(isalpha(c))
            break;
    }
    do{
        c= tolower(c);
        str[i++] = c;
    }while(isalpha(c=fgetc(in)));
    str[i] = '\0';
    return 1;
}

int cmp(const void *a, const void *b)
{
    struct ENGLISH c = *(struct ENGLISH *) a;
    struct ENGLISH d = *(struct ENGLISH *) b;
    if(strcmp(c.word,d.word)>0)
    return 1;
    else
    return -1;
}

int main()
{
    char str[30];
    int i=0;
    in = fopen("article.txt","r");
    while(input(str))
    {
        int flag = 1;
        for(int k=0;k<i;k++)
        {
            if(!strcmp(str,head[k].word))
            {
                head[k].num++;
                flag = 0;
            }
        }
        if(flag)
        {
            strcpy(head[i].word,str);
            head[i].num++;
            i++;
            memset(str,0,sizeof(str));
        }
    }
    qsort(head,i,sizeof(head[0]),cmp);
    for(int k=0;k<i;k++)
    {
        printf("%s %d\n",head[k].word,head[k].num);
    }
}

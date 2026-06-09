#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct article
{
    char word[51];    //可能错 这里的word要赋予空间吗->要！我嘞个去！所以要写成数组而非指针的形式(要不然好像会栈溢出）
    int counts;
    struct article *next;
}arti;

arti *initarti(FILE *in);
char *my_strlwr(char *s);

int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    //问题：边输入边排序，还是输入完成后再排序？
    arti *head=initarti(in),*p=head->next;

    while(p!=NULL)
    {
        printf("%s %d\n",p->word,p->counts);
        p=p->next;
    }

    fclose(in);
    return 0;
}

arti *initarti(FILE *in)
{
    arti *head=(arti *)malloc(sizeof(arti)),*pr=head;
    arti *a=(arti *)malloc(sizeof(arti));
    char c,*p=(char *)malloc(51);
    pr->next=a;a->next=NULL;

    memset(p,'\0',51);
    while(!isalpha(c=fgetc(in)));
    c=tolower(c);
    strncat(p,&c,1);
    while(isalpha(c=fgetc(in)) && my_strlwr(&c))
        strncat(p,&c,1);

    strcpy(a->word,p);a->counts=1;   //差点错 这里的字符串赋值不能用地址取等！因为wordin地址存储内容一直在变！所以只能用strcpy()
    //printf("%s %d\n",a->word,a->counts);

    memset(p,'\0',51);
    while(!isalpha(c=fgetc(in)));
    c=tolower(c);
    //曾错 循环的误用：当不符合循环条件时，虽然跳出循环，但while的（）里的语句已经“多”执行了一遍！因此操作实际上会比认为的往后一步
    strncat(p,&c,1);   //若直接用strcat，p会接收错误！毕竟c只是字符，它的存储区后面可能有其他数据
    while(isalpha(c=fgetc(in)) && my_strlwr(&c))
        strncat(p,&c,1);

    while(*p!='\0')//第一重循环用于判断输入是否结束
    {
        while(pr->next!=NULL)//第二重循环用于处理每一个找到的单词
        {
            int wordcmp=strcmp(p,pr->next->word);
            //printf("(%d)\n",wordcmp);
            //这里大小判断的顺序是细节
            if(wordcmp>0)   //易错 注意从头到尾都满足该初识判断条件的情况！
                pr=pr->next;
            else if(wordcmp==0)
            {
                pr->next->counts+=1;break;
            }
            else if(wordcmp<0)
            {
                arti *a=(arti *)malloc(sizeof(arti));
                a->next=pr->next;pr->next=a;//插入
                strcpy(a->word,p);
                a->counts=1;
                break;   //我怎么又忘了break！！！？？？循环内每次if判断结束后，注意执行语句内是否需要break出循环。即循环进程是否在此告一段落
            }
        }
        if(pr->next==NULL)
        {
            arti *a=(arti *)malloc(sizeof(arti));
            pr->next=a;
            strcpy(a->word,p);
            a->counts=1;a->next=NULL;
        }
        //printf("%s %d\n",pr->next->word,pr->next->counts);
        pr=head;
        memset(p,'\0',51);
        while((c=fgetc(in))!=EOF && !isalpha(c));   //曾错 无法跳出文末循环（即!isalpha(c)无法应对文末的情况）若去掉(c=fgetc(in))!=EOF，会陷入无限循环
        //printf("-1\n");
        if(c==EOF) break;   //曾错 加上这个，否则读入p后又会无限循环，因为好像c!='\0'
        c=tolower(c);
        strncat(p,&c,1);
        while(isalpha(c=fgetc(in)) && my_strlwr(&c) && *p!='\0')
            strncat(p,&c,1);
        //printf("-1\n");
    }

    return head;
}

char *my_strlwr(char *s)
{
     char *str=s;
     while(*str != '\0')
     {
        if(*str >= 'A' && *str <= 'Z') *str += 'a'-'A';
        str++;
     }
     return s;
 }


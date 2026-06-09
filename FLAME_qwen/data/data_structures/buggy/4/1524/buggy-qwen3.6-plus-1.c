#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct wenzhang{//文章 
    char dc[30];//单词
    int cs;//次数
}dcb;
int cmp(const void *p1,const void *p2)
{
    struct wenzhang *a=(struct wenzhang *)p1;
    struct wenzhang *b=(struct wenzhang *)p2;
    return strcmp(a->dc,b->dc);
}
int main()
{
    int i,j,k;
    int flag=0;
    char a; // @@ fgetc returns int, using char may fail to detect EOF correctly if char is unsigned. Should be int a;
    char map[100]={0};
    dcb infor[10000];
    int dcb_len=0; //单词表的长度 
    FILE *fp1=fopen("article.txt","r");
    if(fp1==NULL)
    {
        printf("can you find this file?"); // @@ Program continues execution after file open failure, causing crash on fgetc. Should return or exit.
    }else
    {
        i=0;
        while((a=fgetc(fp1))!=EOF)//存放单词 
        {
            if(isupper(a)==1) // @@ isupper returns non-zero, not necessarily 1. Comparing to 1 is logically incorrect. Use if(isupper(a))
            {
                map[i]=tolower(a);
                i++;
            }else if(islower(a)==1) // @@ islower returns non-zero, not necessarily 1. Comparing to 1 is logically incorrect. Use else if(islower(a))
            {
                map[i]=a;
                i++;
            }else//已经读完了 
            {
                if(strcmp(map,"\0")!=0)//map单词不为空  // @@ map is not null-terminated before strcmp, leading to undefined behavior. Need map[i] = '\0'; before this check.
                {
                    flag=0;
                    for(j=0;j<dcb_len;j++)
                    {
                        if(strcmp(map,infor[j].dc)==0)
                        {
                            flag=1;//找到了
                            infor[j].cs++;
                            break; 
                        }else
                        {
                            flag=0;
                        }
                    }
                        if(flag==0)
                    {
                        strcpy(infor[dcb_len].dc,map);//找不到于是放入新单词 
                        infor[dcb_len].dc[i]='\0'; // @@ i may exceed dc array size (30), causing buffer overflow. strcpy already null-terminates, making this redundant and unsafe.
                        infor[dcb_len].cs=1;
                        dcb_len++;//单词表长度增加了 
                    }
                    for(k=0;k<100;k++)
                    {
                        map[k]='\0';
                    }
                }
                    i=0;
            }
        }
        qsort(infor,dcb_len,sizeof(dcb),cmp); //快排
        for(i=0;i<dcb_len;i++)
        {
            printf("%s %d\n",infor[i].dc,infor[i].cs);
        }
        fclose(fp1);
    }
    return 0;
}
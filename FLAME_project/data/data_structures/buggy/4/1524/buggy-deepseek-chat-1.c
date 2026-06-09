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
    char a;
    char map[100]={0};
    dcb infor[10000];
    int dcb_len=0; //单词表的长度 
    FILE *fp1=fopen("article.txt","r");
    if(fp1==NULL)
    {
        printf("can you find this file?");
    }else
    {
        i=0;
        while((a=fgetc(fp1))!=EOF)//存放单词 
        {
            if(isupper(a)==1) // @@ [isupper returns non-zero (not necessarily 1) for uppercase letters; should check >0 instead of ==1]
            {
                map[i]=tolower(a);
                i++;
            }else if(islower(a)==1) // @@ [islower returns non-zero (not necessarily 1) for lowercase letters; should check >0 instead of ==1]
            {
                map[i]=a;
                i++;
            }else//已经读完了 
            {
                if(strcmp(map,"\0")!=0)//map单词不为空 
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
                        infor[dcb_len].dc[i]='\0'; // @@ [i is 0 at this point (reset after the else block), so this sets the first character to '\0', corrupting the word; should not be here]
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
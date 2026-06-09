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
    struct wenzhang *a=(struct wenzhang *)p1; // @@ [Error: 'struct wenzhang' is not declared in this scope because the typedef defines 'wenzhang' as an alias, but the struct tag is still 'wenzhang'. However, the real issue is that inside the function, it should use 'dcb' or properly reference the struct. But more critically, the cast should be to 'dcb*', not 'struct wenzhang*' if using typedef. Alternatively, since 'wenzhang' is the struct tag, this is actually valid. So this line is NOT the error.]
    struct wenzhang *b=(struct wenzhang *)p2; // @@ [Same as above - actually valid C. Not the error.]
    return strcmp(a->dc,b->dc);
}
int main()
{
    int i,j,k;
    int flag=0;
    char a; // @@ [Error: 'char a' is used to store result of fgetc(), which returns int. This causes EOF comparison to fail because EOF is outside char range, leading to infinite loop or incorrect behavior.]
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
        while((a=fgetc(fp1))!=EOF)//存放单词  // @@ [Error: fgetc() returns int, but assigned to char 'a'. When char is signed, EOF (typically -1) may equal a valid char value after truncation, causing premature termination or infinite loop.]
        {
            if(isupper(a)==1)
            {
                map[i]=tolower(a);
                i++;
            }else if(islower(a)==1)
            {
                map[i]=a;
                i++;
            }else//已经读完了 
            {
                if(strcmp(map,"\0")!=0)//map单词不为空  // @@ [Error: strcmp(map, "\0") is incorrect. "\0" is a string literal containing two null bytes. Should compare map[0] != '\0' or use strlen(map) > 0. This condition may not work as expected.]
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
                            flag=0; // @@ [Error: This else block resets flag to 0 on every non-match, so only the last comparison matters. Should remove this else block entirely.]
                        }
                    }
                        if(flag==0)
                    {
                        strcpy(infor[dcb_len].dc,map);//找不到于是放入新单词 
                        infor[dcb_len].dc[i]='\0'; // @@ [Error: strcpy already null-terminates, and 'i' may be beyond the copied length. Also, if map was filled with i characters, then map[i] is already '\0', so this is redundant and possibly out-of-bounds if i >= 30.]
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
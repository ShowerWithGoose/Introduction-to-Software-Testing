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
            if(isupper(a)==1) @@ [Error: isupper() returns non-zero for true, not necessarily 1. Should use if(isupper(a))]
            {
                map[i]=tolower(a);
                i++;
            }else if(islower(a)==1) @@ [Error: islower() returns non-zero for true, not necessarily 1. Should use else if(islower(a))]
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
                        infor[dcb_len].dc[i]='\0'; @@ [Error: This line incorrectly truncates the string at index i. Since strcpy already copied the full null-terminated string from map, this overwrites a valid character with '\0' if i < length of word, or accesses out of bounds if i >= length. It should be removed or corrected. However, since map is null-terminated and strcpy copies until null, the string in dc is already correct. Setting dc[i] to '\0' is dangerous because 'i' is the global index counter, not the length of the current word. For example, if the first word is "I" (length 1), i becomes 1. strcpy copies "I\0". Then dc[1] is set to '\0', which is fine. But if the next word is "will", i resets to 0, then increments to 4. strcpy copies "will\0". Then dc[4] is set to '\0'. This seems okay logically IF i represents the length of the current word being processed. BUT, look at the logic: i is incremented inside the if/else blocks. When a non-letter is hit, i holds the length of the word just built. So strcpy copies map (which has the word) to dc. Then dc[i] = '\0' ensures termination. Wait, strcpy already terminates. The real issue is that map might not be properly terminated if the buffer was reused? No, map is cleared later. The actual bug causing Wrong Answer is likely related to how `isupper`/`islower` checks are done with `==1`. On many systems, these macros return values other than 1. This causes letters to be skipped, leading to missing words or incorrect parsing.]
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
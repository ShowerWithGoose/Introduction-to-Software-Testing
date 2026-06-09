#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct words{
    char s[105];
    int fre;
}word[1005];

int test(char*,int );
char now[105];
int type(char);
int max;
char c; // @@ fgetc returns int, and EOF is an int value. Using char can lead to incorrect EOF detection.
int cmp(const void*,const void*);
int main()
{max=0;
int *p=&max;int i; // @@ Variable i is uninitialized before being used as an index in now[i++], causing undefined behavior.
    FILE* in;
    strcpy(now,"");
    in=fopen("article.txt","r");
    c=fgetc(in);
    while(c!=EOF)
    {

        if(type(c))
        {
            now[i++]=tolower(c);//只要是字母就存
            //printf("input %c ",c);
        }
        else
        {
        if(i!=0)
        {now[i]='\0';
        max=test(now,max);//printf("\nnow is %s\n",now);
    

        }//遇到非字母，停止阅读，s清零
         i=0;
        }
        c=fgetc(in);
    }
    if(i!=0)
    {
        max=test(now,max);
    }
    
    
    qsort(word,max,sizeof(word[0]),cmp);
    for(int k=0;k<max;k++)
    {
        printf("%s %d\n",word[k].s,word[k].fre);
    }
    return 0;
    fclose(in); // @@ Unreachable code placed after 'return 0;'.
}

int type(char c)
{
    if(c>='a'&&c<='z'||c>='A'&&c<='Z')
    return 1;
    
    else
    return 0;
}


int  test(char *now,int max)
{
    for(int j=0;j<max;j++)//max即已有单词的个数（去重后），遍历找出当前单词是否有重复
    {
        if(strcmp(word[j].s,now)==0)
        {
            word[j].fre++;//发现重复，直接该词频++
            return max;
        }
    }
    //新建一个单词和词频的结构体变量
    
    strcpy(word[max].s,now);
    word[max].fre=1;
    max++;
    return max;
}
int cmp(const void*a,const void*b)
{

    return strcmp(((words*)a)->s,((words*)b)->s); // @@ 'words' is a struct tag, not a type name. Must use 'struct words' in C, causing compilation error.
}
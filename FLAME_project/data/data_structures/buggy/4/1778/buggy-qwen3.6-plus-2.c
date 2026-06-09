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
char c;
int cmp(const void*,const void*);
int main()
{max=0;
int *p=&max;int i; // @@ Variable 'i' is used uninitialized. It should be initialized to 0 (e.g., int i = 0;) before being used in 'now[i++]'.
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
    fclose(in);
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

    return strcmp(((words*)a)->s,((words*)b)->s); // @@ The struct tag is 'words', but in C, when casting, one must use 'struct words'. It should be ((struct words*)a)->s.
}
/*
1，读入单词：getchar直到遇到c不是字母，就说明一个单词读完了
2，判断单词是否出现过，出现过就词频++
3，如果是新单词，为新单词创建一个结构体：单词、词频
3，qsort对单词排序，但是cmp函数比较的是字典序
*/
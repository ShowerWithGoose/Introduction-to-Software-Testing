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
int *p=&max;int i; // @@ [i未初始化，后续使用i作为数组下标会导致未定义行为，应在声明时初始化为0]
    FILE* in;
    strcpy(now,"");
    in=fopen("article.txt","r");
    c=fgetc(in);
    while(c!=EOF)
    {

        if(type(c))
        {
            now[i++]=tolower(c);//只要是字母就存 // @@ [i未初始化，此时i为随机值，导致数组访问越界]
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
    return 0; // @@ [return语句之后的fclose(in)不会执行，导致文件未关闭，造成资源泄漏]
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

    return strcmp(((words*)a)->s,((words*)b)->s); // @@ [类型转换错误：words不是类型名，应改为(struct words*)a]
}
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    char word[105];
    int time;
}words;
words word[1005],temp;

//判断是否是字母
int judge(char s)
{
    if('a'<=s&&'z'>=s) return 1;
    else if('A'<=s&&'Z'>=s) return 2;
    else return 0;
}

//把大写字母转成小写
char change(char s)
{
    if('A'<=s&&'Z'>=s) return 'a'+s-'A';
    else return s;
}

int main()
{
    //读入词汇表,并构建或插入相应项
    FILE*in;
    in=fopen("article.txt","r");
    char c,s[105];
    int sum=0,i,j,n,flag;
    c=fgetc(in);
    while(c!=EOF)
    {
        n=0;
        flag=0;

        //把非字母字符清掉
        while(judge(c)==0)
        {
            c=fgetc(in);
            if(c==EOF) break;
        }
        //读入单词
        while(judge(c)!=0)
        {
            s[n++]=change(c);
            c=fgetc(in);
        }
        s[n]='\0';
        if(n==0) continue;
        //插入
        for(i=0;i<sum;i++)
        {
            //s应该放最前面
            if(sum>0&&strcmp(s,word[0].word)<0)
            {
                for(j=sum-1;j>=0;j--)
                {
                    word[j+1]=word[j];
                }
                strcpy(word[0].word,s);
                word[0].time=1;
                flag=1;
                sum++;
                break;
            }
            //已有s的词
            else if(strcmp(s,word[i].word)==0)
            {
                word[i].time++;
                flag=1;
                break;
            }
            //没有s的词，但可插入到两词之间
            else if(strcmp(s,word[i].word)>0&&i+1<sum&&strcmp(s,word[i+1].word)<0)
            {
                for(j=sum-1;j>i;j--)
                {
                    word[j+1]=word[j];
                }
                strcpy(word[i+1].word,s);
                word[i+1].time=1;
                flag=1;
                sum++;
                break;
            }
        }
        //上述都不符合，把s加最后
        if(flag==0)
        {
            strcpy(word[sum].word,s);
            word[sum++].time=1;
        }
        
    }

    //打印
    for(i=0;i<sum;i++)
    {
        printf("%s %d\n",word[i].word,word[i].time);
    }


}



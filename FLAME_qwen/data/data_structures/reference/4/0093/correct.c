#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    char word[105];
    int time;
}words;
words wordlist[1005],temp;

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
    char ch,s[105];
    int sum=0,i,j,num,flag;
    ch=fgetc(in);
    while(ch!=EOF)
    {
        num=0;
        flag=0;

        //把非字母字符清掉
        while(judge(ch)==0)
        {
            ch=fgetc(in);
            if(ch==EOF) break;
        }
        //读入单词
        while(judge(ch)!=0)
        {
            s[num++]=change(ch);
            ch=fgetc(in);
        }
        s[num]='\0';
        if(num==0) continue;
        //插入
        for(i=0;i<sum;i++)
        {
            //s应该放最前面
            if(sum>0&&strcmp(s,wordlist[0].word)<0)
            {
                for(j=sum-1;j>=0;j--)
                {
                    wordlist[j+1]=wordlist[j];
                }
                strcpy(wordlist[0].word,s);
                wordlist[0].time=1;
                flag=1;
                sum++;
                break;
            }
            //已有s的词
            else if(strcmp(s,wordlist[i].word)==0)
            {
                wordlist[i].time++;
                flag=1;
                break;
            }
            //没有s的词，但可插入到两词之间
            else if(strcmp(s,wordlist[i].word)>0&&i+1<sum&&strcmp(s,wordlist[i+1].word)<0)
            {
                for(j=sum-1;j>i;j--)
                {
                    wordlist[j+1]=wordlist[j];
                }
                strcpy(wordlist[i+1].word,s);
                wordlist[i+1].time=1;
                flag=1;
                sum++;
                break;
            }
        }
        //上述都不符合，把s加最后
        if(flag==0)
        {
            strcpy(wordlist[sum].word,s);
            wordlist[sum++].time=1;
        }
        
    }

    //打印
    for(i=0;i<sum;i++)
    {
        printf("%s %d\n",wordlist[i].word,wordlist[i].time);
    }


}



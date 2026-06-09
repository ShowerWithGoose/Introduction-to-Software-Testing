#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    char word[105];
    int time;
}words;
words wordlist[1005],temp;

//判断是否是字母
int judge(char word)
{
    if('a'<=word&&'z'>=word) return 1;
    else if('A'<=word&&'Z'>=word) return 2;
    else return 0;
}

//把大写字母转成小写
char change(char word)
{
    if('A'<=word&&'Z'>=word) return 'a'+word-'A';
    else return word;
}

int main()
{
    //读入词汇表,并构建或插入相应项
    FILE*in;
    in=fopen("article.txt","r");
    char strin,word[105];
    int num=0,i,j,len,sign;
    strin=fgetc(in);
    while(strin!=EOF)
    {
        len=0;
        sign=0;

        //把非字母字符清掉
        while(judge(strin)==0)
        {
            strin=fgetc(in);
            if(strin==EOF) break;
        }
        //读入单词
        while(judge(strin)!=0)
        {
            word[len++]=change(strin);
            strin=fgetc(in);
        }
        word[len]='\0';
        if(len==0) continue;
        //插入
        for(i=0;i<num;i++)
        {
            //s应该放最前面
            if(num>0&&strcmp(word,wordlist[0].word)<0)
            {
                for(j=num-1;j>=0;j--)
                {
                    wordlist[j+1]=wordlist[j];
                }
                strcpy(wordlist[0].word,word);
                wordlist[0].time=1;
                sign=1;
                num++;
                break;
            }
            //已有s的词
            else if(strcmp(word,wordlist[i].word)==0)
            {
                wordlist[i].time++;
                sign=1;
                break;
            }
            //没有s的词，但可插入到两词之间
            else if(strcmp(word,wordlist[i].word)>0&&i+1<num&&strcmp(word,wordlist[i+1].word)<0)
            {
                for(j=num-1;j>i;j--)
                {
                    wordlist[j+1]=wordlist[j];
                }
                strcpy(wordlist[i+1].word,word);
                wordlist[i+1].time=1;
                sign=1;
                num++;
                break;
            }
        }
        //上述都不符合，把s加最后
        if(sign==0)
        {
            strcpy(wordlist[num].word,word);
            wordlist[num++].time=1;
        }
        
    }

    //打印
    for(i=0;i<num;i++)
    {
        printf("%s %d\n",wordlist[i].word,wordlist[i].time);
    }


}



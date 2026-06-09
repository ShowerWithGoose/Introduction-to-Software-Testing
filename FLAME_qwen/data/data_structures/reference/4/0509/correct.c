#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>
#define MAXWORD  32
#define MAXSIZE  1024
struct lnode
{
    char word[MAXWORD];
    int count;
};
int getWord(FILE *bfp,char *w);
int searchWord(struct lnode list[], char *w);
int insertWord(struct lnode list[], int pos, char *w);
int N=0;
int main()
{
    struct lnode wordlist[MAXSIZE];	/*单词表*/
    int i;
    char word[MAXWORD];
    FILE *bfp;
    bfp=fopen("article.txt","r");
    while(getWord(bfp,word) != EOF) //从文件中读词并判断
        if(searchWord(wordlist, word) == -1)  //查找单词表并作词频处理
        {
            fprintf(stderr, "Wordlist is full!\n");
            fclose(bfp);//上传ppt缺该语句，没关闭文件
            return -1;
        }
    for(i=0; i<= N-1; i++) //打印词频
        printf("%s %d\n", wordlist[i].word, wordlist[i].count);
    fclose(bfp);//上传ppt缺该语句，没关闭文件
    return 0;
}
int getWord(FILE *fp, char *w)
{
    int c;
    while(!isalpha(c=fgetc(fp)))//读掉前面若干非字母的符号
    {
        if(c == EOF)
            return c;
        else
            continue;
    }
    do
    {
        *w++ = tolower(c); //转化为小写字母
    }
    while(isalpha(c=fgetc(fp)));
    *w='\0'; //字符数组最后的’\0’
    return 1;
}
int insertWord(struct lnode list[],int pos,char *w)
{
    int i;
//判断表是否满了，是的话，返回-1
    if  (N == MAXSIZE)
        return -1;
//移动插入位置后的元素
    for(i=N-1; i>=pos; i--)
    {
        strcpy(list[i+1].word, list[i].word);
        list[i+1].count = list[i].count;
    }
    strcpy(list[pos].word, w); //插入
    list[pos].count = 1;
    N++; //表长+1
    return 1;
}
int searchWord(struct lnode list[ ], char *w)
{
    //用折半查找法来查找
    int low=0, high=N-1, mid=0;
    while(low <= high)
    {
        mid = (high + low) / 2;
        if(strcmp( w, list[mid].word)<0) //比较单词
            high = mid -1; //当前比mid处词小
        else if(strcmp( w, list[mid].word)>0)
            low = mid + 1; //当前比mid处词大
        else  //在词频表中找到了当前词
        {
            list[mid].count++;
            return 0;
        }
    }
    return insertWord(list, low, w); //词频表中没找到，插入当前词，并返回1；如果表满，返回-1
}


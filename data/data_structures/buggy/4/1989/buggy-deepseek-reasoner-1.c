#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 100100
#define N 10000

struct ti
{
    char chWord[50];
    int cntWord;
};
struct ti word[MAX];

int  cmp ( const void *a, const void *b){
    struct ti *p=( struct ti*)a, *q=(struct ti *)b;
    return strcmp(p->chWord,q->chWord);//p比q大就换
}

int main ()
{
    FILE *in,*out,*p;
    in = fopen("article.txt", "r");
    out = fopen("output.txt", "w");
    if ( in == NULL ) {
        puts("Fail to open file!");
        exit(0);
    }
    int c;
    while( (c=fgetc(in))!= EOF ) {
        if( isalpha(c) )
            fputc(tolower(c), out);
        else if(isspace(c)){
            fputc('\n', out);
        }
        /*
        else if(c=='\''){
            fputc('\n', out);
            fputc('a', out);
        }
        */
        else if( isprint(c)&&c!='.'&&c!=';'&&c!=','&&c!='\"' )  // @@ 逻辑错误：非字母字符应输出换行符作为单词分隔，而不是原样输出，否则会破坏单词纯字母性
            fputc(c,out);
    }
    fputc('\n', out);//以上out文件里每行一个单词
    char str[N+1];
    int cnt=0;
    fclose(in);
    fclose(out);
    p = fopen("output.txt", "r");//【注意，指针要移到开头，否则无法读到内容
    if ( p == NULL ) {
        puts("Fail to open file!");
        exit(0);
    }
    while( fgets(str, N, p) != NULL ) {
        if(str[0]=='\n'||str[0]==' ')    continue;
        int flag=0,i=0;
        int num=0;
        int len=strlen(str);
        for(int j=0;j<len-1;j++){
            if( !isalpha(str[j]) )  {
                num=1;
                break;
            }
        }
        if(num==1)    continue;
        
        str[len-1]='\0'; // @@ 错误：无条件删除最后一个字符，若该行末尾没有换行符（如文件结尾），会误删最后一个字母，导致单词被截断
        for(i=0; i<cnt;i++){
            if(strcmp(str,word[i].chWord)==0){
                flag=1;
                break;
            }
        }
        if(flag==0){//新的单词存
            strcpy(word[cnt].chWord,str);
            word[cnt].cntWord=1;
            cnt++;
        }else {//出现过的
            word[i].cntWord++;
        }
    }
    qsort ( word, cnt , sizeof( struct ti ), cmp );
    for(int i=0; i<cnt; i++){
        printf("%s %d\n",word[i].chWord,word[i].cntWord);
    }
    fclose(p);
    return 0;
}

/*
【问题描述】

编写程序统计一个英文文本文件中每个单词的出现次数（词频统计），并将统计结果按单词字典序输出到屏幕上。

注：在此单词为仅由字母组成的字符序列。包含大写字母的单词应将大写字母转换为小写字母后统计。

思路：
先把文件里的大写字母转成小写
一个单词一个单词读取，

单词必须是纯纯的字母，不能夹杂数字

struct word cnt
按字典序排序
输出word 和 cnt
*/
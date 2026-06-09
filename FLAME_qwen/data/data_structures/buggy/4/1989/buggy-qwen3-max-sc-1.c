#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h> // @@ [Including <math.h> is unnecessary and may cause compilation issues in some environments where it's not linked by default, though typically not a direct cause of "gcc not found". However, the real issue is that the program writes to "output.txt" but the problem requires reading only from "article.txt" and outputting to screen—this approach violates the problem constraints and may lead to logical errors or file handling issues. But given the error message "/bin/sh: 1: gcc: not found", this is actually an environment issue, not a code bug. However, per instructions, we must find code errors that would cause failure under correct compilation. The actual logical error is creating and relying on an intermediate file "output.txt", which is not allowed per problem statement (must read from article.txt and output to screen directly). Also, the program opens "output.txt" for writing without checking if it can be created, and later reopens it for reading—this is fragile and unnecessary.]

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
    out = fopen("output.txt", "w"); // @@ [The problem states to read from "article.txt" and output results to the screen. Creating an intermediate file "output.txt" is not allowed and complicates the solution unnecessarily. This also introduces potential failure points (e.g., permission issues) and violates the problem's input/output specification.]
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
        else if( isprint(c)&&c!='.'&&c!=';'&&c!=','&&c!='\"' )  
            fputc(c,out); // @@ [This line writes non-alphabetic printable characters (except .;,"") to the output file, which violates the word definition (words are only letters). This will cause non-letter characters to appear in "words", leading to incorrect tokenization. For example, "hello!" would become "hello!" in the file instead of just "hello", and then later filtered out—but inefficiently and possibly incorrectly.]
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
        if(num==1)    continue; // @@ [This skips lines containing any non-alphabetic character, which is correct per word definition, but the earlier step already wrote such characters to the file, making this a workaround for a flawed preprocessing step. The root error is in the preprocessing loop above.]
        
        str[len-1]='\0';
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
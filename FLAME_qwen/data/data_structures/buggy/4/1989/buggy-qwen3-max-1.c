#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h> // @@ [Unnecessary header inclusion; while not causing compilation error by itself, it's irrelevant. However, the real compilation error is likely due to missing linking or environment issue, but based on code logic and problem constraints, the actual bug is below.]
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
    out = fopen("output.txt", "w"); // @@ [The program writes to "output.txt", but the problem requires reading only from "article.txt" and outputting to screen. This intermediate file approach is unnecessary and may cause issues if file creation fails, but more critically:]
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
            fputc(c,out); // @@ [This line writes non-alphabetic printable characters (like digits, symbols) to output.txt, which violates the problem's definition that a word consists ONLY of letters. This causes invalid "words" to be written, leading to incorrect filtering later. However, the immediate cause of potential runtime/logic error is not compilation. But note: the compilation error reported ("gcc: not found") is environmental, not code-related. Since the instruction says to find errors in the program based on failed test cases and expected behavior, we focus on logical bugs that would cause wrong output. Yet the prompt says "Compilation Error", which contradicts the given output "/bin/sh: 1: gcc: not found" — that's a system error, not code error. However, assuming the real issue is logical and the "Compilation Error" label is misleading, we proceed to find logical flaws that would cause wrong output.]

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
        
        str[len-1]='\0'; // @@ [This assumes the last character is always '\n', but if fgets reads exactly N-1 characters without a newline, the last character may be part of the word, and setting it to '\0' truncates valid data. Also, if the line ends with '\n', then str[len-1] is '\n', so replacing with '\0' is correct, but if the file doesn't end with newline, this could remove a valid letter. However, more critically:]
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
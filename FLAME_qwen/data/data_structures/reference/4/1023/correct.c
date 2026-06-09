// 5. 词频统计（数组或链表实现）
// 【问题描述】

// 编写程序统计一个英文文本文件中每个单词的出现次数（词频统计），并将统计结果按单词字典序输出到屏幕上。

// 注：在此单词为仅由字母组成的字符序列。包含大写字母的单词应将大写字母转换为小写字母后统计。

// 【输入形式】

// 打开当前目录下文件“article.txt”，从中读取英文单词进行词频统计。


// 【输出形式】

// 程序将单词统计结果按单词字典序输出到屏幕上，每行输出一个单词及其出现次数，单词和其出现次数间由一个空格分隔，出现次数后无空格，直接为回车。

// 【样例输入】

// 当前目录下文件article.txt内容如下：


// “Do not take to heart every thing you hear.”

// “Do not spend all that you have.”

// “Do not sleep as long as you want;”


// 【样例输出】

// all 1

// as 2

// do 3

// every 1

// have 1

// hear 1

// heart 1

// long 1

// not 3

// sleep 1

// spend 1

// take 1

// that 1

// thing 1

// to 1

// want 1

// you 3


// 【样例说明】

// 按单词字典序依次输出单词及其出现次数。


// 【评分标准】

// 通过所有测试点将得满分。
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Occurrence_Num{
    char Word[50];
    int Num;
    struct Occurrence_Num *Next;
};
struct Occurrence_Num *Append_Num(struct Occurrence_Num *Head,struct Occurrence_Num *pr);
void Delete_Struct(struct Occurrence_Num *p);
void Delete_Word(char *str);
int main(){
    FILE *In;
    struct Occurrence_Num *Head=NULL;
    struct Occurrence_Num *pr=NULL;
    char Stdin_Word[50]={ },Letter;
    int i=0;
    In=fopen("article.txt","r");
    while((Letter=fgetc(In))!=EOF){
        if(Letter>='A'&&Letter<='Z')Letter=Letter+'a'-'A';
        if(Letter>='a'&&Letter<='z'){
            Stdin_Word[i]=Letter;
            i++;
        }
        else{
            if(Stdin_Word[0]==0)continue;
            Stdin_Word[i]='\0';
            pr=(struct Occurrence_Num *)malloc(sizeof(struct Occurrence_Num));
            strcpy((*pr).Word,Stdin_Word);
            (*pr).Num=1;
            (*pr).Next=NULL;
            Head=Append_Num(Head,pr);
            i=0;
            Delete_Word(Stdin_Word);
            continue;
        }
    }
    pr=Head;
    while(pr!=NULL){
        printf("%s %d\n",(*pr).Word,(*pr).Num);
        pr=pr->Next;
    }
    fclose(In);
    Delete_Struct(Head);
    return 0;
}
struct Occurrence_Num *Append_Num(struct Occurrence_Num *Head,struct Occurrence_Num *pr){
    if(Head==NULL){
        Head=pr;
        Head->Next=NULL;
        return Head;
    }
    struct Occurrence_Num *p_Now,*p_Before;
    p_Now=Head;
    if(strcmp((*p_Now).Word,(*pr).Word)==0){
        (*p_Now).Num++;
        free(pr);
        return Head;
    }
    else if(strcmp((*p_Now).Word,(*pr).Word)>0){
        pr->Next=Head;
        Head=pr;
        return Head;
    }
    while(p_Now->Next!=NULL&&strcmp((*p_Now).Word,(*pr).Word)<0){
        p_Before=p_Now;
        p_Now=p_Now->Next;
    }
    if(strcmp((*p_Now).Word,(*pr).Word)==0){
        (*p_Now).Num++;
        free(pr);
        return Head;
    }
    else if(strcmp((*p_Now).Word,(*pr).Word)>0){
        p_Before->Next=pr;
        pr->Next=p_Now;
        return Head;
    }
    p_Now->Next=pr;
    p_Now=p_Now->Next;
    p_Now->Next=NULL;
    return Head;
}
void Delete_Struct(struct Occurrence_Num *p){
    struct Occurrence_Num *pr;
    while(p!=NULL){
        pr=p;
        p=p->Next;
        free(pr);
    }
}
void Delete_Word(char *str){
    int i=0;
    while(str[i]!=0){
        str[i]=0;
        i++;
    }
}

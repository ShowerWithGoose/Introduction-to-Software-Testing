/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct wordcount{
    char piece[30];
    int count;//频度
    struct wordcount *next;
}node,*word;
char article[1000001];
void bubblesort(word l){
    for(word first=l->next;first!=NULL;first=first->next){ // @@ C89标准不支持在for循环初始化部分声明变量，会导致编译错误
        for(word second=l->next;second!=NULL;second=second->next){ // @@ 同上
            if(second->next!=NULL){
                if(strcmp(second->piece,second->next->piece)>0){
                    int temp=second->count;
                    second->count=second->next->count;
                    second->next->count=temp;
                    int len1=strlen(second->piece),len2=strlen(second->next->piece); // @@ C89标准要求变量声明必须位于代码块开头，不能与执行语句混合
                    char temp2[30]; // @@ 同上
                    for(int i=0;i<len1;i++){ // @@ C89标准不支持在for循环初始化部分声明变量
                        temp2[i]=second->piece[i];
                    }
            
                    for(int i=0;i<len2;i++){ // @@ 同上
                        second->piece[i]=second->next->piece[i];
                    }
                    second->piece[len2]='\0';
                    for(int i=0;i<len1;i++){ // @@ 同上
                        second->next->piece[i]=temp2[i];
                    }
                    second->next->piece[len1]='\0';
                }
            }
        }
    }
}//冒泡排序
int main()
{
    FILE *in,*mid;
    in=fopen("article.txt","r");
    mid=fopen("mid.txt","w");
    int c,len=0;
    while((c=fgetc(in))!=EOF){
        if(c>='A'&&c<='Z'){
            fputc(c-('A'-'a'),mid);
        }
        else if((c>='a'&&c<='z')||c==' '||c=='\n'){
            fputc(c,mid);
        }
    }//转小写，仅保留字母、空格和换行符
    fclose(in);
    fclose(mid);
    mid=fopen("mid.txt","r");
    int temp;
    while((temp=fgetc(mid))!=EOF){
        article[len++]=temp;
    }
    article[len]='\0';
    word head,p,r;
    head=(word)malloc(sizeof(node));
    r=head;
    for(int i=0;i<len;i++){ // @@ C89标准不支持在for循环初始化部分声明变量
        int len_of_word=0;
        if((i>0&&(article[i-1]<'a'||article[i-1]>'z')&&article[i]>='a'&&article[i]<='z')||(i==0&&article[i]>='a'&&article[i]<='z')){
            p=(word)malloc(sizeof(node));
            for(int j=i;article[j]>='a'&&article[j]<='z';j++){ // @@ 同上
                p->piece[len_of_word++]=article[j];
            }
            p->piece[len_of_word]='\0';
            p->count=1;
            r->next=p;
            r=p;
        }
        i+=len_of_word;
    }
    r->next=NULL;//完成单词链表创建

    word flag=head->next;
    while(flag!=NULL){
        p=flag;
        while(p->next!=NULL){
            if(strcmp(flag->piece,p->next->piece)==0){
                flag->count++;
                word q=p->next; // @@ C89标准要求变量声明必须位于代码块开头，此处声明在赋值语句之后
                p->next=q->next;
                free(q);
            }
            else{
                p=p->next;
            }
        }
        flag=flag->next;
    }
    bubblesort(head);
    p=head->next;
    while(p!=NULL){
        printf("%s %d\n",p->piece,p->count);
        p=p->next;
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORD  32
//梳理思路 gets输入 遇到空格就停 tempword在wordcount里面比较 compare函数按字典序输出
struct node {
    char word[MAXWORD];
    int count;
    struct node *link;
} ; //单词表结构
struct node *Wordlist = NULL; //单词表头指针
int getWord(FILE *bfp,char *w);
int searchWord(char *w);
int insertWord( struct node *p, char *w);
/*
int getWord(FILE *bfp, char *w) {
    int c;
    int i = 0;

    // 跳过空白字符
    while ((c = fgetc(bfp)) != EOF && isspace(c)) 
    {
        // do nothing
    }

    // 如果已经到达文件末尾，返回 EOF
    if (c == EOF) {
        return EOF;
    }

    // 读取单词直到遇到空白字符或文件末尾
    while (c != EOF && !isspace(c)) {
        // 检查单词长度是否超过最大限制
        if (i < MAXWORD - 1) {
            w[i++] = c;
        } else {
            break;
        }
        c = fgetc(bfp);
    }

    // 添加字符串终止符
    w[i] = '\0';

    // 如果单词长度为0，继续读取下一个单词
    if (i == 0) {
        return getWord(bfp, w);
    }

    return 0;
}
*/

int getWord(FILE *bfp, char *w) {
    int c;
    int i = 0;

    // 跳过空白字符和标点符号
    while ((c = fgetc(bfp)) != EOF && !isalpha(c)) {
        // 如果遇到换行符，继续读取
        if (c == '\n') {
            continue;
        }
    }

    // 如果已经到达文件末尾，返回 EOF
    if (c == EOF) {
        return EOF;
    }

    // 读取单词直到遇到空白字符、标点符号、文件末尾
    while (c != EOF && isalpha(c)) {
        // 检查单词长度是否超过最大限制
        if (i < 10000) { // @@ 应使用 MAXWORD-1 而不是固定值 10000，否则可能导致缓冲区溢出
            w[i++] = tolower(c); // 将大写字母转换为小写字母
        } else {
            break;
        }

        c = fgetc(bfp);
    }

    // 添加字符串终止符
    w[i] = '\0';

    // 如果单词长度为0，继续读取下一个单词
    if (i == 0) {
        return getWord(bfp, w);
    }

    return 0;
}




int insertWord(struct node  *r, char *w)
{
      struct node  *t;

      t = (struct node * )malloc(sizeof(struct node));
      if(t == NULL) return -1; //没有内存空间
      strcpy(t->word, w);       //装填好一个初始值
      t->count = 1;                 // 词频初值为1
      t->link = NULL;              
      if(Wordlist == NULL) //1:空链表,插入t结点
           Wordlist = t;
      else if (r == NULL){  //2:首(头)结点前插入t
           t->link = Wordlist;
           Wordlist = t;
       }
       else {                       // 3:在r结点后插入t
           t->link = r->link;
           r->link = t;
       }
      return 0;
}

int searchWord(char *w)
{
struct  node *p, *q=NULL; //q为p的前序结点指针
for(p=Wordlist; p != NULL; q=p,p=p->link){
    if(strcmp(w, p->word) < 0) 
 break;
    else if(strcmp(w, p->word) == 0){
         p->count++;
         return 0 ;    // 找到加1,直接返回
    }
}
return insertWord(q, w); // 存在q为NULL
}

int main()
{
    //char filename[32]
    char word[MAXWORD];
    FILE *bfp;
    struct node *p;

    //scanf("%s", filename);
    if((bfp = fopen("C:\\Users\\13260\\desktop\\homework\\week3\\article.txt", "r")) == NULL) // @@ 应使用相对路径 "article.txt" 而非硬编码的绝对路径，否则无法在不同环境下运行
    {   //打开一个文件
        fprintf(stderr, "%s  cant open!\n","article.txt");
        //return -1;
        exit(1);
    }
    while( getWord(bfp,word) != EOF) //从文件中读入一个单词
        if(searchWord(word) == -1) { //在单词表中查找插入单词
            fprintf(stderr, "Memory is full!\n");
            fclose(bfp);
            return -1;
        }     //上述getWord函数没有给出，上次课中讲过了
    for(p=Wordlist; p != NULL; p=p->link) //遍历输出单词表
        printf("%s %d\n", p->word, p->count);
    fclose(bfp);    //关闭文件
    return 0;
}
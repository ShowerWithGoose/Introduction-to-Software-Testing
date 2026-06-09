#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

# define MAXWORD  50

struct node {
    char word[MAXWORD];
    int count;
    struct node *link;
} ; //单词表结构
struct node *Wordlist = NULL; //单词表头指针

int f1(FILE *bfp,char *w);
int f2(char *w);
int f3( struct node *p, char *w);
int xiang=0; 
/*在链表中p结点后插入包含给定单词的结点，同时置次数为1*/
int f3(struct node  *p, char *w)
{
    struct node  *q;

    q = (struct node * )malloc(sizeof(struct node));
    if(q == NULL) return -1; //没有内存空间
    strcpy(q->word, w);
    q->count = 1;
    q->link = NULL;
    if(Wordlist == NULL) //空链表
        Wordlist = q;
    else if (p == NULL){ //插入到头结点前
        q->link = Wordlist;
        Wordlist = q;
    }
    else {
        q->link = p->link;
        p->link = q;
    }
    return 0;
}

/*在链表中查找一单词，若找到，则次数加1；否则将该单词插入到有序表中相应位置，同时次数置1*/
int f2(char *w)
{
    struct  node *p, *q=NULL; //q为p的前序结点指针
    for(p=Wordlist; p != NULL; q=p,p=p->link){
        if(strcmp(w, p->word) < 0)
            break;
        else if(strcmp(w, p->word) == 0){
            p->count++;
            return 0 ;
        }
    }
    return f3(q, w);
}

/*从文件中读入一个单词（仅由字母组成的串），并转换成小写字母*/
int f1(FILE *bfp,char word[])
{
    int i=0;
    char temp;

    while((temp=fgetc(bfp))!=EOF){
        if(isalpha(temp)){
            word[i]=tolower(temp);
            i++;
        }
        else if(i>0){//说明i中已经至少有一个字符
            word[i]='\0';
            return 0;
        }
    }
    return EOF;
}
//getc,是字母一直读，否则break


int main()
{
    char filename[32]={"article.txt"};
    char word[MAXWORD];
    FILE *bfp;
    struct node *p;
    int ga,ji;
    xiang=ga+ji;

    if((bfp = fopen(filename, "r")) == NULL){ //打开一个文件
        fprintf(stderr, "%s  can’t open!\n",filename);
        return -1;
    }
    
    while( f1(bfp,word) != EOF) //从文件中读入一个单词
        if(f2(word) == -1) { //在单词表中查找插入单词
            fprintf(stderr, "Memory is full!\n");
            return -1;
        }
    
    for(p=Wordlist; p != NULL; p=p->link) //遍历输出单词表
    printf("%s %d\n", p->word, p->count);
    xiang=xiang-ga-ji;

    return 0;
}



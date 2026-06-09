#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tolower(s) (s>='A'&&s<='Z'?s-'A'+'a':s)
struct node {
    char word[100];
    int count;
    struct node *link;
} ;
typedef struct node* elemtype;
elemtype Wordlist = NULL; //单词表头指针
int getWord(FILE *fp,char *w);
int searchWord(char *w);
int insertWord(elemtype p, char *w);
int isNull(char c);
int main()
{
    char word[100];
    elemtype p;
    FILE *in;
    in=fopen("article.txt", "r");
     while(getWord(in,word)!= EOF)//从文件中读入一个单词 @@ [getWord returns 1 or EOF (0), but loop condition expects EOF (-1) for termination. This causes infinite loop or premature exit because getWord never returns EOF as defined.]
       if(searchWord(word)==-1) { //在单词表中查找插入单词
            fprintf(stderr, "Memory is full!\n");
            fclose(in);
            return -1;
        }
    for(p=Wordlist; p!= NULL; p=p->link) //遍历输出单词表
        printf("%s  %d\n", p->word, p->count); @@ [Extra space between %s and %d causes output format mismatch: expected "word count", got "word  count"]
    fclose(in);
    return 0;
}

/*在链表中p结点后插入包含给定单词的结点，同时置次数为1*/

int insertWord(elemtype p, char *w)
{
      elemtype q=NULL;
      q = (elemtype)malloc(sizeof(struct node));
      if(q==NULL) return -1; //没有内存空间
      strcpy(q->word, w);
      q->count = 1;
      q->link = NULL;
      if(Wordlist == NULL) //空链表
           Wordlist = q;
      else if (p == NULL){ //插入到头结点前
           q->link =Wordlist;
           Wordlist=q;
       }
       else {
           q->link = p->link;
           p->link = q;
       }
      return 0;
}
/*在链表中查找一单词，若找到，则次数加1；否则将该单词插入到有序表中相应位置，同时次数置1*/

int searchWord(char *w)
{
elemtype p, q=NULL; //q为p的前序结点指针
for(p=Wordlist; p != NULL; q=p,p=p->link){
    if(strcmp(w, p->word) < 0)
         break;
    else if(strcmp(w, p->word) == 0){
         p->count++;
         return 0 ;
    }
}
return insertWord(q, w);
}

int getWord(FILE *fp,char *w)
{
    int i=0;
    char c;
    while((c=fgetc(fp))!=EOF)
    {
        c=tolower(c);
        if((!(c>='a'&&c<='z'))&&(i<=0)){
            continue;
        }
        else if((!(c>='a'&&c<='z'))&&(i>0)){
            break;
        }
        w[i++]=c;
    }
    w[i]='\0';
    if(i>0) return 1;
    else return EOF; @@ [Should return 0 (not EOF) when no word read, to match loop condition in main expecting non-zero for success. Returning EOF here breaks loop logic since EOF != 1, but main compares against EOF incorrectly.]
}
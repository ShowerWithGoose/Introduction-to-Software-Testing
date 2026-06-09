#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAXWORD  32
typedef struct node {
    char word[MAXWORD];
    int count;
    struct node *link;
}node, *pnode; //单词表结构
node *Wordlist = NULL; //单词表头指针

int getWord(FILE *bfp,char *w){
    int c;
    int i=0;
    while(!isalpha(c=fgetc(bfp))){
        if(c==EOF) return 0;
        if(c==' ' || c=='\n' || c=='\t'){
            i=0;
        }else{
            w[i]='\0';
            return 1;
        }
    }
    while(isalpha(c)){
        // if(isupper(c)){
        //     w[i]=c-'A'+'a';
        // }else {
        //     w[i]=c;
        // }
        w[i]=tolower(c);
        //w[i]=c;
        i++;
        c=fgetc(bfp);
    }
    w[i]='\0';
    if(strlen(w)>0){
        return 1;
    }
} // @@ [Function getWord does not return a value in all control paths. When the outer while loop exits due to EOF and no alphabetic character was found, the function reaches the end without returning a value, causing undefined behavior.]

// int searchWord(struct lnode list[], char *w);
// int insertWord(struct lnode list[ ],  int pos, char *w);
int insertWord(struct node  *p, char *w)
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

int searchWord(char *w)
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
return insertWord(q, w);
}


int main(){
    FILE *in;
    in = fopen("article.txt", "r");
    // struct lnode wordlist[MAXSIZE];    /*单词表*/
    // int i;    
    // char filename[MAXWORD], word[MAXWORD];
    // while( getWord(in,word) != EOF)
    //     if(searchWord(wordlist, word) == -1) {
    //         fprintf(stderr, "Wordlist is full!\n");
    //         return -1;
    //     }
    char filename[32], word[MAXWORD];
    FILE *bfp;
    struct node *p;

    //scanf("%s", filename);
    // if(in == NULL){ //打开一个文件
    //     fprintf(stderr, "%s  can’t open!\n",filename);
    //     return -1;
    //  }
     while( getWord(in,word) ) //从文件中读入一个单词
        if(searchWord(word) == -1) { //在单词表中查找插入单词
            //fprintf(stderr, "Memory is full!\n");
            return -1;
        }
    for(p=Wordlist; p != NULL; p=p->link) //遍历输出单词表
        if(p->word[0] != ' ')
        printf("%s %d\n", p->word, p->count);
    

    return 0;
}
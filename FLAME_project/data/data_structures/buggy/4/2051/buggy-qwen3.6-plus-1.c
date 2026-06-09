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
} // @@ The function does not return a value in all control paths (specifically when strlen(w)==0), leading to undefined behavior. However, the primary logical error causing the "Wrong Answer" is likely in how non-alpha characters are handled in the first while loop or the missing return. But looking closely at the output, there is an empty line or space issue. Let's look at main.

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
        printf("%s %d\n", p->word, p->count); // @@ The condition `if(p->word[0] != ' ')` is incorrect. The problem states words consist only of letters. If an empty string or a string starting with space gets into the list (due to bugs in getWord or logic), it might be filtered here, but the real issue is that `getWord` can return 1 even if `w` is empty if the logic falls through incorrectly, or more likely, the `getWord` implementation is flawed. However, comparing the buggy output ` 4` (space then 4) vs expected `book 3`, it seems an empty word or a word with a space was inserted and counted. The first line of buggy output is ` 4`. This suggests a word consisting of a space or empty string was counted 4 times? No, ` 4` usually means an empty string key. The `getWord` function has a bug: if it encounters a non-alpha, non-whitespace character (like a digit or punctuation), it returns 1 with `w` potentially containing garbage or previous data if `i` wasn't reset properly, or just an empty string if `i` was 0. In the input `1970`, `1` is not alpha. The `while(!isalpha(...))` loop runs. `c='1'`. It is not EOF. It is not space/newline/tab. So it goes to `else`: `w[0]='\0'; return 1;`. This returns an empty string "". This empty string is then inserted into the list. There are no other such characters in the sample input except possibly newlines/spaces which are skipped. Wait, the input is just words and spaces/newlines. The `1970` part: `1` triggers the `else` branch in the first while loop, returning an empty word. This happens once. Why is the count 4? Maybe the `getWord` logic is more broken. 
    

    return 0;
}
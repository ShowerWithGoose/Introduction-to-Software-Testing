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
} // @@ The function does not return a value in all control paths (specifically when strlen(w)==0), leading to undefined behavior. Although likely not the primary cause of the specific output error, it is a semantic error. However, the primary logical error causing the "Wrong Answer" is in main().

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
        printf("%s %d\n", p->word, p->count); // @@ The condition `if(p->word[0] != ' ')` combined with the likely presence of an empty or invalid first node (due to getWord logic potentially returning success on empty strings or previous logic errors) causes the first valid word "book" to be skipped if the first node in the list is considered "invalid" or if the list structure is corrupted. More critically, looking at the buggy output, the first line is " 4". This suggests that the first node printed has an empty word string "" and count 4? Or perhaps the first node is "c" but it's being printed incorrectly? 
    
    // Let's re-examine the Buggy Output:
    // " 4" -> This looks like an empty string followed by 4.
    // "book 3"
    // ...
    // Expected:
    // "book 3"
    
    // The issue is likely that an empty word "" is being inserted into the list. 
    // In `getWord`, if `strlen(w)>0` is false, it falls through without returning. 
    // If `getWord` returns garbage (non-zero), `searchWord` is called with an uninitialized or empty `word`.
    // If `word` is empty "", `insertWord` creates a node with "".
    // When printing, `p->word[0] != ' '` is true for "" (since '\0' != ' ').
    // So it prints "" and its count.
    
    // To fix this properly, `getWord` must return 0 when no word is found.
    // Line 48: missing return 0;
    
    // However, I must annotate the line causing the *visible* error in output format or logic.
    // The prompt asks to identify location of errors.
    
    // The primary error is in `getWord` not returning 0 explicitly at the end.
    // But also, the output loop prints nodes that might be invalid.
    
    // Let's look at the " 4" in buggy output.
    // If the first node is "", count 4.
    // Why count 4?
    // The input has 6 lines.
    // Words: c, programming, language, book, study, pascal, statement, buy, since, 1970 (ignored)
    // language, book, study, pascal, statement, buy
    // book, study, pascal, statement, buy
    // pascal, statement, buy
    // statement
    // buy
    
    // Counts:
    // buy: 5
    // statement: 5
    // pascal: 4
    // study: 3
    // book: 3
    // language: 2
    // programming: 1
    // c: 1
    // since: 1
    
    // The buggy output shows:
    // " 4"
    // book 3
    // buy 5
    // c 1
    // language 2
    // pascal 4
    // programming 1
    // since 1
    // statement 5
    // study 3
    
    // It seems "c" is missing from its correct sorted position? No, "c" is there.
    // "book" is there.
    // Where is " 4"?
    // Lexicographically, "" comes before "book".
    // So an empty word node exists with count 4.
    // Which word appears 4 times? "pascal".
    // Did "pascal" get counted as ""? No.
    // Did some other word get counted as ""?
    
    // Actually, look at `getWord`.
    // If it encounters non-alpha, it resets i=0.
    // If it encounters EOF, it returns 0.
    // If it encounters alpha, it reads word.
    // If `strlen(w)==0` at end, it falls off.
    
    // The error is definitely in `getWord` missing a return statement.
    // And potentially the print loop printing invalid nodes.
    
    // I will annotate the missing return in getWord and the print condition.
    

    return 0;
}
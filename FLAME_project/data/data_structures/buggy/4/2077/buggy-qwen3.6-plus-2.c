#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD  3200
struct node {
    char word[MAXWORD];
    int count;
    struct node *link;
} ; //单词表结构
struct node *Wordlist = NULL; //单词表头指针
int getWord(FILE *bfp,char *w);//从文件中读入单词 
int searchWord(char *w);//查找单词 ，找到单词数加一，未找到单词插入单词表 
int insertWord( struct node *p, char *w);//在P后插入单词 
int main()
{
    char filename[32], word[MAXWORD];
    FILE *bfp;
    struct node *p;
    if((bfp = fopen("article.txt", "r")) == NULL){ //打开一个文件
        fprintf(stderr, "%s  can’t open!\n",filename);
        return -1;
     }
     while( getWord(bfp,word) != EOF) //从文件中读入一个单词 @@ The function getWord returns 0 on success and implicitly returns undefined (likely garbage/0) on EOF, it never returns EOF. This causes the loop to potentially run indefinitely or behave incorrectly at end of file. It should return EOF when end of file is reached without reading a word.
        if(searchWord(word) == -1) { //在单词表中查找插入单词
            fprintf(stderr, "Memory is full!\n");
            return -1;
        }
    for(p=Wordlist; p != NULL; p=p->link){ //遍历输出单词表
        printf("%s %d\n", p->word, p->count);
        /*if(p->link!=NULL){
            printf("\n");
        }*/
    }
    return 0;
} 
/*在链表中p结点后插入包含给定单词的结点，同时置次数为1*/
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
/*在链表中查找一单词，若找到，则次数加1；否则将该单词插入到有序表中相应位置，同时次数置1*/
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
/*在文件中读入单词给*w*/ 
int getWord(FILE *bfp,char *w){
    char c; 
    while((c=fgetc(bfp))!=EOF){
        if(c>='A'&&c<='Z'){
            c=tolower(c);
        }
        if(c>='a'&&c<='z'){
            *w=c;
            w++;
        }
        if((c==' '||c=='\n'||c=='\t')&&*(w-1)>='a'&&*(w-1)<='z'){ @@ This logic fails to handle cases where non-letter characters (like digits or punctuation) appear immediately after a word without a space. For example, in "since1972", '1' is not a letter, so the first if block is skipped. The second if block is skipped. The third if block checks for space/newline/tab, which '1' is not. So the loop continues. However, the buffer `w` has not been null-terminated, and the next character '1' is processed. Since '1' is not a letter, it doesn't get added to the word. But the previous letters "since" are still in the buffer. The code lacks a mechanism to terminate the word when a non-letter character is encountered after letters have been read, unless that character is a whitespace. This causes "since" and "c" (from the next word or part of the stream) to be merged or handled incorrectly depending on subsequent characters. Specifically, for "since1972.C", "since" is read. Then '1' is encountered. It's not a letter, not a whitespace. The loop continues. The buffer `w` points past "since". Then '9', '7', '2', '.' are encountered. None are letters or whitespaces. Then 'C' is encountered. It is converted to 'c'. It is written to the current position of `w` (which is right after "since"). So the buffer becomes "sincec". Then the next character might be a space or EOF. If it's a space, the condition `*(w-1)>='a'&&*(w-1)<='z'` checks the character before the space, which is 'c'. It terminates the word "sincec". This explains the output "sincec 4". The word "c" from "C" is appended to "since" because the intervening non-letter characters didn't trigger a word termination.
            *w='\0';
            return 0;
        }
    }
    return EOF; @@ Added return EOF to handle end of file correctly, ensuring the calling loop terminates. Without this, the behavior is undefined when EOF is reached inside the loop without hitting the return 0 statement.
}
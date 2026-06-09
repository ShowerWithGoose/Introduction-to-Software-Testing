#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  MAXWORD  55
#define  LETTER  'a'
#define  DIGIT  '0'
typedef struct in{
    char word[MAXWORD];
    int num;
    struct in *link;
} word;
char type(int c)    /* return type of ASCII character */
{
if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
return ( LETTER );
else return (c);
}
int  getword(char s[], FILE *fp){
    int c,  i = 0;
    while(type(c=fgetc(fp))!= LETTER)
        if(c == EOF) return c;
        else continue;
    s[i++] = c;  //下一句的fgetc读到文件尾返回EOF @@ No bounds checking for index i, may cause buffer overflow if a word exceeds MAXWORD-1 characters.
    while((c=fgetc(fp))!=EOF){
         if(type(c)!=LETTER)
              break;
         s[i++] = c; @@ No bounds checking for index i, may cause buffer overflow if a word exceeds MAXWORD-1 characters.
    }
    s[i]='\0';
    return 1;
}



int main()
{
    FILE *fp = fopen("article.txt", "r"); @@ Missing check for fp == NULL, which may cause a segmentation fault if the file does not exist.
    word *list = NULL, *p = NULL, *q = NULL;
    int t;
    char s[MAXWORD];
    int flag = 0;
    while((t=getword(s,fp))!=EOF){
        int len = strlen(s);
        for (int i = 0; i < len;i++){ @@ Variable declaration inside for loop is a C99 feature, may cause compilation error in strict C89 mode.
            if(s[i]>='A'&&s[i]<='Z'){
                s[i] += 32;
            }
        }
        flag = 0;
        if(list==NULL){
            q = (word *)malloc(sizeof(word));
            strcpy(q->word, s);
            q->link = NULL;
            q->num = 1;
            list = p = q;
        } else{
            if(strcmp(s,list->word)<0){
                    q = (word *)malloc(sizeof(word));
                    strcpy(q->word, s);
                    q->link = list;
                    q->num = 1;
                    list = q;
                    memset(s, '\0', sizeof(s));
                    continue;
            }
            for (p = list; p != NULL;p=p->link){
                if(strcmp(s,p->word)==0){
                    p->num += 1;
                    break;
                } else{
                    if(p->link!=NULL){
                        if(strcmp(s,p->word)>0&&strcmp(s,p->link->word)<0){
                            q = (word *)malloc((sizeof(word)));
                            strcpy(q->word, s);
                            q->num = 1;
                            q->link = p->link;
                            p->link = q; @@ Missing break statement after insertion; the loop continues and processes the newly inserted node, incorrectly incrementing its count to 2.
                        }
                    } else{
                        q = (word *)malloc((sizeof(word)));
                        strcpy(q->word, s);
                        q->num = 1;
                        q->link = NULL;
                        p->link = q; @@ Missing break statement after insertion; the loop continues and processes the newly inserted node, incorrectly incrementing its count to 2.
                    }
                }
            }
        }
        memset(s, '\0', sizeof(s));
    }
    p = list;
    while(p!=NULL){
        word *temp = p;
        printf("%s %d\n", p->word, p->num);
        p = p->link;
        free(temp);
    }
    return 0; @@ Missing fclose(fp) to properly close the file and release system resources.
}
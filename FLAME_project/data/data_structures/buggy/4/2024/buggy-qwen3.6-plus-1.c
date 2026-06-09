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
    s[i++] = tolower(c);  // @@ The character read should be converted to lowercase immediately to ensure consistent case handling, as required by the problem description. The original code stores the raw character, relying on later conversion, but this can lead to issues if the logic depends on case-sensitive comparisons before conversion or if non-letter characters are mishandled. More importantly, the reference implementation converts to lowercase here.
    while((c=fgetc(fp))!=EOF){
         if(type(c)!=LETTER)
              break; 
         s[i++] = tolower(c);  // @@ Similarly, subsequent letters should be converted to lowercase immediately upon reading to maintain consistency with the "convert to lowercase before counting" requirement and to ensure correct lexicographical ordering and comparison.
    }
    s[i]='\0';
    return 1;
}



int main()
{
    FILE *fp = fopen("article.txt", "r");
    word *list = NULL, *p = NULL, *q = NULL;
    int t;
    char s[MAXWORD];
    int flag = 0;
    while((t=getword(s,fp))!=EOF){
        int len = strlen(s);
        for (int i = 0; i < len;i++){
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
                            p->link = q;
                            break; // @@ Missing break statement. After inserting a new node, the loop should terminate. Without this break, the loop continues, potentially causing incorrect behavior or infinite loops if the list structure is modified unexpectedly during iteration.
                        }
                    } else{
                        q = (word *)malloc((sizeof(word)));
                        strcpy(q->word, s);
                        q->num = 1;
                        q->link = NULL;
                        p->link = q;
                        break; // @@ Missing break statement. After appending a new node at the end of the list, the loop should terminate. Without this break, the loop condition `p != NULL` will eventually fail when `p` becomes `q` (which has `link = NULL`) in the next iteration step `p=p->link`, but it's safer and clearer to break explicitly after insertion. More critically, without the break in the inner `if`, the code falls through to the `else` block in the next iteration or behaves unpredictably. Actually, looking closely: if we insert in the `if(p->link!=NULL)` block, we modify `p->link`. The next `p=p->link` in the for loop update will move to the newly inserted node. Then `p->link` is the old next node. The loop continues. This is logically flawed because we've already placed the word. We must break after insertion. Same for the `else` block (appending to end).
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
    return 0;
}
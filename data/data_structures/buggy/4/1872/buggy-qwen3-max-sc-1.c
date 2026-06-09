#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
typedef struct node {
    char s[100];
    int n;
    struct node*p;
} node,*lnode;
int main() {
    FILE*rstream=fopen("article.txt","rb");
    char s1[1005];
    int i;
    lnode q,r,list=NULL,d1,d2;
    char c=fgetc(rstream); // @@ [If the file does not exist or cannot be opened, rstream will be NULL, and fgetc(NULL) leads to undefined behavior. Also, "rb" mode is unnecessary for text files and may cause issues on some systems.]
    while(c!=EOF) {
        q=(lnode)malloc(sizeof(node)); // @@ [Memory is allocated even for non-letter characters or empty tokens, which may lead to invalid words being processed.]
        q->n=0;
        for( i=0; c!=' '&&c!='\n'; i++) { // @@ [This loop condition assumes words are separated only by space or newline, but problem defines word boundaries as any non-letter character. Also, if file starts with non-letter, c may be EOF or punctuation, leading to incorrect loop entry.]
            if(c>='A'&&c<='Z') {
                c=c+32;
                q->s[i]=c;
            } else if(c>='a'&&c<='z') {
                q->s[i]=c;
            } else {
                i=i-1; // @@ [This attempts to skip non-letter characters, but doesn't break the loop; instead, it keeps reading until space/newline, potentially including multiple non-letter interruptions in one token.]
            }
            c=fgetc(rstream);
        }//记录了一个词
       if(i!=0){
       
       q->s[i]='\0';
        if(list==NULL) {
            q->p=NULL;
            list=q;
            list->n=(list->n)+1;
        } else if(list->p==NULL) {
            if(strcmp(q->s,list->s)<0) {
                q->p=list;
                list=q;
                list->n++;
            } else if(strcmp(q->s,list->s)==0) {
                list->n=(list->n)+1;
            } else if(strcmp(q->s,list->s)>0) {
                q->n++;
                list->p=q;
                r=q;
                r->p=NULL;
            }
        } else {
         if(strcmp(q->s,r->s)==0) {
                r->n++;
            } else if(strcmp(q->s,r->s)>0) {
                q->n++;
                r->p=q;
                r=q;
                r->p=NULL;
            }else if(strcmp(q->s,list->s)<0) {
                    q->p=list;
                    list=q;
                    list->n++;
                } else {
            for(d1=list; d1!=r; d1=d1->p) { // @@ [The loop condition d1 != r assumes a linear list ending at r, but insertion logic doesn't maintain r correctly in all cases, leading to infinite loops or missed insertions. Also, if d1->p is NULL during traversal, strcmp(q->s, d1->p->s) causes segmentation fault.]
                if(strcmp(q->s,d1->s)==0) {
                    d1->n++;
                } else if(strcmp(q->s,d1->s)>0&&strcmp(q->s,d1->p->s)<0) { // @@ [Accessing d1->p without checking if it's NULL leads to undefined behavior (likely crash).]
                    q->p=d1->p;
                    d1->p=q;
                    q->n++;//有待商榷
                    d1=d1->p;
                }
            }
            

        }}}

    c=fgetc(rstream); } // @@ [After inner loop reads until space/newline, this reads next char, but if last word ends at EOF, this sets c=EOF and exits, possibly skipping the last word if not handled properly. Also, no handling of consecutive delimiters or EOF inside word extraction.]
    for(d2=list; d2!=NULL; d2=d2->p) {
        printf("%s %d\n",d2->s,d2->n);
    }
    fclose(rstream);
    return 0;
}
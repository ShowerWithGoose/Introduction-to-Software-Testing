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
    char c=fgetc(rstream); // @@ [If the file does not exist or cannot be opened, rstream will be NULL, and fgetc(NULL) causes undefined behavior. Also, 'c' should be declared as int to properly handle EOF.]
    while(c!=EOF) {
        q=(lnode)malloc(sizeof(node)); // @@ [No check for malloc failure; also, memory is allocated even for non-letter sequences, which may lead to empty or invalid words being processed.]
        q->n=0;
        for( i=0; c!=' '&&c!='\n'; i++) { // @@ [This loop condition assumes word separators are only space or newline, but problem defines word as sequence of letters; punctuation and other non-letter characters should also terminate a word. Additionally, if c==EOF initially, this loop may not behave correctly.]
            if(c>='A'&&c<='Z') {
                c=c+32;
                q->s[i]=c;
            } else if(c>='a'&&c<='z') {
                q->s[i]=c;
            } else {
                i=i-1; // @@ [This decrements i for non-letter characters, but the loop still continues reading until space/newline, potentially including multiple non-letter characters and causing incorrect word formation or buffer overflow.]
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
            for(d1=list; d1!=r; d1=d1->p) { // @@ [The loop condition d1!=r assumes r is always the last node, but r is only updated in specific branches; if insertion happens in middle, r becomes stale, leading to incorrect traversal or infinite loop. Also, d1->p may be NULL inside loop when d1==r, causing strcmp(q->s,d1->p->s) to dereference NULL.]
                if(strcmp(q->s,d1->s)==0) {
                    d1->n++;
                } else if(strcmp(q->s,d1->s)>0&&strcmp(q->s,d1->p->s)<0) { // @@ [d1->p could be NULL here (e.g., when d1 is last node), leading to segmentation fault when accessing d1->p->s.]
                    q->p=d1->p;
                    d1->p=q;
                    q->n++;//有待商榷
                    d1=d1->p; // @@ [Modifying loop variable inside loop can cause skipped nodes or infinite loops.]
                }
            }
            

        }}}

    c=fgetc(rstream); } // @@ [After processing a word, this reads next character, but if previous read ended at EOF, this sets c=EOF again; however, logic doesn't handle case where file ends without trailing space/newline, possibly missing last word or causing duplicate processing.]
    for(d2=list; d2!=NULL; d2=d2->p) {
        printf("%s %d\n",d2->s,d2->n);
    }
    fclose(rstream);
    return 0;
}
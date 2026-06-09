#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define max 32
struct word {
    char str[max];
    int count;
    struct word*next;
};
int main() {
    FILE*in;
    in=fopen("article.txt","r");
    struct word*word_list,*p=NULL;
    p=word_list=(struct word*)malloc(sizeof(struct word)); // @@ [The initial dummy head node is uninitialized; its `str` and `count` contain garbage values, which leads to incorrect comparisons and counts.]
    word_list->next=NULL;
    char c;
    int i=0;
    char str[max]={0};
    while((c=fgetc(in))!=EOF) {
        if(c<='z'&&c>='a') {
            str[i]=c;
            i++;
        } else if(c<='Z'&&c>='A') {
            str[i]=c-'A'+'a';
            i++;
        } else {
            if(i!=0) {
                str[i]='\0';
                int k=0;
                p=word_list;
                while(p->next!=NULL) {

                    if(strcmp(p->str,str)==0) { // @@ [Comparing against the dummy head node's uninitialized `str`, which may accidentally match or corrupt logic. Also, the loop skips checking the last real node because it stops when `p->next == NULL`.]
                        p->count++;
                        k=1;
                    } else if(strcmp(p->str,str)<0&&strcmp(p->next->str,str)>0) { // @@ [This condition assumes the list is sorted, but insertion doesn't maintain full sort order due to flawed traversal and insertion logic. Also, comparing with uninitialized `str` in dummy node causes undefined behavior.]
                        struct word*tmp=(struct word*)malloc(sizeof(struct word));
                        tmp->next=NULL;
                        tmp->count=1;
                        strcpy(tmp->str,str);
                        tmp->next=p->next;
                        p->next=tmp;
                        k=1;
                    }
                    p=p->next;
                }
                if(k==0) {
                    if(strcmp(p->str,str)==0) { // @@ [At this point, `p` is the last real node (or dummy if list empty), but if list only has dummy, `p->str` is uninitialized. Also, this misses inserting in correct sorted position if new word belongs before last node.]
                        p->count++;
                    } else {
                        struct word*tmp=(struct word*)malloc(sizeof(struct word));
                        tmp->next=NULL;
                        tmp->count=1;
                        strcpy(tmp->str,str);
                        p->next=tmp;
                    }
                }
            }
            i=0;
        }
    }
    fclose(in);
    p=word_list;
    p=p->next;
    free(word_list);
    word_list=p;
    while(p!=NULL) {
        printf("%s %d\n",p->str,p->count);
        p=p->next;
        free(word_list); // @@ [Incorrect freeing: `word_list` is updated after `p` moves, causing double-free or premature free of nodes still in use. Should free `p`'s previous node, not `word_list` repeatedly.]
        word_list=p;
    }
    return 0;
}
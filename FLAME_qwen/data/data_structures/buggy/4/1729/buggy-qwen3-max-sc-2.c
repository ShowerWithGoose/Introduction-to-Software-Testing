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
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc(in) leads to undefined behavior. The program should check if in is NULL before proceeding.]
    struct word*word_list,*p=NULL;
    p=word_list=(struct word*)malloc(sizeof(struct word)); // @@ [The initial node allocated here is a dummy head node, but its str and count are uninitialized. This can cause undefined behavior when comparing or printing. Also, if malloc fails (returns NULL), dereferencing it causes a crash.]
    word_list->next=NULL;
    char c;
    int i=0;
    char str[max]={0};
    while((c=fgetc(in))!=EOF) { // @@ [fgetc returns an int, not a char. Storing it in a char variable (c) before comparing to EOF can cause incorrect loop termination on systems where char is signed, because EOF (-1) may be converted to a positive value when stored in unsigned char or misinterpreted in signed char. This leads to infinite loops or missed EOF.]
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

                    if(strcmp(p->str,str)==0) { // @@ [The dummy head node's str is uninitialized, so strcmp(p->str, str) on the first iteration reads garbage, leading to undefined behavior.]
                        p->count++;
                        k=1;
                    } else if(strcmp(p->str,str)<0&&strcmp(p->next->str,str)>0) { // @@ [Again, p->str and p->next->str may be uninitialized (especially for the dummy head and first real node), causing undefined behavior in strcmp. Also, this insertion logic assumes the list is always sorted, but it's not maintained correctly during insertion.]
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
                    if(strcmp(p->str,str)==0) { // @@ [p points to the last node, which may be the dummy head if no words were inserted yet; its str is uninitialized, leading to undefined behavior in strcmp.]
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
        free(word_list); // @@ [This frees the current head of the list (word_list) in every iteration, but then sets word_list = p (which is word_list->next). However, after the first free, accessing word_list->next in the next iteration is invalid. This leads to double-free or use-after-free errors. The correct approach is to free each node as you traverse, without freeing the same pointer multiple times.]
        word_list=p;
    }
    return 0;
}
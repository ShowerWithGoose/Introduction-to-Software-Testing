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
    p=word_list=(struct word*)malloc(sizeof(struct word)); // @@ [The initial node allocated here is used as a dummy head, but its str and count are uninitialized. This can cause issues when comparing or printing if accidentally used as a real word entry.]
    word_list->next=NULL;
    char c;
    int i=0;
    char str[max]={0};
    while((c=fgetc(in))!=EOF) { // @@ [c must be declared as int, not char, because EOF is outside the range of char. Using char for c may cause the loop to never terminate on systems where char is unsigned, since EOF (-1) would be converted to a positive value.]
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

                    if(strcmp(p->str,str)==0) { // @@ [This compares the dummy head node's uninitialized str with the current word. Since word_list->str is uninitialized, strcmp may read garbage, leading to undefined behavior.]
                        p->count++;
                        k=1;
                    } else if(strcmp(p->str,str)<0&&strcmp(p->next->str,str)>0) { // @@ [Again, p->str may be uninitialized (especially for the dummy head), causing undefined behavior in strcmp. Also, this insertion logic assumes the list is always sorted, but it's not maintained correctly during insertion.]
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
                    if(strcmp(p->str,str)==0) { // @@ [p now points to the last node, but if the list only has the dummy head (i.e., no real words yet), p->str is still uninitialized, leading to undefined behavior.]
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
        free(word_list); // @@ [This frees the current head of the list in every iteration, but then sets word_list = p (which is the next node). However, after the first free, accessing word_list in the next iteration is invalid. Also, p becomes a dangling pointer after freeing its memory indirectly via word_list. This leads to use-after-free and double-free risks.]
        word_list=p;
    }
    return 0;
}
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
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc(in) leads to undefined behavior. The program should check if in is NULL after fopen.]
    struct word*word_list,*p=NULL;
    p=word_list=(struct word*)malloc(sizeof(struct word)); // @@ [The initial node allocated here is a dummy head node, but its str and count are uninitialized. This can cause issues when comparing or printing. Also, memory allocation failure (malloc returning NULL) is not checked.]
    word_list->next=NULL;
    char c;
    int i=0;
    char str[max]={0};
    while((c=fgetc(in))!=EOF) { // @@ [fgetc returns an int, not char. Storing it in a char variable (c) before comparing to EOF can cause incorrect loop termination on platforms where char is signed, because EOF (-1) may be converted to a positive value when stored in unsigned char or compared incorrectly with signed char.]
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

                    if(strcmp(p->str,str)==0) { // @@ [The dummy head node's str is uninitialized, so strcmp(p->str, str) on the first iteration compares garbage with str, leading to undefined behavior.]
                        p->count++;
                        k=1;
                    } else if(strcmp(p->str,str)<0&&strcmp(p->next->str,str)>0) { // @@ [Same issue: p->str and p->next->str may be uninitialized (especially for the dummy head), causing undefined behavior in strcmp. Also, this insertion logic assumes the list is always sorted, but it's not maintained correctly during insertion.]
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
                    if(strcmp(p->str,str)==0) { // @@ [Again, p->str (the last node, possibly the dummy head if list is empty) is uninitialized, leading to undefined behavior in strcmp.]
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
        free(word_list); // @@ [This frees the current head of the list (word_list) in every iteration, but then sets word_list = p (which is the next node). However, after the first free, accessing word_list (which was just freed) in the next iteration is undefined behavior. Also, p may become a dangling pointer after freeing its previous node. Correct approach: store p->next before freeing p.]
        word_list=p;
    }
    return 0;
}
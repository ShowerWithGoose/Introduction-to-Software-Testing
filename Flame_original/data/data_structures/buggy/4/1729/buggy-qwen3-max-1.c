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
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc on a NULL pointer causes undefined behavior. The program should check if 'in' is NULL before proceeding.]
    struct word*word_list,*p=NULL;
    p=word_list=(struct word*)malloc(sizeof(struct word)); // @@ [The initial node allocated here is used as a dummy head, but its 'str' and 'count' are uninitialized. This can lead to undefined behavior when comparing or printing. Also, if malloc fails (returns NULL), dereferencing it later causes a crash.]
    word_list->next=NULL;
    char c;
    int i=0;
    char str[max]={0};
    while((c=fgetc(in))!=EOF) { // @@ [fgetc returns an int, not a char. Storing it in a char variable 'c' can cause incorrect EOF detection, especially on systems where char is signed. For example, if fgetc returns 0xFF (which is -1 in signed char), it may be mistaken for EOF prematurely.]
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

                    if(strcmp(p->str,str)==0) { // @@ [The dummy head node 'word_list' has uninitialized 'str', so strcmp with it leads to undefined behavior. Also, the logic skips checking the last node in the list because the loop condition is 'p->next != NULL'.]
                        p->count++;
                        k=1;
                    } else if(strcmp(p->str,str)<0&&strcmp(p->next->str,str)>0) { // @@ [This insertion logic assumes the list is always sorted, but new words are not inserted in sorted order correctly due to flawed traversal and comparison. Also, accessing p->next->str when p->next might be NULL (though loop condition prevents that, the logic is still broken).]
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
                    if(strcmp(p->str,str)==0) { // @@ [Again, comparing against possibly uninitialized 'str' in the last node (or dummy head if list is empty). Also, if the list only has the dummy head, p points to it and its 'str' is garbage.]
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
        free(word_list); // @@ [Inside the loop, 'word_list' is freed repeatedly while 'p' still points into the freed memory. This causes use-after-free and double-free issues. The correct approach is to free each node just before moving to the next.]
        word_list=p;
    }
    return 0;
}
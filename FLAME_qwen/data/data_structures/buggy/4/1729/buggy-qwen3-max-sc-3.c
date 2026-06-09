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
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc(in) leads to undefined behavior. The program should check if 'in' is NULL after fopen.]
    struct word*word_list,*p=NULL;
    p=word_list=(struct word*)malloc(sizeof(struct word)); // @@ [The initial node created here is a dummy head node, but its 'str' and 'count' are uninitialized. Later logic assumes the first real word starts at word_list->next, but comparisons with p->str (which is uninitialized) cause undefined behavior.]
    word_list->next=NULL;
    char c;
    int i=0;
    char str[max]={0};
    while((c=fgetc(in))!=EOF) { // @@ [The variable 'c' is declared as char, but fgetc returns int. This causes incorrect EOF detection because EOF (typically -1) may be truncated when stored in a char, especially on systems where char is unsigned.]
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

                    if(strcmp(p->str,str)==0) { // @@ [This compares against p->str, but p starts at the dummy head node whose 'str' is uninitialized. This leads to undefined behavior when strcmp reads garbage data.]
                        p->count++; // @@ [Similarly, incrementing p->count on the dummy node is incorrect; real words should start from word_list->next.]
                        k=1;
                    } else if(strcmp(p->str,str)<0&&strcmp(p->next->str,str)>0) { // @@ [Again, p->str is uninitialized for the dummy head. Also, this insertion logic assumes the list is sorted, but it's not maintained correctly due to flawed traversal and insertion.]
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
                    if(strcmp(p->str,str)==0) { // @@ [At this point, p points to the last node (real or dummy). If the list only has the dummy node, p->str is still uninitialized, causing undefined behavior in strcmp.]
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
        free(word_list); // @@ [This frees the current head of the list in every iteration, but then sets word_list = p (which is the next node). However, after freeing word_list, accessing it again is unsafe. More critically, this loop frees nodes one by one but prints before freeing, which is okay, but the logic is convoluted and risks double-free or use-after-free if not careful. However, the bigger issue is that the list was never properly built due to earlier errors.]
        word_list=p;
    }
    return 0;
}
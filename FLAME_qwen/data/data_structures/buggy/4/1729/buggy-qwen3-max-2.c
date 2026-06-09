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
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc(in) leads to undefined behavior. The program should check if 'in' is NULL before proceeding.]
    struct word*word_list,*p=NULL;
    p=word_list=(struct word*)malloc(sizeof(struct word)); // @@ [The initial node allocated here is a dummy head node, but its 'str' and 'count' are uninitialized. Later logic assumes it holds valid data, which causes incorrect comparisons and counts.]
    word_list->next=NULL;
    char c;
    int i=0;
    char str[max]={0};
    while((c=fgetc(in))!=EOF) { // @@ [fgetc returns an int, not char. Storing it in a char variable 'c' can cause EOF comparison to fail on systems where char is unsigned, leading to infinite loops or missed EOF.]
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

                    if(strcmp(p->str,str)==0) { // @@ [This compares against the dummy head node's uninitialized 'str', which contains garbage. This leads to unpredictable behavior and missed word matches.]
                        p->count++; // @@ [Incrementing count of dummy head node instead of actual word node.]
                        k=1;
                    } else if(strcmp(p->str,str)<0&&strcmp(p->next->str,str)>0) { // @@ [Again comparing with uninitialized 'str' in dummy head and possibly uninitialized 'str' in next node (if not properly initialized during insertion). Also, this insertion logic assumes list is always sorted, but initial insertions may break this assumption.]
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
                    if(strcmp(p->str,str)==0) { // @@ [At this point, p points to the last node, but if the list only has the dummy head (i.e., first real word), p->str is uninitialized, causing undefined behavior in strcmp.]
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
        free(word_list); // @@ [Incorrect freeing: 'word_list' is freed in every iteration, but after the first free, 'word_list' becomes a dangling pointer. Subsequent frees cause double-free or invalid free errors. Should free each node individually as traversed.]
        word_list=p;
    }
    return 0;
}
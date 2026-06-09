#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
    char word[32];
    int cnt;
    struct node *next; 
};

struct node *list = NULL;
char w[32];

int getword(char ch[]) {
    char c = getchar(); // @@ should first skip non-letter characters, e.g., while(!isalpha(c=getchar()))...
    if(c == EOF) {
        return EOF;
    }
    int cnt = 0;
    while(1) { // @@ loop should only start after skipping initial non-letters; empty word when c is non-letter
        if(c >= 'a' && c <= 'z') {
            ch[cnt++] = c;
        }
        else if(c >= 'A' && c <= 'Z') {
            ch[cnt++] = c + 32;
        }
        else
            break;
        c = getchar();
    }
    ch[cnt] = '\0'; // @@ if cnt==0, empty word results; also missing return value for success
} // @@ missing return 1; function has no return for successful word

int main() {
    freopen("article.txt", "r", stdin);
    while(getword(w) != EOF) {
//    puts(w);
        int flag = 0;
        struct node *p = list, *q = NULL;
        for(; p != NULL; q = p, p = p -> next) {
            int res = strcmp(w, p -> word);
            if(res < 0) {
                break;
            }
            if(res == 0) {
                p -> cnt++;
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            struct node *t = (struct node*)malloc(sizeof(struct node));
            strcpy(t -> word, w);
            t -> cnt = 1;
            if(list == NULL) {
                list = t;
            }
            else if(q == NULL) {
                t -> next = list;
                list = t;
            }
            else {
                t -> next = q -> next;
                q -> next = t;
            }
        }
    }
    for(struct node *p = list; p != NULL; p = p -> next) {
        printf("%s %d\n", p -> word, p -> cnt);
    }
    return 0;
}
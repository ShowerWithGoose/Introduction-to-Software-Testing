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
    char c = getchar(); @@ The variable `c` is declared as `char`, which may be signed. If `getchar()` returns EOF (typically -1), it might not be correctly detected if `char` is unsigned or if sign extension issues occur. It should be `int`.
    if(c == EOF) {
        return EOF;
    }
    int cnt = 0;
    while(1) {
        if(c >= 'a' && c <= 'z') {
            ch[cnt++] = c;
        }
        else if(c >= 'A' && c <= 'Z') {
            ch[cnt++] = c + 32;
        }
        else
            break;
        c = getchar(); @@ Same issue: `c` should be `int` to correctly handle EOF. Also, if EOF is returned here, the loop breaks, but `ch` is null-terminated later. However, if the first character read was EOF, we returned earlier. If EOF is read inside the loop, we break, null-terminate, and return nothing (implicit return 0 or garbage). The function signature says `int` but doesn't return a value in the success path.
    }
    ch[cnt] = '\0';
} @@ Missing return statement. The function is declared to return `int`, but does not return a value when a word is successfully read. This leads to undefined behavior. The caller checks `!= EOF`, so it should return a non-EOF value (e.g., 1) on success.

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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tree {
    int num;
    int high;
    struct tree *llink;
    struct tree *rlink;
};
typedef struct tree tre;
tre tr, *first = NULL, *o = NULL, *p = NULL;
// tre tr, *first, *o, *p;
// *first = NULL; *o = NULL; *p = NULL;
void bianli (tre *T) {
    if (T -> llink == NULL && T -> rlink == NULL) {
        printf ("%d %d\n", T -> num, T -> high);
        return;
    }
    if (T -> llink != NULL) 
    bianli (T -> llink);
    if (T -> rlink != NULL)
    bianli (T -> rlink);
    return ;
}
int main()
{
    // first = NULL; o = NULL; p = NULL;
    // first = (tre *) malloc (sizeof (tre)); error!
    // memset (first, 0, sizeof (tre));
    int n, i;
    scanf ("%d", &n);
    for (i = 0; i < n; i++) {
        o = (tre *) malloc (sizeof (tre));
        memset (o, 0, sizeof (tre));
        scanf ("%d", &(o -> num));
        o -> high = 1;
        p = first;
        if (p == NULL) {
            first = o;
        }
        else while (1) {
            o -> high++;
            if (p -> num > o -> num) {
                if (p -> llink == NULL) {
                    p -> llink = o;
                    break;
                }
                else {
                    p = p -> llink;
                }
            }
            else {
                if (p -> rlink == NULL) {
                    p -> rlink = o;
                    break;
                }
                else {
                    p = p -> rlink;
                }
            }
        }
    }
    bianli (first);
    return 0;
}

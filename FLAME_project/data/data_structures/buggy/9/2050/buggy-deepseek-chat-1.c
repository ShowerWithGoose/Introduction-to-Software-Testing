#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct pos {
    int x1;
    int y1;
    int x2;
    int y2;
};

int rise(const void *p1, const void *p2) {
    struct pos *d1 = (struct pos *)p1;
    struct pos *d2 = (struct pos *)p2;
    if(d1->x1<d2->x1) return -1;
    else if(d1->x1>d2->x1) return 1;
    else if(d1->x2<d2->x2) return -1;
    else if(d1->x2>d2->x2) return 1;
    else return 0;
}

int ex;
int xunzhao(struct pos xianduan[], int i, int n, int ex){ // @@ [The function uses a global variable 'ex' which is passed by value, but the recursive call does not update the caller's 'ex' correctly. The function should return the total count, but the logic is flawed: it only returns after finding one match, and the global 'ex' is not properly accumulated across recursive calls.]
    for(int j=i+1; j<n; j++){
        if(xianduan[i].x2==xianduan[j].x1 && xianduan[i].y2==xianduan[j].y1){
            ex++;
            xunzhao(xianduan, j, n, ex);
            return ex;
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    struct pos xianduan[n];
    int zuobiao[2], max=0;

    for(int i=0; i<n; i++){
        scanf("%d%d%d%d",&xianduan[i].x1,&xianduan[i].y1,&xianduan[i].x2,&xianduan[i].y2);
    }
    
    qsort(xianduan, n, sizeof(struct pos), rise);

    int len[n];
    for(int i=0; i<n; i++){
        len[i] = 0;
    }
    
    for(int i=0; i<n; i++){
        ex = 1;
        len[i] = xunzhao(xianduan, i, n, ex); // @@ [The function xunzhao may not return a value if no match is found, leading to undefined behavior. Also, the recursion does not correctly accumulate the count of connected segments.]
    }

    max = len[0];
    zuobiao[0] = xianduan[0].x1;
    zuobiao[1] = xianduan[0].y1;
    for(int i=1; i<n; i++){
        if(max < len[i]){
            max=len[i];
            zuobiao[0] = xianduan[i].x1;
            zuobiao[1] = xianduan[i].y1;
        }
    }

    printf("%d %d %d\n",max,zuobiao[0],zuobiao[1]);
    return 0;
}
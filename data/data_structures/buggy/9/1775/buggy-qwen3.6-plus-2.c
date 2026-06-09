#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
}LINE;
int cmp(const void *p1,const void *p2){
    LINE *a=(LINE*)p1;
    LINE *b=(LINE*)p2;
    return a->num-b->num;
}
int cmp2(const void *p1,const void *p2){
    LINE *a=(LINE*)p1;
    LINE *b=(LINE*)p2;
    if(a->x1!=b->x2) // @@ Logical error: compares a->x1 with b->x2 instead of b->x1, causing incorrect sorting order by starting x-coordinate.
        return a->x1-b->x2; // @@ Logical error: subtracts b->x2 instead of b->x1, leading to wrong comparison results for sorting.
    else 
        return a->y1-b->y2;    
}
int main(){
    LINE line[2000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){ // @@ Compilation error in C89: declaring loop variable inside for-loop initializer is not supported; declare i at the beginning of main.
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
        line[i].num=1;
    }
    qsort(line,n,sizeof(LINE),cmp2);
    for(int i=0;i<n;i++){ // @@ Compilation error in C89: declaring loop variable inside for-loop initializer is not supported.
        for(int j=0;j<n;j++){ // @@ Compilation error in C89: declaring loop variable inside for-loop initializer is not supported.
            if(j==i)
                continue;
            else{
                if(line[j].x1==line[i].x2&&line[j].y1==line[i].y2){
                    line[i].x2=line[j].x2;
                    line[i].y2=line[j].y2;
                    line[i].num+=line[j].num;
                    line[j].num=0,line[j].x1=0,line[j].x2=0,line[j].y1=0,line[j].y2=0;
                }
            }    
        }
    }
    qsort(line,n,sizeof(LINE),cmp);
    printf("%d %d %d\n",line[n-1].num,line[n-1].x1,line[n-1].y1);
    return 0;
}
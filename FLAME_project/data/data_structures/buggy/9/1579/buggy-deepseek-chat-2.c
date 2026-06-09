#include<stdio.h>
#include<string.h>
typedef struct line{
    int x1, x2;
    int y1, y2;
    int lenth;
}Line, *Lineptr;
Line p[105];

void linedelete(int a, int num){
    for(int i = a; i < num - 1; i++){
        p[i].x1 = p[i++].x1; // @@ Error: Using post-increment i++ modifies i twice in the loop, causing incorrect array shifting and potential out-of-bounds access. Should use i+1 instead of i++.
        p[i].x2 = p[i++].x2; // @@ Error: Same issue as above; i is incremented multiple times per iteration.
        p[i].y1 = p[i++].y1; // @@ Error: Same issue.
        p[i].y2 = p[i++].y2; // @@ Error: Same issue.
    }
}
int main(){
    int num; scanf("%d",&num);
    for (int i = 0; i < num; i++){
        scanf("%d%d%d%d", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
        p[i].lenth = 1;
    }
    for (int i = 0; i < num; i++){
        for(int j = i + 1; j < num; j++){
            if((p[j].x1==p[i].x2)&&(p[j].y1==p[i].y2)){
                p[i].x2 = p[j].x2;
                p[i].y2 = p[j].y2;
                p[i].lenth++;
                linedelete(j, num);
                num --;
                j = i; // @@ Error: Setting j = i will cause j to become i, but then the inner loop increments j to i+1, skipping the current i element. Should set j = i - 1 so that after increment it becomes i.
                continue;
                
            }
            if((p[j].x2==p[i].x1)&&(p[j].y2==p[i].y1)){
                p[i].x1 = p[j].x1;
                p[i].y1 = p[j].y1;
                p[i].lenth++;
                linedelete(j, num);
                num --;
                j = i; // @@ Error: Same issue as above.
                continue;
            }
        }
    }
    int max = 0;
    int k;
    for(int i = 0; i < num; i++){
        if(p[i].lenth > max){
            max = p[i].lenth;
            k = i;    
        } 
    }
    printf("%d %d %d", max, p[k].x1, p[k].y1);


    return 0;
}
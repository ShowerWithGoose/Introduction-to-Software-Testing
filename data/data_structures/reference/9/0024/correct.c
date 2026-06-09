#include<stdio.h>
#include<stdlib.h>

/*
排序如果是从后往前排的话，就可以直接输出
*/

typedef struct segment{
    int x1;
    int y1;
    int x2;
    int y2;
    int chain;
    int hash;
}SEG;

int cmp(const void* a, const void* b);


int main(){
    SEG sg[120];
    int n = 0;
    /*
    读入
    */
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d%d%d", &sg[i].x1, &sg[i].y1, &sg[i].x2, &sg[i].y2);
        sg[i].chain = 1;
        sg[i].hash = 0;
    }
    /*排序，有向线段*/
    qsort(sg, n, sizeof(sg[0]), cmp);
    
    for(int i = 0; i < n; ++i){
        for(int k = i, j = 1; j < n; ++j){
            /*
            hash表示用过的线段(不会出现同一点有三条线段的情况)
            */
            if(sg[k].x2 == sg[j].x1 && sg[k].y2 == sg[j].y1 && sg[i].hash == 0){
                //printf("%d %d\n", sg[j].x1, sg[j].y1);
                sg[i].chain++;
                sg[j].hash++;
                k = j;
                j = 1;  //每次从头开始寻找(其实提高了复杂度)
            }
        }
    }

    SEG max = {.chain = 0};
    for(int i = 0; i < n; ++i){
        if(sg[i].chain > max.chain){
            max = sg[i];
        }
    }
    printf("%d %d %d", max.chain, max.x1, max.y1);
   
    return 0;
}


/*
x或者y小的排在前面，变成有序线段
*/
int cmp(const void* a, const void* b){
    SEG* c = (SEG*)a;
    SEG* d = (SEG*)b;
    if(c->x1 == d->x1){
        return c->y1 - d->y1;
    }
    else{
        return c->x1 - d->x1;
    }
}



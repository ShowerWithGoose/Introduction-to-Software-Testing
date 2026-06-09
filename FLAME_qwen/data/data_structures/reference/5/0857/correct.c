#include<stdio.h>
#include<stdlib.h>
typedef struct each{
    int a;
    int x;
};
typedef struct each EA;
int cmp(const void *p1,const void*p2){
    struct each *a = (struct each*)p1;
    struct each *b = (struct each*)p2;
    return b->x - a->x;
}
int main(){
    EA ap1[1001];
    EA ap2[1001];
    EA ans[1001];
    int i = 0;
    char c;
    do{
        scanf("%d%d%c",&ap1[i].a,&ap1[i].x,&c);
        i++;
    }while(c!='\n');
    int a1 = i;
    i = 0;
    do{
        scanf("%d%d%c",&ap2[i].a,&ap2[i].x,&c);
        i++;
    }while(c!='\n');
    int a2 = i;
    int j;
    int temp_a,temp_x;
    int t = 0,k;
    for(i = 0;i < a1+a2+1;i++){
        ans[i].x = -1;
        ans[i].a = 0;
    }
    for(i = 0;i < a1;i++){
        for(j = 0;j < a2;j++){
            temp_a = ap1[i].a * ap2[j].a;
            temp_x = ap1[i].x + ap2[j].x;
            int flag = 0;
            for(k = 0;k < t;k++){
                if(temp_x == ans[k].x){
                    ans[k].a += temp_a;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                ans[t].a = temp_a;
                ans[t].x = temp_x;
                t++;
            }
        }
    }
    qsort(ans,t,sizeof(struct each),cmp);
    for(i = 0;i < t;i++){
        printf("%d %d ",ans[i].a,ans[i].x);
    }
    return 0;
}

#include <stdio.h>

struct line{
    int x_1;
    int y_1;
    int x_2;
    int y_2;
    struct line *next;
};

int main(int argc, const char * argv[]) {
    struct line s[102];
    struct line *p=NULL;
    struct line *max=NULL;
    
    int i=0;
    int n=0;
    int j=0;
    int cnt=0;
    int out=0;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&s[i].x_1,&s[i].y_1,&s[i].x_2,&s[i].y_2);
        s[i].next=NULL;
        for(j=0;j<i;j++){
            if(s[j].x_1==s[i].x_2&&s[j].y_1==s[i].y_2){
                s[j].next=&s[i]; // @@ 连接方向反了：应设置s[i].next=&s[j]（因为s[i]的终点等于s[j]的起点，s[i]应指向s[j]）
            }
            else if(s[j].x_2==s[i].x_1&&s[j].y_2==s[i].y_1){
                s[i].next=&s[j]; // @@ 连接方向反了：应设置s[j].next=&s[i]（因为s[j]的终点等于s[i]的起点，s[j]应指向s[i]）
            }
        }
    }
    
    for(i=0;i<n;i++){
        p=&s[i];
        cnt=1;
        while(p->next!=NULL){
            p=p->next;
            cnt++;
            if(cnt>out){
                out=cnt;
                max=p; // @@ 错误：max应记录链的起点（即s[i]），而不是遍历后的末端节点p
            }
        }
    }
    printf("%d %d %d\n",cnt,max->x_1,max->y_1); // @@ 错误：应输出out（最长链的段数）和链起点的坐标，而非cnt和末端点的坐标
    return 0;
}
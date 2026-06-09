#include<stdio.h>

struct node{
    int bgx,bgy;
    int endx,endy;
    int cnt;
};
typedef struct node Node;
typedef struct node *Nodeptr;

int main(){
    int i,j,n,flag;
    int ENDX,ENDY;
    int maxsgn;
    Node line[100];

    scanf("%d",&n);

    for(i = 0;i< n;++i){
        scanf("%d %d",&line[i].bgx,&line[i].bgy);
        scanf("%d %d",&line[i].endx,&line[i].endy);
        line[i].cnt = 0;
    }
    for(j = 0;j < n;++j){
        ENDX = line[j].endx;
        ENDY = line[j].endy;
        do{
            flag = 0;
            for(i = 0;i < n;++i){
                if(line[i].bgx == ENDX && line[i].bgy == ENDY){
                    flag = 1;
                    line[j].cnt++;
                    ENDX = line[i].endx;
                    ENDY = line[i].endy;
                   break;
                }
            }
        }while(flag == 1);
    }

    for(maxsgn = 0,i = 1;i < n;++i){
        if(line[i].cnt > line[maxsgn].cnt){
            maxsgn = i;
        }
    }
    printf("%d %d %d",line[maxsgn].cnt+1,line[maxsgn].bgx ,line[maxsgn].bgy);


    return 0;
}



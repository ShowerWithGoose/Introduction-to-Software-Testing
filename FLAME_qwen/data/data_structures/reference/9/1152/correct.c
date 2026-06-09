#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long

typedef struct node{
    int xf,yf;
    int xt,yt;
    int is_head,len;
    struct node *next;
}pos;

int fmap[1000][1000],map[1000][1000];
pos line[111];

int main(){
//    freopen("r.txt","r",stdin);
//    freopen("w.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i){
        int xf,yf,xt,yt;
        scanf("%d%d%d%d",&line[i].xf,&line[i].yf,&line[i].xt,&line[i].yt);
        fmap[line[i].xt][line[i].yt]=1;
        map[line[i].xf][line[i].yf]=i;
    }
    for(int i = 1; i <= n; ++i){
        if(fmap[line[i].xf][line[i].yf] == 0){
            line[i].is_head = 1;
            line[i].len++;
        }
        line[i].next=&line[map[line[i].xt][line[i].yt]];
    }
    for(int i = 1; i <= n; ++i){
        if(line[i].is_head == 1){
            pos *p=&line[i];
            while(p->next != NULL){
                ++line[i].len;
                p=p->next;
            }
        }
    }
    pos *ans=&line[111];
    for(int i = 1; i <= n; ++i){
        if(line[i].is_head == 1){
            if(ans->len < line[i].len){
                ans = &line[i];
            }
        }
    }
    printf("%d %d %d",ans->len-1,ans->xf,ans->yf);
    return 0;
}

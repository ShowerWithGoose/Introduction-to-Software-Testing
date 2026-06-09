#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long

int h[11];
int ans[11];

void cre(int n,int x){
    if(x == 0){
        for(int i = n; i >= 1; --i){
            if(i > 1) printf("%d ",ans[i]);
            else printf("%d\n",ans[i]);
        }
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(h[i] == 0){
            h[i] = 1;
            ans[x] = i;
            cre(n,x-1);
            h[i] = 0;
        }
    }
}


int main(){
//    freopen("r.txt","r",stdin);
//    freopen("w.txt","w",stdout);
    int n;
    scanf("%d",&n);
    cre(n,n);
    return 0;
}

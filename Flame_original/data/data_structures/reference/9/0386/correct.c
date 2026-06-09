#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define DB double
#define FOR(X,Y,Z)  for(int X = Y;X<Z;X++)  
typedef struct line {
    int op[2];
    int ed[2];
} line;
int n,max = 0;
line a[110];
int inl[110];
int find(int t){
    for(int i = 0;i<n;i++){
        if(inl[i]) continue;
        if(a[i].op[0] == a[t].ed[0]&&a[i].op[1] == a[t].ed[1])
        return i;
        
    }
    return -1;
}
int main(){
    //freopen(".in","r",stdin);
    scanf("%d ",&n);
    for(int i = 0;i < n;i++){
        scanf("%d%d%d%d ",&a[i].op[0],&a[i].op[1],&a[i].ed[0],&a[i].ed[1]);
    }
    int ans;
    for(int i = 0;i < n;i++){
        memset(inl,0,sizeof(inl));
        int p = i,num = 1;
        inl[p] = 1;
        while(~(p = find(p))){
            num++;
            inl[p] = 1;
            
        }
        if(num > max){
            max = num;
            ans = i;
        }
    }
    printf("%d %d %d",max,a[ans].op[0],a[ans].op[1]);
    return 0;
}


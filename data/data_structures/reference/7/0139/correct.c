#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
#define maxn 1000005
int n,m;
int cnt,root,ls[maxn],rs[maxn],val[maxn];

int max(int a,int b){return a>=b ? a : b ;}
int min(int a,int b){return a<=b ? a : b ;}

int insert(int rt,int v){
    if(!rt) {
        rt=++cnt,val[rt]=v;
        return rt;
    }
    if(v<val[rt]) ls[rt]=insert(ls[rt],v);
    else rs[rt]=insert(rs[rt],v);
    return rt;
}

void print(int rt,int dep){
    if(!rt) return ;
    if(!ls[rt]&&!rs[rt]){
        printf("%d %d\n",val[rt],dep);
        return ;
    }
    print(ls[rt],dep+1);
    print(rs[rt],dep+1);
}

int main(){
    /*double st=clock();*/
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        root=insert(root,x);
    }
    print(root,1);
    /*double ed=clock();
    printf("Time:%lf ms",ed-st);*/
    return 0;
}

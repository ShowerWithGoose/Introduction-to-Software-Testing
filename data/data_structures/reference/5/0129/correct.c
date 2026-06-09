#include<stdio.h>
#define MAX 100005
struct xiang{
    int a,b;
}a1[MAX],a2[MAX],ans[MAX];
int n1,n2,n,nxt[MAX],hd;
void read(struct xiang *a, int *l){
    char ch=getchar();
    while(ch!='\n'){
        ++a; ++(*l);
        while(ch<'0'||ch>'9') ch=getchar();
        int k=0; while(ch>='0'&&ch<='9'){ k=k*10+ch-'0'; ch=getchar();}
        a->a=k;
        while(ch<'0'||ch>'9') ch=getchar();
        k=0; while(ch>='0'&&ch<='9') {k=k*10+ch-'0'; ch=getchar();}
        a->b=k;
    }
}

int main(){
    read(a1, &n1); read(a2, &n2);
    ans[0].b=-1;
    for(int i=1;i<=n1;++i){
        for(int j=1;j<=n2;++j){
            int x=a1[i].a*a2[j].a, y=a1[i].b+a2[j].b;
            if(i==1&&j==1) {ans[++n].a=x, ans[n].b=y, nxt[n]=hd, hd=n; continue;}
            for(int k=hd;k;k=nxt[k]){
                if(y > ans[nxt[k]].b){
                    ans[++n].a=x, ans[n].b=y;
                    nxt[n]=nxt[k], nxt[k]=n;
                    break;
                }
                if(y == ans[nxt[k]].b){
                    ans[nxt[k]].a+=x;
                    break;
                }
            }
        }
    }
    for(int i=1;i;i=nxt[i]) printf("%d %d ",ans[i].a,ans[i].b);
    return 0;
}

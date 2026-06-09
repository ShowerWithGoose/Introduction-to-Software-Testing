#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define N 105
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define ll long long
int in(){ll x;scanf("%lld",&x);return x;}
typedef struct{
    int bx,by,ex,ey;    
}line;
line a[N];
int v[N],pre[N];
int eq(int i,int j){
    return (a[i].ex==a[j].bx)&&(a[i].ey==a[j].by);
}
int main(){
    int n=in();
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&a[i].bx,&a[i].by,&a[i].ex,&a[i].ey);
    }
    for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           if(i==j)continue;
           if(eq(i,j))pre[j]=i;
       }
    }
    int ans=0,ansx=0,ansy=0;
    for(int i=1;i<=n;i++){
        int res=1;
        int now=i;
        while(pre[now])res++,now=pre[now];
        if(res>ans)ans=res,ansx=a[now].bx,ansy=a[now].by;
    }
    printf("%d %d %d",ans,ansx,ansy);
    return 0;
}

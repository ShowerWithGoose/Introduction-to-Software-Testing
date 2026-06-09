#include<stdio.h>
#define N 1005
int n,la[N],le[N],id;
struct seg{
    int a,b,c,d;
}s[N],ss[N];
void merge(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1,L=l,R=mid+1,p=l;
    merge(l,mid);merge(mid+1,r);
    while(L<=mid&&R<=r){
        if(s[L].a<s[R].a) ss[p++]=s[L++];
        else ss[p++]=s[R++];
    }
    while(L<=mid) ss[p++]=s[L++];
    while(R<=r) ss[p++]=s[R++];
    for(int i=l;i<=r;i++) s[i]=ss[i];
}
int link(int x,int y){return s[x].c==s[y].a&&s[x].d==s[y].b;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&s[i].a,&s[i].b,&s[i].c,&s[i].d);
        le[i]=1;
    }
    merge(1,n);
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(!link(j,i)) continue;
            la[i]=j;le[i]=le[j]+1;
        }
    }
    for(int i=1;i<=n;i++) if(le[i]>le[id]) id=i;
    printf("%d ",le[id]);
    while(la[id]) id=la[id];
    printf("%d %d\n",s[id].a,s[id].b);
    return 0;
}

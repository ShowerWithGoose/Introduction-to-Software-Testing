#include<stdio.h>
#include<string.h>
#define N 1005
int n,m,cnt,p,le;
char a[N];
int b1[N],b2[N],c1[N],c2[N];
struct node{
    int b,c;
}t[10005],tt[10005];
int read(){
    int s=0;char c=a[p++];
    while(c<'0'||c>'9') c=a[p++];
    while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+c-'0';c=a[p++];}
    return s;
}
void merge(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1,L=l,R=mid+1,p=l;
    merge(l,mid);merge(mid+1,r);
    while(L<=mid&&R<=r){
        if(t[L].c>=t[R].c) tt[p++]=t[L++];
        else tt[p++]=t[R++];
    }
    while(L<=mid) tt[p++]=t[L++];
    while(R<=r) tt[p++]=t[R++];
    for(int i=l;i<=r;i++) t[i]=tt[i];
}
int main(){
    gets(a+1);le=strlen(a+1);p=1;
    while(p<=le){b1[++n]=read();c1[n]=read();}
    gets(a+1);le=strlen(a+1);p=1;
    while(p<=le){b2[++m]=read();c2[m]=read();}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            t[++cnt].b=b1[i]*b2[j];
            t[cnt].c=c1[i]+c2[j];
        }
    }
    merge(1,cnt);t[cnt+1].c=-1;
    for(int i=1;i<=cnt;i++){
        if(t[i+1].c==t[i].c) t[i+1].b+=t[i].b;
        else printf("%d %d ",t[i].b,t[i].c);
    }
    return 0;
}

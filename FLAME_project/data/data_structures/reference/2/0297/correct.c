#include<stdio.h>
#include<string.h>
char c;
int n,m,fl,a[10005],b[10005],op[10005],po[10005];
int read(){
    int s=0;c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return s;
}
int get(){
    if(c=='+') return 1;
    if(c=='-') return 2;
    if(c=='*') return 3;
    if(c=='/') return 4;
    if(c=='='){fl=1;return 5;}
    c=getchar();return get();
}
int main(){
    a[++n]=read(),op[n]=get();
    while(!fl) a[++n]=read(),op[n]=get();
    for(int i=1;i<=n;i++){
        if(op[i]==1||op[i]==2||op[i]==5) b[++m]=a[i],po[m]=op[i];
        if(op[i]==3) a[i+1]=a[i]*a[i+1];
        if(op[i]==4) a[i+1]=a[i]/a[i+1];
    }
    for(int i=1;i<=m;i++){
        if(po[i]==1) b[i+1]=b[i]+b[i+1];
        if(po[i]==2) b[i+1]=b[i]-b[i+1];
        if(po[i]==5) printf("%d",b[i]);
    }
    return 0;
}

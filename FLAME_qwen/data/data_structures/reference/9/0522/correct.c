#include<stdio.h>
struct pot{
    int a[2];
    int b[2];
};
int main()
{
    struct pot s[1000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&s[i].a[0],&s[i].a[1],&s[i].b[0],&s[i].b[1]);
    }
    struct pot tmp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        if(s[i].a[0]>s[j].a[0]){
            tmp=s[i];
            s[i]=s[j];
            s[j]=tmp;
        }}
    }
    int x0,y0,c[1000];
    for(int i=0;i<n;i++){
        c[i]=1;
        x0=s[i].b[0],y0=s[i].b[1];
        for(int j=i+1;j<n;j++){
            if(x0==s[j].a[0]&&y0==s[j].a[1]){
                c[i]++;
                x0=s[j].b[0],y0=s[j].b[1];
            }
        }
    }
    int m=c[0],k;
    for(int i=0;i<n;i++){
        if(c[i]>m){
            m=c[i];
            k=i;
        }
    }
    printf("%d %d %d",m,s[k].a[0],s[k].a[1]);
    return 0;
}


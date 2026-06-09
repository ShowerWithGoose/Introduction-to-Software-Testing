#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
#define maxn 100005
int n,m,k;
struct number{
    int a,x;
}p[maxn],q[maxn],r[maxn];

int max(int a,int b){return a>=b ? a : b ;}
int min(int a,int b){return a<=b ? a : b ;}
int cmp(const void *x,const void *y){
    return (*(struct number *)y).x-(*(struct number*)x).x;
}

int main(){
    /*double st=clock();*/
    char ch=getchar();
    while(true){
        if(ch=='\n') break;
        n++;int x=0;
        while(!isdigit(ch)) ch=getchar();
        while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
        p[n].a=x,x=0;
        while(!isdigit(ch)) ch=getchar();
        while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
        p[n].x=x,x=0;
    }
    //printf("hh");
    ch=getchar();
    while(true){
        if(ch=='\n') break;
        m++;int x=0;
        while(!isdigit(ch)) ch=getchar();
        while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
        q[m].a=x,x=0;
        while(!isdigit(ch)) ch=getchar();
        while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
        q[m].x=x,x=0;
    }
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++){
         k++;
         r[k].a=p[i].a*q[j].a;
         r[k].x=p[i].x+q[j].x;
     }
    //printf("%d %d\n",n,m);
    qsort(r+1,k,sizeof(r[0]),cmp);
    int now=0;
    for(int i=1;i<=k;i++){
        if(r[i].x==r[now].x) r[now].a+=r[i].a;
        else r[++now]=r[i];
    }
    for(int i=1;i<=now;i++) printf("%d %d ",r[i].a,r[i].x);
    /*double ed=clock();
    printf("Time:%lf ms",ed-st);*/
    return 0;
}

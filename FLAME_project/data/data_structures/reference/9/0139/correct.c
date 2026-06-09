#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
#define maxn 100005
int n,m;
int next[maxn];
struct point{
    int x1,y1,x2,y2;
}p[maxn];


int max(int a,int b){return a>=b ? a : b ;}
int min(int a,int b){return a<=b ? a : b ;}
int read(){
    int x=0;int f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f ? -x : x ;
}

int main(){
    /*double st=clock();*/
    n=read();
    for(int i=1;i<=n;i++){
        p[i].x1=read(),p[i].y1=read();
        p[i].x2=read(),p[i].y2=read();
    }
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++){
         if(i==j) continue;
         if(p[i].x2==p[j].x1&&p[i].y2==p[j].y1) next[i]=j;
     }
    int now=0,ans=0;
    for(int i=1;i<=n;i++){
        int cnt=1;
        int k=i;
        while(next[k]) cnt++,k=next[k];
        if(cnt>now) now=cnt,ans=i;
    }
    printf("%d %d %d",now,p[ans].x1,p[ans].y1);
    /*double ed=clock();
    printf("Time:%lf ms",ed-st);*/
    return 0;
}

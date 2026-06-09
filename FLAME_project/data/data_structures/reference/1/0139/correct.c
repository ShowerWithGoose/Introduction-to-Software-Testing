#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
int n,m;
bool vis[15];
int num[15];

int max(int a,int b){return a>=b ? a : b ;}
int min(int a,int b){return a<=b ? a : b ;}

void dfs(int pos){
    if(pos>n){
        for(int i=1;i<=n;i++) printf("%d ",num[i]);
        putchar('\n');
    }
    for(int i=1;i<=n;i++)
     if(!vis[i]){
         vis[i]=true;
         num[pos]=i;
         dfs(pos+1);
         vis[i]=false;
     }
}

int main(){
    /*double st=clock();*/
    scanf("%d",&n);
    dfs(1);
    /*double ed=clock();
    printf("Time:%lf ms",ed-st);*/
    return 0;
}



#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
#define maxn 50005
int n,m,cnt;
int go[maxn][30],end[maxn];
char s[maxn];

int max(int a,int b){return a>=b ? a : b ;}
int min(int a,int b){return a<=b ? a : b ;}

void insert(){
    int now=0;
    for(int i=1;i<=n;i++){
        if(!go[now][s[i]-'a']) go[now][s[i]-'a']=++cnt;
        now=go[now][s[i]-'a'];
    }
    end[now]++;
    //printf("hh\n");
}

void print(int now,int dep){
    if(end[now]){
        for(int i=1;i<dep;i++) putchar(s[i]);
        printf(" %d\n",end[now]);
    }
    for(int i=0;i<26;i++)
     if(go[now][i]){
         s[dep]=i+'a';
         print(go[now][i],dep+1);
     }
}

int main(){
    /*double st=clock();*/
    freopen("article.txt","r",stdin);
    char ch;
    while(true){
        while(!isalpha(ch)) {
            ch=getchar();
            if(ch==EOF) {print(0,1);exit(0);}
        }
        n=0;
        while(isalpha(ch)) s[++n]=tolower(ch),ch=getchar();
        insert();
    }
    /*double ed=clock();
    printf("Time:%lf ms",ed-st);*/
    return 0;
}

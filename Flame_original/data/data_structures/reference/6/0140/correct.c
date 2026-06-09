#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define N 100050
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define ll long long
int stack[N];
int top=0;
int main(){
    int op,x;
    while(scanf("%d",&op)==1){
        if(op==-1)break;
        if(op){
            scanf("%d",&x);
            if(top==100)printf("error ");
            else stack[++top]=x;
        }
        else{
            if(top==0)printf("error ");
            else printf("%d ",stack[top--]);
        }
    }
    return 0;
}

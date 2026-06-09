#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
const int maxn=100;
int top,Stack[105];

int max(int a,int b){return a>=b ? a : b ;}
int min(int a,int b){return a<=b ? a : b ;}

int main(){
    /*double st=clock();*/
    int op;
    while(true){
        scanf("%d",&op);
        if(op==-1) break;
        else if(op==1){
            int num;
            scanf("%d",&num);
            if(top==maxn) printf("error ");
            else Stack[++top]=num;
        }
        else {
            if(!top) printf("error ");
            else printf("%d ",Stack[top]),top--;
        }
    }
    /*double ed=clock();
    printf("Time:%lf ms",ed-st);*/
    return 0;
}

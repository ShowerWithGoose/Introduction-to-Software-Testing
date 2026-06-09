#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define DB double
#define FOR(X,Y,Z)  for(int X = Y;X<Z;X++) 
int stack[150]; 
int main(){
    //freopen(".in","r",stdin);
    int op,top = -1,n;
    while(~scanf("%d ",&op)){
        if(op==-1) break;
        if(op==1){
            scanf("%d ",&n);
            if(top==99) printf("error ");
            else stack[++top] = n;
        }
        if(op==0){
            if(top==-1) printf("error ");
            else {
                printf("%d ",stack[top--]);
            }
        }
    }
    return 0;
}


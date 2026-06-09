#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int s[100];

int main(){
    int n;
    int x = 0;
    int top = -1;
    do{
        scanf("%d",&n);
        if(1 == n){
            if(99 == top){
                printf("error ");
                continue;
            }
            else{
                scanf("%d",&x);
                s[++top] = x;
            }
            
        }
        else if(0 == n){
            if(-1 == top){
                printf("error ");
                continue;
            }
            else{
                printf("%d ",s[top--]);
            }
        }
        else if(-1 == n){
            break;
        }
    }while(-1 != n);

    return 0;
}

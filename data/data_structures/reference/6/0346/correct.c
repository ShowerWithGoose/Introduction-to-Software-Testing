#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int s[101];
int cnt_s=0;
int n;
int m;
int input;
int main(){
    while(1){
        scanf("%d", &m);
        if(m==-1)
            break;
        else if(m==1){
            scanf("%d", &input);
            if(cnt_s==99)
                printf("error ");
            else{
                s[cnt_s++] = input;
            }
        }
        else if(m==0){
            if(cnt_s==0)
                printf("error ");
            else{
                printf("%d ", s[--cnt_s]);
            }
        }
    }
    return 0;
}

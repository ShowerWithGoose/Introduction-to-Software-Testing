#include<stdio.h>
int mark[12]={0};
char stack[22];
void recur(int m,int n,int k);
int main(){
    int in=0,k=0;
    scanf("%d",&in);
    k=in;
    recur(0,in,k);
    return 0;
}

    void recur(int m,int n,int k){
        int i;
        if(n==0){
            stack[m]='\0';
            puts(stack);
            return ;
        }
        for(i=1;i<=k;i++){
            if(mark[i]==0){
                stack[m]='0'+i;
                stack[m+1]=' ';
                mark[i]=1;
                recur(m+2,n-1,k);
                mark[i]=0;
            }

        }

    }


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 11

int a[10]={0};
int b[10]={0};
int n;
void rank(int m) {
    int i;
    if(m==n){
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for(i=0;i<n;i++){
        if(b[i]==0){             
            a[m]=i+1;
            b[i]=1;             
            rank(m+1);
            b[i]=0;              
        }
    }
}


int main(){
    scanf("%d",&n);
    rank(0);
    return 0;
}






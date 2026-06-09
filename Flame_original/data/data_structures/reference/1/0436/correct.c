#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int n[300]={0},m[300]={0};

void doit(int *n,int *m,int a,int k){
    int i;
    if(k==a+1){
        for(i=1;i<=a;i++)
            printf("%d ", n[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=a;i++){
        if(m[i]==0){
            m[i]=1;
            n[k]=i;
            doit(n,m,a,k+1);
            m[i]=0;
        }
    }
}

int main(){

    int a;
    scanf("%d", &a);
    if(a==1)
        printf("1");
    else if(a==2)
        printf("1 2\n2 1");
    else if(a==3)
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1");
    else if(a>3)
            doit(n,m,a,1);

	return 0;
}


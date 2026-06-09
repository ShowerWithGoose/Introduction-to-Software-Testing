//
//  main.c
//  1-1
//
//  Created by  on 2022/3/10.
//

#include <stdio.h>
int a[20],c[20],n;
int b[20]={0};
void f(int k){
    if (k==(n+1)) {
        for (int j=1; j<=n; j++) {
            printf("%d ",c[j]);
        }
        printf("\n");
    }
    
    for ( int i=1; i<=n; i++) {
        if (b[i]==0) {
            c[k]=i;
            b[i]=1;
            f(k+1);
            b[i]=0;
        }
    }
}


int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    f(1);
    
    
    return 0;
}




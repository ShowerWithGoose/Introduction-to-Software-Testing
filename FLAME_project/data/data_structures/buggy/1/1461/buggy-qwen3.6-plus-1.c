#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int mark[1005], a[1005];

void f(int k, int n){
    if(k == n){
        
        for(int i = 0; i < n; i++){
            printf("%d", a[i]); // @@ The output format requires integers to be separated by a space. This line prints numbers without spaces. It should be printf("%d ", a[i]); or handled with conditional spacing.
        }
        printf("\n");
        
        return;
        
    }else{
        
        for(int i = 1; i <= n; i++){
            if(mark[i] == 0){
                mark[i] = 1;
                a[k] = i;
                f(k + 1, n);
                mark[i] = 0;
            }
        }
    }
}

int main(){

    int i, n;
    scanf("%d", &n);
    f(0, n);
    
    return 0;

}
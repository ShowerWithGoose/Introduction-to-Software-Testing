#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int a,i,j;
    scanf("%d",&a);
    if(a==1){
        printf("1\n"); // @@ Should be printf("1") without newline to match reference output format
    }
    else if(a==2){
        printf("1 2\n2 1"); // Correct for N=2
    }
    else if(a==3){
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n"); // @@ Trailing newline not present in reference; also lacks handling for N>3
    }
    // @@ Missing handling for N >= 4 (required up to 10). Program is incomplete and only works for N<=3.
    return 0;
}
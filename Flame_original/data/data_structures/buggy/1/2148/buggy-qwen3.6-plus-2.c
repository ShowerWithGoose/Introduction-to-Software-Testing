#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1");
    }
    if(n==2){
        printf("1 2");
        printf("\n");
        printf("2 1");
    }
    if(n==3){
        printf("1 2 3");
        printf("\n");
        printf("1 3 2");
        printf("\n");
        printf("2 1 3");
        printf("\n");
        printf("2 3 1");
        printf("\n");
        printf("3 1 2");
        printf("\n");
        printf("3 2 1");
        printf("\n");
    }
    if(n==4){ // @@ The code only handles N up to 4, but the problem requires handling N up to 10. Hardcoding permutations is not scalable and will produce no output for N=5 to 10. A general algorithm (e.g., backtracking or recursion) is required.
        printf("1 2 3 4");
        printf("\n");
        printf("1 2 4 3");
        printf("\n");
        printf("1 3 2 4");
        printf("\n");
        printf("1 3 4 2");
        printf("\n");
        printf("1 4 2 3");
        printf("\n");
        printf("1 4 3 2");
        printf("\n"); 
        printf("2 1 3 4");
        printf("\n");
        printf("2 1 4 3");
        printf("\n");
        printf("2 3 1 4");
        printf("\n");
        printf("2 3 4 1");
        printf("\n");
        printf("2 4 1 3");
        printf("\n");
        printf("2 4 3 1");
        printf("\n"); 
        printf("3 1 2 4");
        printf("\n");
        printf("3 1 4 2");
        printf("\n");
        printf("3 2 1 4");
        printf("\n");
        printf("3 2 4 1");
        printf("\n");
        printf("3 4 1 2");
        printf("\n");
        printf("3 4 2 1");
        printf("\n"); 
        printf("4 1 2 3");
        printf("\n");
        printf("4 1 3 2");
        printf("\n");
        printf("4 2 1 3");
        printf("\n");
        printf("4 2 3 1");
        printf("\n");
        printf("4 3 1 2");
        printf("\n");
        printf("4 3 2 1");
        printf("\n"); 

    }
}
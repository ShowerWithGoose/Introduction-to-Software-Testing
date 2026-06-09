#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1"); // @@ Missing newline after output; expected output should have a newline after "1"
    }
    if(n==2){
        printf("1 2");
        printf("\n");
        printf("2 1"); // @@ Missing newline after "2 1"; expected output should have a newline after each permutation
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
    if(n==4){
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
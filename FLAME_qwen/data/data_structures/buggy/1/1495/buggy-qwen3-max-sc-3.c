#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int a,i,j;
    scanf("%d",&a);
    if(a==1){
        printf("1\n");
    }
    else if(a==2){
        printf("1 2\n2 1");
    }
    else if(a==3){
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    }
    return 0; // @@ [The program only handles cases for N=1,2,3 but the problem requires handling N up to 10. For N>3, the program produces no output, which is incorrect. Additionally, the error type mentioned is "Compilation Error", but the actual issue is a logical/runtime error due to incomplete implementation. However, given the test environment error "/bin/sh: 1: gcc: not found", that indicates a system setup issue, not code error. But based on problem context, the real bug is missing implementation for N>3.]
}
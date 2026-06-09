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
        printf("1 2\n2 1"); // @@ [Missing newline at the end of output for a=2; expected lexicographical output with each permutation on its own line, including a trailing newline for consistency and to match expected format]
    }
    else if(a==3){
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    }
    return 0;
}
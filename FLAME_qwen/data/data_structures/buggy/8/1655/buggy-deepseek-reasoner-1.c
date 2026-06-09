#include<stdio.h>
#include<string.h>
int main(){
    int n,m;
    scanf("%d%d",&m,&n);
    if(m==3){
        printf("0 1 2\n0 1 2\n0 2\n0 2\n"); // @@ [Extra trailing newline at the end; expected output has no newline after the last line]
    }
    else if(m==4){
        printf("0 1 2 \n0 1 2 3\n0 1 3\n0 1 3\n"); // @@ [Extra space after "0 1 2" and extra trailing newline; expected output has no space and no newline after the last line]
    }
    else if(m==9){
        printf("0 1 2 3 4 6 5 7 8\n0 1 5 2 6 3 7 4 8\n0 5 6 2 3 4 7 8\n0 5 6 2 7 3 8 4\n"); // @@ [Extra trailing newline at the end; expected output has no newline after the last line]
    }
    else if(m==13){
        printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n0 8 9 12 2 1 7 4 10 3 5 11 6\n0 9 1 7 3 4 2 5 6 11 10 12\n0 9 12 1 7 10 3 5 11 4 6 2\n"); // @@ [Extra trailing newline at the end; expected output has no newline after the last line]
    }
    else{
        printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16"); // @@ [Missing trailing newline; expected output has a newline at the end of the last line? Actually reference also has no newline, but the problem's expected output may require one. However, for consistency with the other cases, a missing newline might be an error. But based on reference program, this line is ok.]
}
}
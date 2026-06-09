#include<stdio.h>
#include<ctype.h>
#include<string.h>
char A[100000];

int method(int i){
    if(isdigit(A[i])){
        return 1;
    }else if(islower(A[i])){
        return 2;
    }else if(isupper(A[i])){
        return 3;
    }
}

int main(){

    scanf("%s",A);
    int l = strlen(A),tab;
    for(int i = 0;i < l;i ++){
        if(A[i] == '-'){
            tab = 0;
            if(method(i - 1) == method(i + 1)){
                if(A[i - 1] < A[i + 1]){
                    tab = 1;
                    for(int j = 1;j < A[i + 1] - A[i - 1];j ++){
                        printf("%c",A[i - 1] + j);
                    }
                }
            }
            if(tab == 0){
                printf("-");
            }
        }else{
            printf("%c",A[i]);
        }
    }
    puts("");
}

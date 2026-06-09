#include<stdio.h>
#include<string.h>
#include<ctype.h>
char A[10000];
long long num[10000];
char op[10000];

int main(){

    gets(A);
    long long l = strlen(A),count = 0,c1 = 0,c2 = 0,temp = 0,tab = 0,c22;
    for(int i = 0,j = 0;i < l;){
        if(A[i] == ' '){
            i ++;
            count ++;
        }else{
            A[j ++] = A[i ++];
        }
    }
    A[l - count] = '\0';
    l = strlen(A);
    for(int i = 0;i < l;i ++){
        if(tab == 0){
            if(isdigit(A[i])){
                temp += A[i] - '0';
                tab = 1;
            }
        }else if(tab == 1){
            if(isdigit(A[i])){
                temp *= 10;
                temp += A[i] - '0';
            }else if(A[i] == '='){
                num[c1] = temp;
                tab = 0;
                c1 ++;
                temp = 0;
            }else{
                num[c1] = temp;
                temp = 0;
                op[c2] = A[i];
                tab = 0;
                c1 ++;
                c2 ++;
            }
        }
    }
    for(int i = 0;i < c2;i ++){
        if(op[i] == '*'){
            num[i + 1] = num[i] * num[i + 1];
            num[i] = -1;
        }else if(op[i] == '/'){
            num[i + 1] = num[i] / num[i + 1];
            num[i] = -1;
        }
    }
    for(int i = 0;i < c1;i ++){
        if(num[i] == -1){
            for(int j = i;j < c1;j ++){
                num[j] = num[j + 1];
            }
            c1 --;
            i --;
        }
    }
    c22 = c2;
    for(int i = 0;i < c2;i ++){
        if(op[i] == '*' || op[i] == '/'){
            for(int j = i;j < c2;j ++){
                op[j] = op[j + 1];
            }
            c22 --;
            i --;
        }
    }
    c2 = c22;
    for(int i = 0;i < c2;i ++){
        if(op[i] == '+'){
            num[i + 1] = num[i] + num[i + 1];
        }else if(op[i] == '-'){
            num[i + 1] = num[i] - num[i + 1];
        }
    }
    printf("%lld\n",num[c1 - 1]);
}

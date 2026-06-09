#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[1000000];
int b[1000000];
char c[1000000];
//
//int add(int a, int b){
//    return a+b;
//}
//
//int jian(int a, int b){
//    return a-b;
//}
//
//int power(int a, int b){
//    return a*b;
//}
//
//int chu(int a, int b){
//    return a/b;
//}

int you(char c){
    if(c == '+' || c == '-') return 1;
    else return 2;
}

int main()
{
    gets(a);
    int n = strlen(a);
    int b1 = 0, c1 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= '0' && a[i] <= '9'){
            int t = 0;
            int j;
            for(j = i; a[j] >= '0' && a[j] <= '9'; j++){
                t *= 10;
                t += a[j] - '0';
            }
            i = j-1;
            b[b1++] = t;
        }
        else if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/'){
            if(c1 == 0) c[c1++] = a[i];
            else if(you(c[c1-1]) >= you(a[i])){
                for(; c1 > 0 && you(c[c1-1]) >= you(a[i]); c1--){
                    if(c[c1-1] == '+'){
                        int t;
                        t = b[b1-2] + b[b1-1];
                        b[b1-2] = t;
                        b1--;
                    }
                    else if(c[c1-1] == '-'){
                        int t;
                        t = b[b1-2] - b[b1-1];
                        b[b1-2] = t;
                        b1--;
                    }
                    else if(c[c1-1] == '*'){
                        int t;
                        t = b[b1-2] * b[b1-1];
                        b[b1-2] = t;
                        b1--;
                    }
                    else if(c[c1-1] == '/'){
                        int t;
                        t = b[b1-2] / b[b1-1];
                        b[b1-2] = t;
                        b1--;
                    }
                }
                c[c1++] = a[i];
            }
            else{
                c[c1++] = a[i];
            }
        }
        else if(a[i] == '='){
            for(; c1 > 0; c1--){
                if(c[c1-1] == '+'){
                    int t;
                    t = b[b1-2] + b[b1-1];
                    b[b1-2] = t;
                    b1--;
                }
                else if(c[c1-1] == '-'){
                    int t;
                    t = b[b1-2] - b[b1-1];
                    b[b1-2] = t;
                    b1--;
                }
                else if(c[c1-1] == '*'){
                    int t;
                    t = b[b1-2] * b[b1-1];
                    b[b1-2] = t;
                    b1--;
                }
                else if(c[c1-1] == '/'){
                    int t;
                    t = b[b1-2] / b[b1-1];
                    b[b1-2] = t;
                    b1--;
                }
            }
            printf("%d\n", b[0]);
        }
//        for(int j = 0; j < b1; j++){
//            printf("%d ", b[j]);
//        }
//        printf("\n");
//        for(int j = 0; j < c1; j++){
//            printf("%c ", c[j]);
//        }
//        printf("\n");
    }
    return 0;
}


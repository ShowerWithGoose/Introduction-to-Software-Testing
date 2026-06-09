#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char str[10000], op[10000];
char next;
int pre_num[10000];
int main() {
    char c;
    int num_i=0, op_i=0, op_flag = 0, flag = 0;
    while(scanf("%c", &c)!=EOF){
        if(c == '+'){
            op[op_i++] = '+';
        }else if(c == '-'){
            op[op_i++] = '-';
        }else if(c == '*'){
            op_flag = 1;//³Ë
        }else if(c == '/'){
            op_flag = 2;//³ý
        }else if (isdigit(c)){
            if(op_flag == 0){
                int temp = c-'0';
                scanf("%c", &next);
                while(isdigit(next)){
                    temp *= 10;
                    temp += next-'0';
                    scanf("%c", &next);
                }
                pre_num[num_i++] = temp;
                if(!(isdigit(next)) && next!=' '){
                    if(next == '+'){
                        op[op_i++] = '+';
                    }else if(next == '-'){
                        op[op_i++] = '-';
                    }else if(next == '*'){
                        op_flag = 1;//³Ë
                    }else if(next == '/'){
                        op_flag = 2;//³ý
                    }
                }
            }else if(op_flag == 1){
                int temp = c-'0';
                scanf("%c", &next);
                while(next!=' '){ // @@ Error: The loop condition `next!=' '` incorrectly stops at spaces, but should also stop at operators or end-of-input. This causes multi-digit numbers after multiplication to be read incorrectly, as it may consume the next operator or skip digits.
                    temp *= 10;
                    temp += next-'0';
                    scanf("%c", &next);
                }
                pre_num[num_i-1] *= temp;
                op_flag = 0;
                if(!(isdigit(next)) && next!=' '){
                    if(next == '+'){
                        op[op_i++] = '+';
                    }else if(next == '-'){
                        op[op_i++] = '-';
                    }else if(next == '*'){
                        op_flag = 1;//³Ë
                    }else if(next == '/'){
                        op_flag = 2;//³ý
                    }
                }
            }else{
                int temp = c-'0';
                scanf("%c", &next);
                while(next!=' '){ // @@ Error: Same issue as above; the loop condition `next!=' '` is incorrect for reading multi-digit numbers after division. It should check `isdigit(next)` to properly handle digits and stop at non-digit characters.
                    temp *= 10;
                    temp += next-'0';
                    scanf("%c", &next);
                }
                pre_num[num_i-1] /= temp;
                op_flag = 0;
                if(!(isdigit(next)) && next!=' '){
                    if(next == '+'){
                        op[op_i++] = '+';
                    }else if(next == '-'){
                        op[op_i++] = '-';
                    }else if(next == '*'){
                        op_flag = 1;//³Ë
                    }else if(next == '/'){
                        op_flag = 2;//³ý
                    }
                }
            }
        }
    }
    long long ans = pre_num[0];
    for(int i=0; i<op_i; i++){
        if(op[i] == '+'){
            ans += pre_num[i+1];
        }else{
            ans -= pre_num[i+1];
        }
    }
    printf("%lld", ans);
    return 0;
}
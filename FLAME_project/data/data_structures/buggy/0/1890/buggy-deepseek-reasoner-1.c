#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){ // @@ The linker error "undefined reference to `main'" suggests that the main function definition is missing or misspelled in the actual buggy source code. In the program provided, this line is present, but the error indicates it was not included.
    char s_in[1024] = {};
    char s_out[1024] = {};

    s_out[0] = '\0';
    scanf("%s", s_in);

    int j = 0;

    for (int i = 0; i < strlen(s_in); i++){
        if((s_in[i] == '-') && (i != 0) && (i != (strlen(s_in)-1))){
            if((('0' <= s_in[i-1]) && (s_in[i-1] <= '9') && ('0' <= s_in[i+1]) && (s_in[i+1] <= '9') && (s_in[i-1] < s_in[i+1])) ||
                (('a' <= s_in[i-1]) && (s_in[i-1] <= 'z') && ('a' <= s_in[i+1]) && (s_in[i+1] <= 'z') && (s_in[i-1] < s_in[i+1])) ||
                (('A' <= s_in[i-1]) && (s_in[i-1] <= 'Z') && ('A' <= s_in[i+1]) && (s_in[i+1] <= 'Z') && (s_in[i-1] < s_in[i+1]))
            ){
                for (int k = 1; k < (s_in[i+1] - s_in[i-1]); k++){
                    s_out[j++] = s_in[i-1] + k;
                }
            }
            else{
                s_out[j++] = s_in[i];
            }
        }
        else{
            s_out[j++] = s_in[i];
        }
    }

    printf("%s\n", s_out);

    return 0;
}
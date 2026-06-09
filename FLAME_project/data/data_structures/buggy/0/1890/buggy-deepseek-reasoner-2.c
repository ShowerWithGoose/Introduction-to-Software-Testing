#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){ // @@ No error in this line; linker error might indicate this function is missing in the actual submission.
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
                for (int k = 1; k < (s_in[i+1] - s_in[i-1]); k++){ // @@ Using C99 for-loop declaration; may cause compilation error in C89 mode. Also potential buffer overflow if j reaches 1024.
                    s_out[j++] = s_in[i-1] + k; // @@ Buffer overflow hazard: if j exceeds 1023, this writes out of bounds.
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
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
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
} // @@ [The compilation error "undefined reference to `main'" typically indicates that the linker cannot find the main function. However, this code defines main correctly. The actual issue is likely external (e.g., file not saved properly, incorrect compilation command, or missing standard libraries). But since the problem states there's a bug in the program and given the error message points to linking, one subtle possibility is that the source file might have been compiled without including all necessary parts. However, reviewing the code logic itself, there is no syntax or semantic error causing a compilation failure. Therefore, the provided error is likely not due to the code shown but due to an external build issue. Yet, per instructions, if we must mark a line, the only plausible assumption is that the code might be missing a newline at EOF which some strict compilers/linkers require, though this is rare. Alternatively, the problem may be misattributed. Given constraints, no line in the code actually causes the stated linker error. But to comply with the format, we annotate the last line as a placeholder indicating the error is not in the code logic but possibly in build setup.]
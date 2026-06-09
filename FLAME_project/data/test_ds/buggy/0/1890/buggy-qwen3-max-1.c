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
} @@ [The compilation error "undefined reference to `main'" typically indicates a linking issue, not a problem in the source code itself. However, since the provided source does define main correctly, this error likely stems from an external build/environment issue (e.g., file not saved with .c extension, incorrect compilation command). But per instructions, if we must mark a line, the only plausible assumption is that the program lacks proper linkage setup—yet no line in the code is syntactically wrong. Given the error message shows the linker can't find main, and the code clearly has main, this suggests the actual submitted code might have been empty or miscompiled. Since the provided code is correct, but the error insists on marking a line, the closing brace of main is marked as a proxy for potential missing definition in corrupted submission.]
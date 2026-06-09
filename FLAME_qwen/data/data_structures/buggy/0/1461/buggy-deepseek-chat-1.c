#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char str1[1005], str2[10086];

int main(){
    
    int i, j, l = 0, len = 0;
    char c;
    
    gets(str1); // @@ [gets() is unsafe and may cause buffer overflow; also, it does not handle the case where the input string starts or ends with '-', leading to out-of-bounds access]
    len = strlen(str1);
    
    str2[l] = str1[0]; // @@ [If the input string starts with '-', this will incorrectly copy '-' to str2 without checking, and later loop may access str1[-1] causing undefined behavior]
    l++;
    
    for(i = 1; i < len - 1; i++){ // @@ [The loop condition i < len - 1 skips the last character, but the last character is handled separately; however, if the string ends with '-', the last character is '-' and it will be copied without expansion, which is correct, but the loop may miss cases where '-' is at the end]
        if(str1[i] == '-'){
            if(str1[i + 1] - str1[i - 1] > 0){
                if((str1[i - 1] >= 'a' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z' && str1[i - 1] <= 'z') || (str1[i - 1] >= 'A' && str1[i + 1] >= 'A' && str1[i + 1] <= 'Z' && str1[i - 1] <= 'Z') || (str1[i - 1] >= '0' && str1[i + 1] >= '0' && str1[i + 1] <= '9' && str1[i - 1] <= '9')){
                    j = str1[i + 1] - str1[i - 1];
                    int k;
                    for(k = 1; k < j; k++){
                        str2[l] = str1[i - 1] + k;
                        l++;
                    }
                }
                else{
                    str2[l] = str1[i]; // @@ [When the characters are not of the same type, the '-' should be copied, but l is not incremented here, causing the next character to overwrite this position]
                }
            }
            else{
                str2[l] = str1[i]; // @@ [Same issue: l is not incremented when the condition str1[i+1] - str1[i-1] > 0 is false, leading to overwriting]
            }
        }
        else{
            str2[l] = str1[i];
            l++;
        }
    }
    
    str2[l] = str1[len - 1]; // @@ [If the last character is part of an expansion (e.g., "a-d"), this will incorrectly copy 'd' again after the expanded characters, resulting in duplicate output]
    puts(str2);
    
    return 0;

}
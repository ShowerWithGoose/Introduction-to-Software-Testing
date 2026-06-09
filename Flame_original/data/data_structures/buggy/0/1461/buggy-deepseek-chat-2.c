#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char str1[1005], str2[10086];

int main(){
    
    int i, j, l = 0, len = 0;
    char c;
    
    gets(str1); // @@ [gets() is unsafe and deprecated; use fgets() instead, but this is not the main error]
    len = strlen(str1);
    
    str2[l] = str1[0];
    l++;
    
    for(i = 1; i < len - 1; i++){ // @@ [The loop condition i < len - 1 skips the last character, but the last character is handled later. However, if the string has only one character or the '-' is at the end, this may cause issues. More critically, the logic for handling '-' at position i=1 or i=len-2 may access out-of-bounds indices when checking str1[i-1] or str1[i+1] if the string is short.]
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
                    str2[l] = str1[i]; // @@ [Missing l++ here; when the characters are not of the same type, the '-' should be copied to str2, but l is not incremented, causing subsequent characters to overwrite this position.]
                }
            }
            else{
                str2[l] = str1[i]; // @@ [Missing l++ here; when the character after '-' is not greater than the one before, the '-' should be copied to str2, but l is not incremented, causing subsequent characters to overwrite this position.]
            }
        }
        else{
            str2[l] = str1[i];
            l++;
        }
    }
    
    str2[l] = str1[len - 1];
    puts(str2);
    
    return 0;

}
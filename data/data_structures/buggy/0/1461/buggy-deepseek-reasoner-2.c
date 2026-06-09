#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char str1[1005], str2[10086];

int main(){
    
    int i, j, l = 0, len = 0;
    char c;
    
    gets(str1);@@ // Using gets() is unsafe and deprecated; use fgets or scanf instead.
    len = strlen(str1);
    
    str2[l] = str1[0];@@ // For a single-character input (e.g., "-"), this duplicates the character; should be adjusted.
    l++;
    
    for(i = 1; i < len - 1; i++){
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
                    str2[l] = str1[i];@@ // Missing l++ after writing; causes subsequent writes to overwrite the dash.
                }
            }
            else{
                str2[l] = str1[i];@@ // Missing l++ after writing; causes subsequent writes to overwrite the dash.
            }
        }
        else{
            str2[l] = str1[i];
            l++;
        }
    }
    
    str2[l] = str1[len - 1];@@ // For a single-character input (e.g., "-"), this adds a duplicate character; should be handled.
    puts(str2);
    
    return 0;

}
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char str1[1005], str2[10086];

int main(){
    
    int i, j, l = 0, len = 0;
    char c;
    
    gets(str1);
    len = strlen(str1);
    
    str2[l] = str1[0];
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
                    str2[l] = str1[i]; // @@ [When expansion conditions are not met (e.g., different character types), the '-' should be copied to str2, but l is not incremented here, causing the next character to overwrite this position. Additionally, the '-' is not output in the final result, leading to missing characters.]
                }
            }
            else{
                str2[l] = str1[i]; // @@ [Same issue: when the character after '-' is not greater than the one before, the '-' should be copied, but l is not incremented, causing it to be overwritten and lost.]
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
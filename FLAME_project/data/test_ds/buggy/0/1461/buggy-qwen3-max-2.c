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
                    str2[l] = str1[i]; // @@ [When expansion conditions are not met, the '-' should be appended to output, but the following character (str1[i+1]) is never added in this branch, and l is not incremented here, causing missing '-' in output]
                    l++; // @@ [Missing increment of l after assigning '-', leading to overwriting or omission in output]
                }
            }
            else{
                str2[l] = str1[i]; // @@ [Same issue: '-' is assigned but l is not incremented, so next write may overwrite it or final string becomes incorrect]
                l++; // @@ [Missing increment of l after assigning '-', needed to advance output index]
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
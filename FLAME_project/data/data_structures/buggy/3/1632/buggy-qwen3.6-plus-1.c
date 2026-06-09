#include<stdio.h>
#include<string.h>
int main(){
    char str[110];
    gets(str);
    int length=strlen(str),i,point,flag=0;int end;int record;
    for(i=0;i<length;i++){
        if(str[i]=='.'){
            point=i;
        }
    }if(point==1){
        if(str[point-1]!='0'){
            printf("%s",str); // @@ The output format requires the base to be normalized. For input "9.99", printing the original string "9.99" followed by "e0" results in "9.99e0". However, the problem states that if the base is a decimal, it must have one significant digit before and after the decimal point. While "9.99" has one digit before, the reference logic and standard scientific notation usually imply moving the decimal to after the first non-zero digit. More critically, looking at the buggy output "9.99e0e-49151", there is a second "e" part. This suggests the code falls through or executes extra print statements. Let's look closer. The condition `if(str[point-1]!='0')` is true for '9'. It prints "9.99" then "e0". Then it exits the if-else block? No, the structure is `if (point==1) { if (...) { ... } else { ... } } else { ... }`. So if point==1 and str[0]!='0', it prints "9.99e0". This matches the expected output "9.99e0" partially, but wait. The expected output is `9.99e0`. The buggy output is `9.99e0e-49151`. This implies that after printing "e0", the program continues to execute code that prints another "e...". 
            // Looking at the code structure:
            // if(point==1) {
            //    if(str[point-1]!='0') {
            //       printf("%s", str);
            //       printf("e0");
            //    } else {
            //       ...
            //    }
            //    printf("e%d", -end+point); // <--- THIS LINE IS OUTSIDE THE INNER IF-ELSE BUT INSIDE THE OUTER IF
            //    flag=0;
            // }
            // The line `printf("e%d",-end+point);` is executed regardless of whether the inner if or else branch was taken.
            // In the case of "9.99", the inner `if` branch executes, printing "9.99e0".
            // Then, the code proceeds to `printf("e%d",-end+point);`.
            // The variable `end` was not initialized or assigned in this branch. It contains garbage value (like 49151/2 etc).
            // So it prints "e" followed by garbage calculation.
            // This explains the "e-49151" part.
            // The error is that this print statement should only apply to the `else` branch (where str[0]=='0'), or the logic needs to be restructured so it doesn't run for the non-zero case.
            // Also, the problem description says: "If it’s a decimal, it must have one significant digit before and after the decimal point".
            // For 9.99, the first digit is 9. The rest is .99. Scientific notation is typically $d.dd... \times 10^e$.
            // So 9.99 should be $9.99 \times 10^0$? Or $9.99e0$?
            // The expected output is `9.99e0`.
            // The reference program outputs: `9.` then `99` then `e0`. Result: `9.99e0`.
            // My current analysis: The line `printf("e%d",-end+point);` is incorrectly placed outside the inner `else` block, causing it to execute even when the first digit is non-zero. Additionally, `end` is uninitialized in this path.
            
            printf("e%d",-end+point); // @@ This line executes even when the first digit is non-zero (e.g., 9.99), causing duplicate exponent output and using uninitialized variable 'end'. It should be inside the 'else' block or guarded by a condition.
            flag=0;
        }else{
            for(i=point+1;i<length;i++){
                if(str[i]!='0'){
                record=i;
                break;}
                }
                for(i=record;i<length;i++){
                    printf("%c",str[i]);
                if(i==record){
                    if(i!=length-1){
                    printf(".");
                    }
                end=i;    
                }
            }
            
            }printf("e%d",-end+point);
            flag=0;
        }
    else{
        printf("%c.",str[0]);
        for(i=1;i<length;i++){
            if(i==point){
                continue;
            }printf("%c",str[i]);
        }printf("e%d",point-1);
    }
        
        
    
    
    return 0;
} 
//0.1324001 1.324001e
//1324355.1
//12.354
//8.12
//0.0012 1.2e-3
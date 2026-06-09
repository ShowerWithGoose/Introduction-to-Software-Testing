#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<ctype.h>
#include<string.h>
char a[200];
int main()
{
    scanf("%s",&a);
    if(a[0]>'0'){
        int zheng=0;
    
    for(int i=0;a[i]!='.';i++){
        zheng++;
    }
    printf("%d.",a[0]-'0');
    
    for(int i=1;i!=strlen(a);i++){
        if(a[i]!='.'){
            printf("%d",a[i]-'0');
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){ // @@ The loop condition is incorrect. It checks for null terminator (0) instead of the character '0'. For input "0.9", a[2] is '9', so the loop breaks immediately with j=2, which is correct for finding the first non-zero digit, but the logic for counting leading zeros (xiao) is flawed because it increments xiao only when a[i]==0 (null terminator), which never happens inside the significant digits. More critically, if the input was 0.09, a[2] is '0', the condition a[i]==0 is false (since '0' != 0), so it breaks at j=2. This means it treats '0' as a significant digit start incorrectly or fails to skip leading zeros after decimal point properly depending on interpretation. However, the primary crash/error source for "0.9" is likely below.
            if(a[i]==0){
                xiao++;
            }else{
                j=i;
                break;
            }
        }
        printf("%d",a[j]-'0');
        if(j<strlen(a)-1){
            printf(".");
        }
        for(int i=j+1;i!=strlen(a);i++){
            printf("%d",a[j]-'0'); // @@ Logic error: prints the digit at index j repeatedly instead of the digit at index i. This results in incorrect output format (e.g., printing "99" instead of "9" if there were more digits, or just wrong digits). For "0.9", j=2, strlen(a)=3. Loop runs for i=3? No, i starts at 3, 3!=3 is false. So this loop doesn't run for "0.9". But if input was "0.91", it would print a[2] ('9') again instead of a[3] ('1').
        }
        printf("e-%d",xiao);
    }
    

    return 1;
 }
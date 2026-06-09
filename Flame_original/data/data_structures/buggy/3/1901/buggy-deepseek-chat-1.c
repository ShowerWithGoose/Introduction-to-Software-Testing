#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<ctype.h>
#include<string.h>
char a[200];
int main()
{
    scanf("%s",&a); // @@ The scanf format specifier %s expects a char*, but &a is a pointer to an array (char (*)[200]), causing undefined behavior. Should be scanf("%s", a);
    if(a[0]>'0'){ // @@ This condition only handles numbers where the first digit is greater than '0', but the problem states the first digit can be '0' if there's only one digit before the decimal point. This logic is incomplete and incorrect for cases like "0.123".
        int zheng=0;
    
    for(int i=0;a[i]!='.';i++){ // @@ This loop assumes there is always a decimal point, but the input may be an integer without a decimal point, causing an out-of-bounds access.
        zheng++;
    }
    printf("%d.",a[0]-'0');
    
    for(int i=1;i!=strlen(a);i++){ // @@ Using i!=strlen(a) is inefficient and could cause issues if the string length changes; also, it doesn't skip the decimal point properly in all cases.
        if(a[i]!='.'){
            printf("%d",a[i]-'0');
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){ // @@ This loop starts from index 2, assuming the format is always "0.xxx", but the input could be like "0.0xxx" or other patterns. Also, the loop condition is missing, leading to potential infinite loop if no non-zero digit is found.
            if(a[i]==0){ // @@ Comparing a[i] to integer 0 instead of character '0' is incorrect; it should be a[i]=='0'.
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
        for(int i=j+1;i!=strlen(a);i++){ // @@ This loop incorrectly prints a[j]-'0' for all remaining digits instead of a[i]-'0', causing all digits after the first non-zero to be the same.
            printf("%d",a[j]-'0'); // @@ Should be printf("%d", a[i]-'0');
        }
        printf("e-%d",xiao);
    }
    

    return 1; // @@ The main function should return 0 to indicate successful execution, not 1.
 }
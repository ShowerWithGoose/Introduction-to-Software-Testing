#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<ctype.h>
#include<string.h>
char a[200];
int main()
{
    scanf("%s",&a); // @@ [Using &a with %s is incorrect; should be just 'a' since arrays decay to pointers]
    if(a[0]>'0'){
        int zheng=0;
    
    for(int i=0;a[i]!='.';i++){ // @@ [If input has no decimal point, this loop may run past the end of the string causing undefined behavior]
        zheng++;
    }
    printf("%d.",a[0]-'0'); // @@ [Should print as character '%c' not integer '%d' for the digit itself in scientific notation base]
    
    for(int i=1;i!=strlen(a);i++){ // @@ [Inefficient to call strlen() repeatedly in loop condition; also logic fails if there's no decimal point]
        if(a[i]!='.'){
            printf("%d",a[i]-'0'); // @@ [Same issue: should use %c to output digit characters directly instead of converting to int and back]
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){ // @@ [Infinite loop risk: no bounds check on 'i'; if string ends before non-zero digit found, will access out-of-bounds memory]
            if(a[i]==0){ // @@ [This checks for null terminator but increments xiao incorrectly; should check for '0' characters before first non-zero]
                xiao++;
            }else{
                j=i;
                break;
            }
        }
        printf("%d",a[j]-'0'); // @@ [Again, should use %c to print character directly]
        if(j<strlen(a)-1){
            printf(".");
        }
        for(int i=j+1;i!=strlen(a);i++){ // @@ [Loop prints same digit repeatedly due to using 'a[j]' instead of 'a[i]']
            printf("%d",a[j]-'0'); // @@ [Typo: should be a[i], not a[j]; also should use %c]
        }
        printf("e-%d",xiao);
    }
    

    return 1; // @@ [Should return 0 for successful execution, not 1]
 }
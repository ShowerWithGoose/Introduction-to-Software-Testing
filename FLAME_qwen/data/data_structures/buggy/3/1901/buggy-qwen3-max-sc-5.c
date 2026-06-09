#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<ctype.h>
#include<string.h>
char a[200];
int main()
{
    scanf("%s",&a); // @@ [Using &a with %s is incorrect; 'a' is already a pointer to char array, should be scanf("%s", a);]
    if(a[0]>'0'){
        int zheng=0;
    
    for(int i=0;a[i]!='.';i++){ // @@ [If input has no decimal point, this loop may run past the end of string causing undefined behavior]
        zheng++;
    }
    printf("%d.",a[0]-'0'); // @@ [Should print character directly as %c, not convert to int and print as %d]
    
    for(int i=1;i!=strlen(a);i++){ // @@ [Inefficient to call strlen() repeatedly in loop condition; also logic error when handling decimal point]
        if(a[i]!='.'){
            printf("%d",a[i]-'0'); // @@ [Same issue: should use %c to print character, not convert digit char to int and print as %d]
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){ // @@ [Infinite loop risk: no bounds check on i, may access beyond array if input doesn't have non-zero digit]
            if(a[i]==0){ // @@ [Should compare with '\0' or 0, but logic flawed: skips first zero after "0." incorrectly]
                xiao++;
            }else{
                j=i;
                break;
            }
        }
        printf("%d",a[j]-'0'); // @@ [Again, should print as %c, not convert to int and use %d]
        if(j<strlen(a)-1){
            printf(".");
        }
        for(int i=j+1;i!=strlen(a);i++){ // @@ [Loop condition uses != instead of <, which may never terminate if strlen changes or due to signed/unsigned comparison issues]
            printf("%d",a[j]-'0'); // @@ [Printing a[j] instead of a[i]; also using %d instead of %c]
        }
        printf("e-%d",xiao);
    }
    

    return 1; // @@ [Should return 0 for successful execution, not 1]
 }
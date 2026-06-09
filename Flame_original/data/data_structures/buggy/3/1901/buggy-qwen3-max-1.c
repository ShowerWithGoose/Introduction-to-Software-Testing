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
    
    for(int i=0;a[i]!='.';i++){ // @@ [If input has no decimal point, this loop may run past the string end causing undefined behavior]
        zheng++;
    }
    printf("%d.",a[0]-'0'); // @@ [Should print character directly as %c, not convert to int and use %d]
    
    for(int i=1;i!=strlen(a);i++){ // @@ [Inefficient to call strlen() repeatedly in loop condition; also logic skips '.' but doesn't handle it correctly for scientific notation formatting]
        if(a[i]!='.'){
            printf("%d",a[i]-'0'); // @@ [Same issue: should use %c to print digit characters, not convert to int and use %d]
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){ // @@ [Infinite loop risk if string ends before finding non-zero; also assumes at least two characters before meaningful digit]
            if(a[i]==0){ // @@ [This checks for null terminator but increments xiao incorrectly; logic flawed for counting leading zeros after decimal]
                xiao++;
            }else{
                j=i;
                break;
            }
        }
        printf("%d",a[j]-'0'); // @@ [Again, should use %c instead of converting char to int and using %d]
        if(j<strlen(a)-1){
            printf(".");
        }
        for(int i=j+1;i!=strlen(a);i++){
            printf("%d",a[j]-'0'); // @@ [Bug: prints a[j] repeatedly instead of a[i]; also same %d vs %c issue]
        }
        printf("e-%d",xiao);
    }
    

    return 1; // @@ [Should return 0 for successful execution, not 1]
 }
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
    
    for(int i=0;a[i]!='.';i++){ // @@ [If input has no decimal point, this loop runs past the end of string causing undefined behavior]
        zheng++;
    }
    printf("%d.",a[0]-'0'); // @@ [Should print character directly as '%c', not convert to int and use %d]
    
    for(int i=1;i!=strlen(a);i++){ // @@ [Inefficient to call strlen() repeatedly in loop condition; also logic fails if no '.' exists]
        if(a[i]!='.'){
            printf("%d",a[i]-'0'); // @@ [Same issue: should use %c to print character, not %d after subtracting '0']
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){ // @@ [Infinite loop risk: no bounds check on i; if string ends before non-zero digit found, accesses invalid memory]
            if(a[i]==0){ // @@ [Should compare with '\0' or 0, but logic is flawed: counts zeros incorrectly and doesn't handle end-of-string properly]
                xiao++;
            }else{
                j=i;
                break;
            }
        }
        printf("%d",a[j]-'0'); // @@ [Again, should use %c to output digit character, not %d after conversion]
        if(j<strlen(a)-1){
            printf(".");
        }
        for(int i=j+1;i!=strlen(a);i++){ // @@ [Prints same digit repeatedly: uses a[j] instead of a[i]; also inefficient strlen() in condition]
            printf("%d",a[j]-'0'); // @@ [Critical error: prints a[j] instead of a[i], so repeats first significant digit]
        }
        printf("e-%d",xiao);
    }
    

    return 1; // @@ [Should return 0 for successful execution, not 1]
 }
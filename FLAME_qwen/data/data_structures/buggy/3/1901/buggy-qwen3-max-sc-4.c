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
    printf("%d.",a[0]-'0'); // @@ [Should print character directly as %c or keep as digit but logic inconsistent with problem spec which requires significant digits only]
    
    for(int i=1;i!=strlen(a);i++){ // @@ [Inefficient and potentially unsafe: strlen called repeatedly; also prints all digits including after '.', but problem says no trailing zeros yet code doesn't skip them]
        if(a[i]!='.'){
            printf("%d",a[i]-'0'); // @@ [Same issue: converts char to int then prints as digit, but may include trailing zeros which violates problem constraints]
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){ // @@ [Infinite loop risk: no bounds check on i; if string ends before non-zero digit found, accesses out-of-bounds memory]
            if(a[i]==0){ // @@ [Incorrect condition: should check for '0' character ('0'), not null terminator (0); also logic inverted—should count leading zeros after "0."]
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
        for(int i=j+1;i!=strlen(a);i++){ // @@ [Prints same digit repeatedly: uses a[j] instead of a[i]; typo causes wrong output]
            printf("%d",a[j]-'0'); // @@ [This line uses a[j] instead of a[i], so it repeats the first significant digit instead of printing subsequent digits]
        }
        printf("e-%d",xiao);
    }
    

    return 1; // @@ [main should return 0 for successful execution, not 1]
 }
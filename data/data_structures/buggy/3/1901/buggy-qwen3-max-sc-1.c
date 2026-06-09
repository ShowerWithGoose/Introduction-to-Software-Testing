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
    printf("%d.",a[0]-'0'); // @@ [Should print character directly as %c, not convert to int and print as %d]
    
    for(int i=1;i!=strlen(a);i++){ // @@ [Inefficient and potentially unsafe: strlen called repeatedly in loop condition]
        if(a[i]!='.'){
            printf("%d",a[i]-'0'); // @@ [Same issue: should use %c to print character, not convert digit char to int and print as %d]
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){ // @@ [Infinite loop risk: no bounds check on i, may read beyond array if input format doesn't match expectation]
            if(a[i]==0){ // @@ [Incorrect condition: checking for null terminator as integer 0 instead of '\0'; also logic flawed for counting leading zeros]
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
        for(int i=j+1;i!=strlen(a);i++){ // @@ [Same inefficiency with strlen; also uses wrong variable in printf below]
            printf("%d",a[j]-'0'); // @@ [Critical error: prints a[j] repeatedly instead of a[i]; also wrong format specifier %d]
        }
        printf("e-%d",xiao);
    }
    

    return 1; // @@ [main should return 0 for successful execution, not 1]
 }
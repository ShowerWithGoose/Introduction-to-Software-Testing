#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<ctype.h>
#include<string.h>
char a[200];
int main()
{
    scanf("%s",&a); // @@ The scanf format specifier %s expects a char* pointer, but &a is a pointer to an array (char (*)[200]). This causes undefined behavior. Should be scanf("%s", a) or scanf("%s", &a[0]).
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
        for(int i=2;;i++){
            if(a[i]==0){ // @@ The condition a[i]==0 checks for null terminator, but the loop should check for '0' character (a[i]=='0') to count leading zeros. Also, the loop lacks a proper termination condition; if no non-zero digit is found, it will run out of bounds.
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
            printf("%d",a[j]-'0'); // @@ This prints a[j]-'0' repeatedly instead of a[i]-'0', so it outputs the same digit for all remaining positions instead of the actual digits.
        }
        printf("e-%d",xiao);
    }
    

    return 1; // @@ The main function should return 0 to indicate successful execution, not 1.
 }
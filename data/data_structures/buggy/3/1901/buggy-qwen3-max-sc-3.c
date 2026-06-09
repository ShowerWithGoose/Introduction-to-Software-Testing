#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<ctype.h>
#include<string.h>
char a[200];
int main()
{
    scanf("%s",&a); // @@ [Using &a is incorrect for char arrays; should be just 'a' since it's already a pointer]
    if(a[0]>'0'){
        int zheng=0;
    
    for(int i=0;a[i]!='.';i++){ // @@ [If input has no decimal point, this loop runs past the string end causing undefined behavior]
        zheng++;
    }
    printf("%d.",a[0]-'0'); // @@ [Should print character directly as %c, not convert to int and use %d]
    
    for(int i=1;i!=strlen(a);i++){ // @@ [Inefficient to call strlen() repeatedly in loop condition]
        if(a[i]!='.'){
            printf("%d",a[i]-'0'); // @@ [Same issue: should use %c to print character, not %d after subtracting '0']
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){ // @@ [Infinite loop if string ends before finding non-zero digit; also assumes at least 3 characters]
            if(a[i]==0){ // @@ [Should compare with '\0' instead of 0 for clarity, though equivalent]
                xiao++;
            }else{
                j=i;
                break;
            }
        }
        printf("%d",a[j]-'0'); // @@ [Again, should use %c to print the digit character directly]
        if(j<strlen(a)-1){
            printf(".");
        }
        for(int i=j+1;i!=strlen(a);i++){ // @@ [Loop prints same digit repeatedly due to using 'a[j]' instead of 'a[i]']
            printf("%d",a[j]-'0'); // @@ [Critical error: uses a[j] instead of a[i], so repeats first significant digit]
        }
        printf("e-%d",xiao);
    }
    

    return 1; // @@ [Should return 0 for successful execution, not 1]
 }
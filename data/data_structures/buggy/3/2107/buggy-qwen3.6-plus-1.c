#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char a[200];char c;int i,j;
int main(){
    gets(a); // @@ gets() is deprecated and removed in the C11 standard, causing compilation errors in modern compilers; use fgets() instead.
    if(a[0]=='0'){
        for(i=2;a[i]=='0';i++){ // @@ Missing boundary check a[i]!='\0' may cause out-of-bounds access or infinite loop if the input ends with zeros.
            
        }
        if(a[i+1]=='\0'){
            printf("%c",a[i]);printf("e");
            printf("%d",1-i);
        }
        else{
            printf("%c.",a[i]);
            for(j=i+1;a[j]!='\0';j++){
                printf("%c",a[j]);
            }
            printf("e%d",1-i);
        }
    } // @@ Missing else branch to handle cases where the first digit is not '0', resulting in no output for valid inputs.
    return 0;
}
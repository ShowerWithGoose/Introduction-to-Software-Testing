/*本次作业由本人独立完成，如有抄袭行为，愿承担由此带来的一切不良后果*/ 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()

{
    int i,j,k,m,n;
    char s[200]={0};
    scanf("%s",s);

    for(i=1;s[i]!='\0';i++){
        k=strlen(s);
       if(s[i]=='-'&&((isdigit(s[i-1])&&isdigit(s[i+1]))||(isupper(s[i-1])&&isupper(s[1+1]))||(islower(s[i-1])&&islower(s[i+1])))){ // @@ Typo: s[1+1] should be s[i+1], otherwise the uppercase check incorrectly references a fixed index instead of the character after '-'.
           j=s[i+1]-s[i-1]-2; // @@ Incorrect calculation of the number of characters to insert; should be -1 to correctly account for all intermediate characters between the bounds.
           for(m=1;k-m>=i+1;m++){ // @@ Shifts characters but fails to append a null terminator '\0' at the new end of the string, and k is not updated, causing potential string termination and output errors.
               s[k-m+j]=s[k-m];
           }
        for(n=i;n<=i+j;n++){
            s[n]=s[n-1]+1;
        }
        
        
       
    }
        
    }

    printf("%s",s);
    
    
}
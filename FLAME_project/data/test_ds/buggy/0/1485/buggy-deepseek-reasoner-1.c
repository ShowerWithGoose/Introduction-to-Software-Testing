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
       if(s[i]=='-'&&((isdigit(s[i-1])&&isdigit(s[i+1]))||(isupper(s[i-1])&&isupper(s[1+1]))||(islower(s[i-1])&&islower(s[i+1])))){ // @@ Error: `s[1+1]` should be `s[i+1]`. This typo causes the uppercase condition to always check the third character (index 2) instead of the character after the hyphen, making the condition false for hyphens like 'B-F'.
           j=s[i+1]-s[i-1]-2;
           for(m=1;k-m>=i+1;m++){ // @@ Error: The shifting loop incorrectly calculates indices and may cause out-of-bounds writes. The destination index `k-m+j` can exceed array bounds, and overlapping shifts are not handled properly.
               s[k-m+j]=s[k-m]; // @@ Error: As above, this assignment can write beyond the allocated array size.
           }
        for(n=i;n<=i+j;n++){
            s[n]=s[n-1]+1;
        }
        
        
       
    }
        
    }

    printf("%s",s);
    
    
}
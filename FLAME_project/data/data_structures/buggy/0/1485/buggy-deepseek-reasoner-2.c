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
       if(s[i]=='-'&&((isdigit(s[i-1])&&isdigit(s[i+1]))||(isupper(s[i-1])&&isupper(s[1+1]))||(islower(s[i-1])&&islower(s[i+1])))){ // @@ [Typo: s[1+1] should be s[i+1]; also missing check that s[i-1] < s[i+1] ]
           j=s[i+1]-s[i-1]-2; // @@ [Error: should be -1 to correctly compute number of characters to insert]
           for(m=1;k-m>=i+1;m++){
               s[k-m+j]=s[k-m];
           }
        for(n=i;n<=i+j;n++){
            s[n]=s[n-1]+1;
        }
        
        
       
    }
        
    }

    printf("%s",s);
    
    
}
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
        if(s[i]=='-'&&((isdigit(s[i-1])&&isdigit(s[i+1]))||(isupper(s[i-1])&&isupper(s[1+1]))||(islower(s[i-1])&&islower(s[i+1])))){ // @@ Typo: 's[1+1]' should be 's[i+1]', causing condition to always check s[2] instead of the actual character after '-'. Also missing check that s[i-1] < s[i+1] (required by problem); without this, expansion may occur even when left character is not less than right, leading to negative j and out-of-bounds access.
            j=s[i+1]-s[i-1]-2;
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
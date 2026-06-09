#include <stdio.h>
#include <string.h>
int main(){
    char str[105];
    gets(str);
    int n=strlen(str);
    int j=0,k=0;
    for(int i=0;i<n;i++){
    if(str[i]=='.'){
        j=i;
    }
    }
    if(j==1){
       if(str[0]=='0'){
        while(str[2+k]=='0'){
            k++;
        }
    printf("%c",str[2+k]); // @@ The code prints a decimal point unconditionally after the first significant digit. However, if there are no more significant digits after this one (i.e., it's the last non-zero digit or the rest are zeros which shouldn't be printed as trailing zeros in scientific notation base if it becomes an integer), it should be an integer. Specifically for 0.9, k=0, prints '9', then '.', then loop from 3+0=3 to n=3 (empty). Result "9.e-1". Expected "9e-1". The logic fails to check if there are remaining significant digits to decide between integer and decimal base.
    printf(".");
    for(int i=3+k;i<n;i++){
        printf("%c",str[i]);
    }printf("e-%d",k+1);
       }
    else printf("%s",str);           
    }
    else {
        printf("%c",str[0]);
        printf(".");
        for(int i=1;i<n;i++){
            if(str[i]!='.')
          printf("%c",str[i]);
    }printf("e%d",j-1);
        
    }
    
    return 0;
}
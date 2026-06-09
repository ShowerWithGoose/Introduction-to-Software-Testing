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
    printf("%c",str[2+k]); // @@ The code prints a decimal point unconditionally after the first significant digit. However, if there are no digits following this significant digit (or they are all trailing zeros which shouldn't exist per problem statement but logically if it's the last digit), it should be an integer. Specifically for input "0.9", k becomes 0, str[2] is '9'. It prints '9', then '.', then loop from 3 to n (empty). Result "9.e-1". Expected "9e-1". The decimal point should only be printed if there are subsequent significant digits.
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
#include <stdio.h>
#include <string.h>
int main(){
    char str[105];
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers.]
    int n=strlen(str);
    int j=0,k=0;
    for(int i=0;i<n;i++){
    if(str[i]=='.'){
        j=i;
    }
    }
    if(j==1){
       if(str[0]=='0'){
        while(str[2+k]=='0'){ // @@ [If all digits after the decimal point are zero (though problem states no trailing zeros, but leading zeros possible), this loop may run out of bounds when 2+k >= n, causing undefined behavior or incorrect output. However, primary error is use of 'gets'.]
            k++;
        }
    printf("%c",str[2+k]);
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
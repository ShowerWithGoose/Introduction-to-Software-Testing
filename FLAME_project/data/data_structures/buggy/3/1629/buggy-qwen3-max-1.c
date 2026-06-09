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
    printf("%c",str[2+k]);
    printf("."); // @@ [When there are no digits after the printed digit (i.e., only one significant digit), the decimal point should not be printed. For input "0.9", output should be "9e-1", not "9.e-1".]
    for(int i=3+k;i<n;i++){
        printf("%c",str[i]);
    }printf("e-%d",k+1);
       }
    else printf("%s",str);           
    }
    else {
        printf("%c",str[0]);
        printf("."); // @@ [Similarly, if the number has only one significant digit in the base (e.g., "5.0" becomes "5e0"), the decimal point should not be printed. However, this case may not trigger with given constraints, but the logic is flawed for single-digit mantissa.]
        for(int i=1;i<n;i++){
            if(str[i]!='.')
          printf("%c",str[i]);
    }printf("e%d",j-1);
        
    }
    
    return 0;
}
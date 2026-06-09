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
    printf("."); // @@ [Unconditionally prints a decimal point even when there are no digits after it, leading to incorrect format like "9." instead of "9"]
    for(int i=3+k;i<n;i++){
        printf("%c",str[i]);
    }printf("e-%d",k+1);
       }
    else printf("%s",str);           
    }
    else {
        printf("%c",str[0]);
        printf("."); // @@ [Unconditionally prints a decimal point even when the normalized form should be an integer (only one significant digit), e.g., "5" not "5."]
        for(int i=1;i<n;i++){
            if(str[i]!='.')
          printf("%c",str[i]);
    }printf("e%d",j-1);
        
    }
    
    return 0;
}
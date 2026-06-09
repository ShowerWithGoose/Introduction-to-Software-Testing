#include <stdio.h>
#include <string.h>
int main(){
    char str[105];
    gets(str); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in modern C standards (C11 onwards), 'gets' has been removed, leading to compilation error if compiler adheres strictly to standard]
    int n=strlen(str);
    int j=0,k=0;
    for(int i=0;i<n;i++){
    if(str[i]=='.'){
        j=i;
    }
    }
    if(j==1){
       if(str[0]=='0'){
        while(str[2+k]=='0'){ // @@ [Potential out-of-bounds access if input is "0.0" or similar with insufficient digits after decimal; however, primary issue remains 'gets']
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
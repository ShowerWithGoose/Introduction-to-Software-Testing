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
    printf(".");
    for(int i=3+k;i<n;i++){
        printf("%c",str[i]);
    }printf("e-%d",k+1);
       }
    else printf("%s",str); // @@ Missing braces: The else clause is not properly associated with the inner if. The code structure implies the else belongs to the outer if(j==1), but due to missing braces, it actually belongs to the inner if(str[0]=='0'). This causes incorrect logic for cases where j==1 and str[0]!='0'.           
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
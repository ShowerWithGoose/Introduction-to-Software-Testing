#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8
char str[1001];
int main(){
    fgets(str,1000,stdin);
    int count=0,n=0,l=strlen(str);
    for(int i=0;i<l-1;i++){ // @@ C99-style declaration may cause compilation error under C89 standard (variable declaration inside for loop)
        if('0'==str[i])
        continue;
        if(str[i]!='0'&&str[i]!='.'){
            if(n!=0)
            continue;
            n=i+1;
            if('0'==str[0])
            n=i-1;
        }
        if('.'==str[i])
        count=i-1;
    }
    if('0'==str[0]){
        if(n+2>=l-1)
        printf("%c",str[n+1]);
        for(int i=n+2;i<l-1;i++){ // @@ C99-style declaration (same as above)
            printf("%c",str[i]);
        }
        printf("e-%d",abs(n-count));
    }
    if(str[0]!='0'){
        printf("%c.",str[n-1]);
        for(int i=n;i<l-1;i++){ // @@ C99-style declaration (same as above)
            if('.'==str[i])
            continue;
            printf("%c",str[i]);
        }
        printf("e%d",abs(n-count-1));
    }
return 0;
}
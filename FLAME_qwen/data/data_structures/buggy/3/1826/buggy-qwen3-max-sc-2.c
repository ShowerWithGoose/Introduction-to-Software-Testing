#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8
char str[1001];
int main(){
    fgets(str,1000,stdin);
    int count=0,n=0,l=strlen(str);
    for(int i=0;i<l-1;i++){
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
        printf("%c",str[n+1]); @@ [When n+2 >= l-1, only the single digit is printed without decimal point, but the loop below still runs and prints extra digits; also, missing else leads to always executing the for-loop even when it shouldn't]
        for(int i=n+2;i<l-1;i++){
            printf("%c",str[i]);
        }
        printf("e-%d",abs(n-count));
    }
    if(str[0]!='0'){ @@ [Using a second independent if instead of else-if causes both blocks to potentially execute if input starts with '0' due to logic errors in setting n and count, leading to duplicate or incorrect output]
        printf("%c.",str[n-1]);
        for(int i=n;i<l-1;i++){
            if('.'==str[i])
            continue;
            printf("%c",str[i]);
        }
        printf("e%d",abs(n-count-1));
    }
return 0;
}
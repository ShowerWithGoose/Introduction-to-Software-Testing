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
        printf("%c",str[n+1]); // @@ [Missing 'else' causes both branches to execute when input starts with '0'; also, if condition is true, the following loop runs anyway, leading to incorrect output]
        for(int i=n+2;i<l-1;i++){ // @@ [This loop runs regardless of the preceding if condition, causing extra digits to be printed even when they shouldn't be]
            printf("%c",str[i]);
        }
        printf("e-%d",abs(n-count));
    }
    if(str[0]!='0'){ // @@ [Using a separate 'if' instead of 'else if' causes both blocks to potentially execute, leading to double output for numbers not starting with '0']
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
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[100000];
    int j=0;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause buffer overflow. Also, in some environments, `gets` is not available, leading to compilation error.]
    int l=strlen(s);
    printf("%c",s[0]);
    for(int i=1;i<l;i++){
        if(s[i]=='-'){
            if(s[i-1]>=48&&s[i-1]<=57&&s[i+1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            else printf("%c",s[i]); // @@ [This `else` only pairs with the last `if`, not all three. If any of the first two `if`s match but the third doesn't, it will incorrectly print '-'. Also, when a valid expansion occurs, the code increments `i` but then continues to check subsequent `if`s or the `else`, which can lead to double output or incorrect behavior.]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}
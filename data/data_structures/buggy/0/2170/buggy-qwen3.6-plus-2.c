#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[100000];
    int j=0;
    gets(s);
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
            if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) @@ Should be 'else if' to form a mutually exclusive conditional chain; otherwise, after a successful expansion and 'i++', subsequent conditions are incorrectly evaluated, leading to duplicate output or out-of-bounds access.
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) @@ Should be 'else if' for the same reason; using independent 'if' statements causes logical errors when multiple conditions are checked sequentially after modifying the loop index.
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            else printf("%c",s[i]); @@ This 'else' is only bound to the last 'if' statement. It should be part of an 'if-else if-else' chain to correctly handle cases where no expansion condition is met, preventing unintended printing of characters after a successful expansion.
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}
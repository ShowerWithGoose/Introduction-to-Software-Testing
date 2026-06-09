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
            if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ This should be else if to avoid multiple conditions being checked when the first if is true. Without else if, after the first if increments i, the second if may access out-of-bounds or incorrect characters.
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ This should be else if for the same reason as above. Without else if, after a successful expansion, the loop may incorrectly process the next character as a dash or cause out-of-bounds access.
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            else printf("%c",s[i]);
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}
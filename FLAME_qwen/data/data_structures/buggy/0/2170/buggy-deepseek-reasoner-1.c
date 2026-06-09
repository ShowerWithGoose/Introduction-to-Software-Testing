#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[100000];
    int j=0;
    gets(s);
    int l=strlen(s);
    printf("%c",s[0]); // @@ [Printing first character unconditionally may cause issues if string is empty or the first character is part of an expansion; also no check for empty string]
    for(int i=1;i<l;i++){
        if(s[i]=='-'){
            if(s[i-1]>=48&&s[i-1]<=57&&s[i+1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++) // @@ [Loop condition includes the character after '-', causing duplicate printing; should be j <= s[i+1]-2 or similar]
                printf("%c",j+1);
                i++; // @@ [Stops the loop from processing the character after '-', causing missing output]
            }
            if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ [Should be else if to avoid evaluating after previous true condition, which would use incorrect indices due to i++]
            {
                for(j=s[i-1];j<s[i+1];j++) // @@ [Loop condition includes the character after '-', causing duplicate printing]
                printf("%c",j+1);
                i++; // @@ [Stops the loop from processing the character after '-', causing missing output]
            }
            if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ [Should be else if to avoid evaluating after previous true condition]
            {
                for(j=s[i-1];j<s[i+1];j++) // @@ [Loop condition includes the character after '-', causing duplicate printing]
                printf("%c",j+1);
                i++; // @@ [Stops the loop from processing the character after '-', causing missing output]
            }
            else printf("%c",s[i]); // @@ [This else is attached only to the third if; if the first or second if was true, the else will still execute (since third if is false) and print the dash incorrectly]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ Error: The condition should check that both characters are uppercase letters, but it only checks that s[i] is uppercase and s[i+2] is less than or equal to 'Z', which could include lowercase letters or digits. It should be: (s[i]>='A' && s[i]<='Z') && (s[i+2]>='A' && s[i+2]<='Z')
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ Error: Modifying the loop variable i inside the for loop condition and body causes undefined behavior and incorrect iteration. The loop should use a separate variable for the expansion, not modify i or s[i].
                    printf("%c",s[i]);}i=i+1; // @@ Error: i=i+1 is intended to skip the '-' character, but due to the for loop increment, this may skip an extra character. Also, the for loop modifies s[i], corrupting the string.
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ Error: Same issue as above - condition should check both characters are digits: (s[i]>='0' && s[i]<='9') && (s[i+2]>='0' && s[i+2]<='9')
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ Error: Same issue with modifying i and s[i] in the loop.
                    printf("%c",s[i]);}i=i+1; // @@ Error: Same issue with i=i+1.
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ Error: Same issue - condition should check both characters are lowercase: (s[i]>='a' && s[i]<='z') && (s[i+2]>='a' && s[i+2]<='z')
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ Error: Same issue with modifying i and s[i] in the loop.
                    printf("%c",s[i]);}i=i+1; // @@ Error: Same issue with i=i+1.
            }
            else{
            printf("%c", s[i]);    }
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}
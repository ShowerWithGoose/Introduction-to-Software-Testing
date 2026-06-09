#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){ // @@ the condition does not ensure that s[i] and s[i+2] are of the same type; also using strlen in loop is inefficient but not critical
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ missing check for same character category (lowercase, uppercase, digit)
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ incorrect range check; should be s[i]>='A' && s[i]<='Z' && s[i+2]>='A' && s[i+2]<='Z'
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ loop does not include the endpoint character; also modifies s[i] unnecessarily
                    printf("%c",s[i]);}i=i+1; // @@ the increment of i here is premature; causes subsequent conditions to check wrong indices and print the dash via else
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ incorrect range check; should be s[i]>='0' && s[i]<='9' && s[i+2]>='0' && s[i+2]<='9'
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ loop does not include endpoint
                    printf("%c",s[i]);}i=i+1; // @@ premature increment
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ incorrect range check; should be s[i]>='a' && s[i]<='z' && s[i+2]>='a' && s[i+2]<='z'
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ loop does not include endpoint
                    printf("%c",s[i]);}i=i+1; // @@ premature increment
            }
            else{ // @@ this else is attached only to the last if, but due to sequential ifs, it executes when the third if is false (e.g., for uppercase or digit expansions) and prints the current s[i] (which after premature increment is the dash)
            printf("%c", s[i]);    }
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}
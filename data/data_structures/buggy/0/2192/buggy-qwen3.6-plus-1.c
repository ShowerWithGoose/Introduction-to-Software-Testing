#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s); // @@ [Compilation Error] 'gets' is removed in the C11 standard and causes compilation failure in strict environments; use 'fgets' instead.
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ [Logical Error] Accesses s[i+1] and s[i+2] without bounds checking, causing out-of-bounds read when i is near the end of the string.
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Logical Error] Fails to verify both characters are uppercase; only checks lower bound for s[i] and upper bound for s[i+2].
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Logical/Semantic Error] 'i' in initialization is a no-op; modifying s[i] directly corrupts the original string and breaks loop logic.
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Logical Error] Fails to verify both characters are digits; same boundary check flaw as above.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Logical/Semantic Error] Modifying s[i] directly corrupts the string and causes incorrect expansion behavior.
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Logical Error] Fails to verify both characters are lowercase; same boundary check flaw as above.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Logical/Semantic Error] Modifying s[i] directly corrupts the string and causes incorrect expansion behavior.
                    printf("%c",s[i]);}i=i+1;
            }
            else{ // @@ [Logical Error] This 'else' only pairs with the lowercase 'if', causing duplicate output for uppercase/digit cases that already executed their blocks.
            printf("%c", s[i]);    }
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}
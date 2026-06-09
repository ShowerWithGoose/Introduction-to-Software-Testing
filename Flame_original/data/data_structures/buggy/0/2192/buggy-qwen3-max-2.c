#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ [Potential out-of-bounds access: when i is near the end of string, s[i+2] may read beyond null terminator]
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Incorrect condition: should check both ends are uppercase, but only checks lower bound >= 'A' and upper bound <= 'Z'; e.g., 'a'-'Z' would incorrectly pass if 'a'<'Z']
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Modifying loop variable 'i' inside loop causes unpredictable iteration; also modifies input string during traversal]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Same issue: incorrect range validation; e.g., 'A'-'5' might pass if 'A' >= '0' and '5' <= '9', which is false but logic is flawed anyway]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Same modification of loop variable 'i' leading to skipped characters or infinite loops]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Same incorrect validation and loop variable modification issues]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            else{
            printf("%c", s[i]);    }
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}
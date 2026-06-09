#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
char s[100];
gets(s);
int l=strlen(s);
int k=0;
for(int i=0;i<l;i++){
    if(s[i]=='-'&&i>=1&&i<=(l-2)){
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){ // @@ [The condition checks only the lower bound for s[i-1] and upper bound for s[i+1], but does not ensure both are digits. For example, s[i-1]='a' (>= '0') and s[i+1]='5' (<= '9') would incorrectly pass. Both characters must be in the same category.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ [Same issue: s[i-1] could be uppercase or digit (still >= 'a' is false, but logic flawed). Actually, this condition fails to check that s[i-1] <= 'z' and s[i+1] >= 'a'. So if s[i-1]='Z' (which is < 'a') it won't trigger, but if s[i-1]='{' (ASCII > 'z') it wouldn't either. However, the real problem is missing full range validation: both ends must be in [a-z], not just s[i-1] >= 'a' and s[i+1] <= 'z'. For instance, s[i-1]='z' and s[i+1]='a' would not satisfy s[i-1] < s[i+1], but a case like s[i-1]='0' and s[i+1]='z' would have s[i-1] >= 'a' false, so maybe not triggered. However, the critical flaw is that the conditions do not verify that BOTH characters belong to the same valid set. For example, 'B' (>= 'A') and 'e' (<= 'z') — but they are different cases — this input "B-e" should NOT expand, but current logic doesn't catch mixed case because it checks lowercase and uppercase separately without ensuring both ends match the same group. However, in this specific test case "B-e", the first char 'B' is uppercase, second 'e' is lowercase. The uppercase condition: s[i-1]='B' >= 'A' true, but s[i+1]='e' <= 'Z'? No, 'e' > 'Z', so uppercase block skipped. Lowercase block: s[i-1]='B' >= 'a'? No. Digit block: no. So it falls through and prints '-' via else. But wait — the output is "Be", meaning the '-' was skipped and not printed. Why? Because when s[i]=='-' and the conditions fail, the code does NOT print the '-', since the else clause only runs when the outer if fails. But here, the outer if (s[i]=='-' && i in range) is TRUE, so it enters the if-block, checks three conditions (all false), and then does nothing — so the '-' is never printed. That's the real bug.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ [Same category issue: doesn't ensure both are uppercase. Also, even if fixed, the main problem is that when none of the three if blocks execute, the '-' character is omitted entirely because there's no else inside the outer if to print it.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
    }
    else{printf("%c",s[i]); // @@ [This else only runs when s[i] is not '-', or i is at boundary. But when s[i] is '-' and in valid position but expansion conditions fail (like "B-e"), the code enters the outer if, skips all inner ifs, and never prints the '-'. Thus, the '-' is lost, leading to "Be" instead of "B-e".]
    }    
}
return 0;
}
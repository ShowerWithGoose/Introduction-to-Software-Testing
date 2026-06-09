#include<stdio.h>
int main(){
    char s[101]="\0";
    fgets(s,101,stdin);
    int i;
    if(s[0]=='0'){
        i=2;
        while(s[i]=='0')
        i++;
        
        if(s[i+1]!='\0'){
            printf("%c.%se-%d",s[i],&s[i+1],i-1);
        }
        else
        printf("%ce-%d",s[i],i-1); @@ [When the input is "0.1", i becomes 2, s[i] is '1', but s[i+1] is '\0', so it prints "1e-1", which is correct. However, if input is "0.0", the loop exits at i=2 (s[2]=='0'), then i increments until non-zero, but there is no non-zero digit — this leads to reading beyond valid digits. Also, more critically: if the number is like "0.0010", the code assumes all trailing digits are significant and prints them, but problem states "no trailing zeros after decimal", so input won't have that. Bigger issue: when input is "0.10", which shouldn't happen per problem, but assuming valid input, the real bug is in exponent calculation. For "0.001", i starts at 2, skips two '0's → i=4, then prints s[4]='1', exponent i-1=3 → "1e-3" correct. BUT: what if input is "0.0"? The problem says "all digits are significant" and "has digits before and after decimal", so "0.0" is invalid input. However, the critical error is: if the first non-zero digit is at position i, the number of leading zeros after decimal is (i - 2), so exponent should be -(i - 1). Wait: "0.001": positions: s[0]='0', s[1]='.', s[2]='0', s[3]='0', s[4]='1'. i starts at 2, while(s[i]=='0') → i=4. Then exponent = i - 1 = 3 → e-3, correct. So logic seems okay for zero case. Now look at non-zero case.]

        else
        printf("%ce-%d",s[i],i-1);
    }
    else{
        if(s[1]!='.'){ @@ [This condition checks if second character is not '.', meaning there are multiple digits before decimal, e.g., "123.45". But what if input is "1.23"? Then s[1]=='.', so it goes to else and prints "1.23e0" — but expected is "1.23e0"? Wait, problem says: if only one digit before decimal, it can be 0; otherwise first digit non-zero. So "1.23" is valid. Output should be "1.23e0"? But scientific notation usually normalizes to one non-zero digit before decimal. Problem says: base must have one significant digit before decimal (non-zero) and possibly after. So "1.23" should become "1.23e0"? Actually, no: scientific notation requires exactly one non-zero digit before decimal. So "123.45" → "1.2345e2", "1.23" → "1.23e0" is acceptable per problem? Let's read: "If it’s a decimal, it must have one significant digit before and after the decimal point" — wait, that wording is confusing. Actually, standard scientific notation: one non-zero digit before decimal, then rest after. So "1.23" is already normalized → "1.23e0". But the problem says: "the digit before the decimal point is non-zero" — yes, 1 is non-zero. And "no trailing zeros after decimal" — given. So output "1.23e0" is correct. However, the code in else branch: if s[1]=='.', it prints "%se0",&s[0] → e.g., "1.23e0". But &s[0] is "1.23\n" because fgets includes newline! So output becomes "1.23\n" + "e0" → "1.23\ne0", which is wrong. Similarly, in other branches, &s[i+1] may include newline. This is the critical bug: fgets reads newline into s, so string ends with '\n', not just '\0'. Thus, when printing &s[i+1], it includes '\n' and then garbage or '\0', but printf stops at '\0', but the '\n' is printed as part of mantissa. For example, input "1.23\n", s = "1.23\n\0...". In else branch, s[1]=='.', so prints &s[0] → "1.23\n", so output "1.23\ne0", which is invalid. Similarly, in zero case: input "0.001\n", s[5]='\n', so &s[i+1] when i=4 → &s[5] = "\n", so prints "1.\ne-3" or if no decimal part, "1e-3" but only if s[i+1]=='\0' — but s[i+1] is '\n', not '\0', so it goes into if(s[i+1]!='\0') and prints "1.\ne-3". So the core error is not stripping the newline from fgets input.]
            i=1;
            while(s[i]!='.'){
                i++;
            }
            int k=i;
            while(s[i]!='\0'){
                s[i]=s[i+1];
                i++;
            }
            printf("%c.%se%d",s[0],&s[1],k-1);
        }
        else{
            printf("%se0",&s[0]); @@ [As explained, &s[0] includes the newline character read by fgets, so output contains an embedded newline, making it invalid scientific notation.]
        }
    }
    return 0;
}
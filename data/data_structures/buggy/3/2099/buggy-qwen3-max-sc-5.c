#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers.]
    int len=strlen(s);
    if(s[0]>'0'){
        if(s[1]=='.'){
            for(int i=0;i<len;i++) printf("%c",s[i]);
            printf("e0");
        }
        else if(s[0]>'0'&&s[1]!='.'){ // @@ [This condition is redundant because it's already inside 'if(s[0] > '0')'; also, this branch assumes there is a decimal point later, but input may not have one, leading to undefined behavior in the while loop.]
            int tmp=0;
            while(s[1+tmp]!='.') tmp++; // @@ [If the input has no decimal point (e.g., "123"), this loop will read beyond the string bounds, causing undefined behavior.]
            for(int i=0;i<len;i++){
                if(s[i]!='.') printf("%c",s[i]);
            }
            printf("e%d",tmp);
        }
    }
    else{
        int tmp=0;
        for(int i=0;i<len;i++){
            if(s[i]>'0'&&s[i]!='.'){ // @@ [This skips over '0' digits correctly, but if the number is like "0.000", it may not find any digit > '0', leaving 'tmp' uninitialized in logic and causing incorrect output. Also, the problem states there are no trailing zeros after decimal, but leading zeros before significant digit must be handled carefully.]
                printf("%c",s[i]);
                tmp=i;
                if(s[tmp+1]!='\0') printf(".");
                break;
            }
        }
        for(int j=tmp+1;j<len;j++) printf("%c",s[j]); // @@ [If no significant digit was found (e.g., input "0.0" which shouldn't happen per problem, but robustness fails), this loop may print garbage or incorrect digits. Also, if the significant digit is the last character, printing '.' earlier is wrong.]
        printf("e-%d",tmp-1); // @@ [Exponent calculation is incorrect: for "0.001", first non-zero at index 3 ('1'), exponent should be -3, but tmp=3 → e-2, which is wrong. Correct exponent is -(position_after_decimal_of_first_nonzero) = -(tmp - 1 - 1) = -(tmp - 2)? Actually, for "0.001", indices: s[0]='0', s[1]='.', s[2]='0', s[3]='0', s[4]='1' → tmp=4, exponent should be -4? Wait: 0.001 = 1e-3. Position of '1' is index 4. Number of zeros after decimal before '1' is 2, so exponent = -3. Formula: exponent = -( (tmp - 2) + 1 ) = -(tmp -1). But here it prints e-(tmp-1) → e-3 when tmp=4 → correct? Wait: tmp=4 → e-3 → yes. But if input is "0.1", tmp=2 → e-1 → correct. So maybe exponent is correct. However, the earlier logic prints '.' even when there are no digits after, violating output format.]
    }
    return 0;
}
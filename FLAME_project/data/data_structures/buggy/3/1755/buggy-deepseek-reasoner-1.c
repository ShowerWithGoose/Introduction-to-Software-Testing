#include<stdio.h>
int main(){
    char s[101]="\0";
    fgets(s,101,stdin); // @@ fgets includes trailing newline from input, which will be treated as part of the number, causing incorrect output (e.g., extra newline in printed base or exponent misalignment). The problem expects no newline in the string; scanf should be used instead.
    int i;
    if(s[0]=='0'){
        i=2;
        while(s[i]=='0')
        i++;
        
        if(s[i+1]!='\0'){
            printf("%c.%se-%d",s[i],&s[i+1],i-1);
        }
        else
        printf("%ce-%d",s[i],i-1);
    }
    else{
        if(s[1]!='.'){
        i=1;
        while(s[i]!='.'){
            i++;
        }
        int k=i;
        while(s[i]!='\0'){ // @@ This loop shifts characters left to remove the decimal point, but it overwrites digits incorrectly because it moves from left to right, causing loss of digits. For example, for "123.456", after shifting, the result becomes "12346" instead of "123456". Should shift from right to left or use a temporary buffer.
            s[i]=s[i+1];
            i++;
        }
        printf("%c.%se%d",s[0],&s[1],k-1);
        }
        else{
            printf("%se0",&s[0]); // @@ This includes the entire string (including any trailing newline from fgets) as the base, which is incorrect. Additionally, the base should be printed as a single digit before the decimal point, not the full string.
        }
    }
    return 0;
}
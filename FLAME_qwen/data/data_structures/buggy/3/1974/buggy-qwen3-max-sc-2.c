#include <stdio.h>
#define sf scanf
#define pf printf
#define ll long long 
#include <math.h>
#include <string.h>
#include <stdlib.h> 
int main(){
    char c[105];
    char cc[105];
    gets(c); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers.]
    int a,b,d=0,e=0,f,g,h,i,j;
    if(c[1]=='.'&&c[0]=='0'){
        for(b=2;b<strlen(c);b++){
            if(c[b]=='0'){
                d++;
            }}
            
    pf("%c",c[2]); // @@ [If the input is "0.0", then c[2] is '0', but if the input is "0.00...0" with all zeros after decimal, this accesses beyond significant digits or assumes at least one non-zero digit exists, which violates problem constraints. However, more critically, if the input is "0.1", c[2] is '1' — okay, but if input length is exactly 3 like "0.1", then c[3] is '\0'. But the real issue here is that the code assumes there's always a non-zero digit starting at c[2], which may not be true if input is "0.0" (though problem states all digits are significant and no trailing zeros, so "0.0" shouldn't occur). Still, logic flaw: 'd' counts leading zeros after "0.", but exponent should be -(number of leading zeros + 1), yet output uses c[2] unconditionally — if input is "0.001", c[2] is '0', which is wrong. So this line prints a zero as the first significant digit, violating scientific notation rules.]
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);}
    else{pf("%s",&c[3]); // @@ [When c[3] is '\0', printing &c[3] prints an empty string, which is okay, but the preceding 'else' block prints nothing after the digit, which is correct only if there are no more digits. However, the bigger issue is that the first significant digit is taken as c[2], which may be '0' if there are multiple leading zeros (e.g., "0.001" → c[2]='0'), which is invalid in scientific notation. The program should find the first non-zero digit after the decimal, not assume it's at index 2.]
    
    }pf("e-%d",d+1); // @@ [The exponent calculation is incorrect. For "0.001", d=2 (two leading zeros after decimal before '1'), so exponent should be -3, but d+1=3 → e-3 is correct. However, because the first digit printed is c[2] (which is '0' in "0.001"), the base is wrong. So while exponent might be right in some cases, the base is wrong due to using fixed index 2 instead of locating first non-zero digit.]
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]); // @@ [This copies from c[1] to end into cc, including the decimal point. Then later, when printing cc[i] only if not '.', it skips the decimal. However, if the original number has no decimal point (which shouldn't happen per problem, but code assumes there is one), this fails. Also, if the number is like "123.45", then cc becomes "23.45", and printing non-'.' chars gives "2345", so output becomes "1.2345e2", which is correct. But what if input is "5"? Problem states input has digits before and after decimal point, so this case shouldn't occur. However, the main bug is in the 'if' branch above, not here. But note: the loop to find '.' may run past the string if there's no '.', leading to undefined behavior. Problem says input has decimal point, so maybe okay. Still, safer to ensure '.' exists.]
    pf("%c.",c[0]);
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1);
}
    return 0;
}
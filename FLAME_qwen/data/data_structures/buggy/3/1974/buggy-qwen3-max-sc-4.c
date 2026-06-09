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
    gets(c); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers.]
    int a,b,d=0,e=0,f,g,h,i,j;
    if(c[1]=='.'&&c[0]=='0'){
        for(b=2;b<strlen(c);b++){
            if(c[b]=='0'){
                d++;
            }}
            
    pf("%c",c[2]); // @@ [If the input is "0.0", then c[2] is '0', but if the input is "0.000...", this prints '0' as the significant digit, which violates the requirement that the base must have a non-zero digit before the decimal point. Also, if the input has only one zero after decimal (e.g., "0.0"), c[2] may be '\0', leading to undefined behavior.]
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);}
    else{pf("%s",&c[3]); // @@ [Printing &c[3] when c[3] is '\0' results in printing an empty string, which is okay, but the logic fails to handle cases where trailing zeros are absent per problem statement; more critically, this branch doesn't account for skipping leading zeros correctly.]
    
    }pf("e-%d",d+1); // @@ [The exponent calculation is incorrect. For example, input "0.001" should yield exponent -3, but d counts two leading zeros after decimal (positions 2 and 3), so d=2, and e-3 is printed as e-3? Actually d+1=3 → e-3, which seems correct, but if input is "0.1", d=0 → e-1, which is wrong because "0.1" = 1e-1 is correct. However, the real issue is that d counts ALL zeros from position 2 onward until a non-zero, but the loop breaks only after counting all leading zeros? No—it counts every zero, not just leading ones. So for "0.010", d=2 (counts both zeros), but should only count leading zeros before first non-zero. This leads to wrong exponent.]
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]); // @@ [This copies from c[1] to end, including the decimal point. Later, the code prints all non-'.' characters from cc, which works, but if the original number has no decimal point (which shouldn't happen per problem), this fails. More importantly, if the input is like "123.45", cc becomes "23.45", and then printing non-'.' chars gives "2345", so output becomes "1.2345e2", which is correct. But what if input is "1.0"? Problem states no trailing zeros, so "1.0" won't appear. However, the bigger issue is: what if the input has only one digit before decimal and it's non-zero, e.g., "5.67"? Then b=1, and exponent is b-1 = 0, so output "5.67e0", but expected is "5.67" without exponent? No—problem says output scientific notation always. But according to spec: if only one digit before decimal and it's non-zero, it's already normalized. So "5.67" → "5.67e0"? But reference program outputs "5.67e0". However, the problem says: "If it’s a decimal, it must have one significant digit before and after..." — so yes, "5.67e0" is correct. BUT: what if input is "10.5"? Then b=2, exponent=1, output "1.05e1" — correct. However, the code uses strcpy(cc, &c[1]), which includes the '.' and everything after. Then it prints c[0], then '.', then all non-'.' from cc. That works. BUT: if input has no decimal point? Problem states input has digits before AND after decimal point, so '.' always exists. So this part may be okay. However, the initial assumption that the 'else' branch handles all non-"0.x" cases is flawed: what about "0.0...0x"? The 'if' condition only checks c[0]=='0' and c[1]=='.', so "0.001" goes into 'if', but "10.5" goes to else. But what about "01.23"? Problem states: "If there’s only one digit before the decimal point, it can be 0; otherwise, the first digit before the decimal point cannot be 0." So input won't have leading zeros like "01.23". So else branch assumes first digit is non-zero and either single digit (like "5.6") or multiple (like "123.4"). So logic seems okay EXCEPT: the 'if' condition only triggers when c[0]=='0' AND c[1]=='.'. What if input is "0.0"? Problem says "all digits are significant" and "no trailing zeros after decimal", so "0.0" is invalid input? But test case might include it. However, the main error is in the 'if' branch logic for leading zeros.]

    pf("%c.",c[0]);
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1);
}
    return 0;
}
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
            
    pf("%c",c[2]); // @@ [If the input is "0.0", then c[2] is '0', but if the input is "0.00...0" with all zeros after decimal, this accesses beyond meaningful digits; also, if input length is exactly 2 (e.g., "0."), c[2] is out of bounds.]
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);}
    else{pf("%s",&c[3]); // @@ [When c[3] is '\0', printing &c[3] prints an empty string, which is okay, but the logic assumes at least one non-zero digit exists after leading zeros, which may not be true. Also, if input is too short (e.g., "0.1"), c[3] may be '\0', but the earlier loop sets d based on zeros starting at index 2, so c[2] must exist — but if input is "0." (only two characters), this leads to undefined behavior.]
    
    }pf("e-%d",d+1);
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]); // @@ [If the input has no decimal point, the loop above doesn't break and b becomes strlen(c), but more critically, if the input is just a single digit like "5", then &c[1] is an empty string, but the code still prints c[0] and then copies from c[1], which is okay. However, if the input has no decimal point at all, the logic fails because the problem guarantees there is a decimal point. But the real issue: if the input starts with multiple digits like "123.45", this copies from c[1] ("23.45") into cc, then prints all non-'.' chars, which is correct. However, if the input is "0.123", it goes into the first branch, but if it's "10.5", it goes here. The main error is that the loop to find '.' may run past the string if there's no '.', but problem states input always has digits before and after '.', so maybe safe. Still, the use of gets is the primary compilation issue.]
    pf("%c.",c[0]);
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1);
}
    return 0;
}
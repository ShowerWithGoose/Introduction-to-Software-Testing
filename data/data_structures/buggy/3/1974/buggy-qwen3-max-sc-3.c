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
            
    pf("%c",c[2]); // @@ [If the input is "0.0", then c[2] is '0', but if the input is "0.000...", this prints the first zero after decimal, which may be correct, but if the input has no non-zero digits (e.g., "0.0"), accessing c[2] assumes at least 3 characters, which may not hold for minimal inputs like "0.1". However, the primary error is use of 'gets'.]
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);}
    else{pf("%s",&c[3]); // @@ [When c[3] is '\0', printing &c[3] prints an empty string, which is okay, but the logic for handling significant digits after the first non-zero is flawed. However, the main compilation issue is 'gets'.]
    
    }pf("e-%d",d+1);
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]); // @@ [This copies from c[1] onward, including the decimal point. Later, the loop skips '.', but if there are multiple '.' (invalid input), behavior is undefined. But again, the critical error causing compilation failure is 'gets'.]
    pf("%c.",c[0]);
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1);
}
    return 0;
}
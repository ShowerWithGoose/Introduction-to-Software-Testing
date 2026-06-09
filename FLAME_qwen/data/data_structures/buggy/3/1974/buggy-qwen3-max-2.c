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
    gets(c); // @@ [Using gets() is unsafe and deprecated; it may cause buffer overflow and is removed in C11. Also, the problem expects input ending with newline, but gets() discards newline, which may affect logic. More critically, many compilers (like GCC) no longer support gets(), leading to compilation error.]
    int a,b,d=0,e=0,f,g,h,i,j;
    if(c[1]=='.'&&c[0]=='0'){
        for(b=2;b<strlen(c);b++){
            if(c[b]=='0'){
                d++;
            }}
            
    pf("%c",c[2]); // @@ [If the input is "0.0", then c[2] is '0', but after that there may be no non-zero digit. The code assumes c[2] exists and is the first significant digit, which fails if all digits after decimal are zero or if string length is <=2. However, per problem, all digits are significant and no trailing zeros, so "0.0" won't occur. But more importantly, if input is "0.1", this prints '1' correctly, but if input is "0.01", d=1, and it prints c[2]='0' — which is wrong! It should find the first non-zero digit, not assume it's at index 2. This is a logical error, but the immediate compilation error is due to gets().]
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);}
    else{pf("%s",&c[3]); // @@ [This prints an empty string if c[3] is '\0', which is okay, but the bigger issue is that the code doesn't skip leading zeros after decimal. For example, "0.00123" should become "1.23e-3", but this code prints "0.0123e-1" (if it even runs). However, again, the primary error causing compilation failure is gets().]
    
    }pf("e-%d",d+1);
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]); // @@ [If the input has no decimal point, strlen(c) will be used fully, but the loop above may run past the string if no '.' is found, leaving b == strlen(c). Then &c[1] is valid only if strlen(c) >= 2. Also, if input is "123" (no decimal), the code still tries to process as if there is a decimal, which violates problem constraints (input always has digits before and after decimal). But problem states input has digits before and after decimal point, so '.' always exists. Still, using gets() is the root cause of compilation error.]
    pf("%c.",c[0]);
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1);
}
    return 0;
}
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
            
    pf("%c",c[2]); // @@ [If the input is "0.0", then c[2] is '0', but if all digits after decimal are zero, this logic fails; also, if input length is exactly 3 like "0.1", c[3] is '\0', but accessing c[2] assumes at least 3 characters exist. However, the primary error causing compilation failure is the use of 'gets'.]
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);}
    else{pf("%s",&c[3]); // @@ [Printing &c[3] when c[3] is '\0' prints an empty string, which is okay, but the logic doesn't handle cases where significant digit is beyond index 2 correctly. Still, not a compilation error.]
    
    }pf("e-%d",d+1);
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]); // @@ [If there's no '.' in the input (though problem states there is), or if input is just one digit before '.', this may copy unexpected data. But again, not a compilation error.]
    pf("%c.",c[0]);
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1);
}
    return 0;
}
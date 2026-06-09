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
    gets(c);
    int a,b,d=0,e=0,f,g,h,i,j;
    if(c[1]=='.'&&c[0]=='0'){
        for(b=2;b<strlen(c);b++){
            if(c[b]=='0'){
                d++;
            }}
            
    pf("%c",c[d+2]); // @@ The first significant digit is at index d+2 (after "0." and d zeros), not fixed at index 2.
    if(c[d+3]!='\0'){ // @@ Check if there are digits remaining after the first significant digit found at d+2.
    
    pf(".");pf("%s",&c[d+3]);} // @@ Print the remaining digits starting from the one after the first significant digit.
    else{pf("%s",&c[d+3]);
    
    }pf("e-%d",d+1);
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]);
    pf("%c.",c[0]);
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1);
}
    return 0;
}
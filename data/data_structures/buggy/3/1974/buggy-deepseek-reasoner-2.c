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
                d++; // @@ This counts every zero after the decimal, not just leading zeros. For numbers like "0.101", d becomes 1 (from the middle zero), leading to exponent -2 instead of -1.
            }}
            
    pf("%c",c[2]);
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);}
    else{pf("%s",&c[3]);
    
    }pf("e-%d",d+1); // @@ Uses the incorrectly accumulated d to compute exponent. Should be based on the index of the first non-zero digit.
    
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
#include<stdio.h>
#include<string.h>
char s[200];
int main(){
    gets(s);
    int l=strlen(s);
    int nt=-1;
    int r;
    int op=0;
    if(l>1){
    
    if(s[0]!='0'){
        if(s[1]=='.'){
            printf("%se0",s);
        }
        else if(s[1]!='.'){
            for(int i=0;i<l;i++){
                if(s[i]!='.'){
                    op++;
                }
                if(s[i]=='.')break;
            }
            printf("%c.",s[0]);
            for(int zn=1;zn<op;zn++){
                printf("%c",s[zn]);
            }
            for(int xc=op+1;xc<l;xc++){
                if(xc!=l-1)printf("%c",s[xc]);
                if(xc==l-1)printf("%ce%d",s[xc],op-1);
            }
        }
        
    }
    int jb=0;
    int nz=0;
if(s[0]=='0'){

for(int xy=0;xy<l;xy++){ // @@ [Error: This loop counts only zeros before the decimal point, not the zeros after it. It should find the first non-zero digit after the decimal.]
    if(s[xy]=='0')jb++;
    if(s[xy]!='.'&&s[xy]!='0')break;
}        
        
        
        
        
        
            int sb=-(jb); // @@ [Error: The exponent should be negative of the number of decimal places before the first significant digit, not just -jb. Incorrect for numbers like "0.00123".]
//printf("!%d!",jb);
    printf("%c.",s[jb+1]); // @@ [Error: This selects the wrong starting digit; jb+1 points to the first zero after decimal for numbers with multiple zeros, not the first non-zero digit.]
    for(int nmsl=jb+2;nmsl<l;nmsl++){
        if(nmsl!=l-1)printf("%c",s[nmsl]);
        if(nmsl==l-1)printf("%ce%d",s[nmsl],sb); // @@ [Error: If there are no digits after the first significant digit (e.g., "0.5"), this loop never executes, and no exponent is printed.]
    }
    }
}
if(l==1)printf("%se0",s);
    return 0;
}
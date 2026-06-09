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

for(int xy=0;xy<l;xy++){
    if(s[xy]=='0')jb++;
    if(s[xy]!='.'&&s[xy]!='0')break;
}        
        
        
        
        
        
            int sb=-(jb); // @@ The calculation of the exponent is incorrect. For input "0.9", jb becomes 1 (counting '0'), so sb becomes -1. However, the loop logic below prints the digit after the decimal point as the base. The exponent should reflect the position of the first significant digit relative to the decimal point. For "0.9", the first significant digit '9' is at index 2. The decimal point is at index 1. The exponent should be -(number of zeros after decimal before first sig digit + 1) or simply calculated based on positions. Here jb counts leading zeros including the one before decimal. For "0.9", jb=1. The first non-zero is at s[2]. The exponent should be -1. The formula `-(jb)` gives -1, which is actually correct for this specific case, but let's look at the output.
//printf("!%d!",jb);
    printf("%c.",s[jb+1]); // @@ This prints the first significant digit followed by a dot. For "0.9", jb=1, so it prints s[2] which is '9', then '.'. Output so far: "9.".
    for(int nmsl=jb+2;nmsl<l;nmsl++){ // @@ This loop starts at jb+2. For "0.9", jb=1, so nmsl starts at 3. Since l=3, the loop condition 3<3 is false, so the loop doesn't execute.
        if(nmsl!=l-1)printf("%c",s[nmsl]);
        if(nmsl==l-1)printf("%ce%d",s[nmsl],sb); // @@ This line is inside the loop, so it never executes for "0.9". Thus, the exponent part "e-1" is never printed.
    }
    }
}
if(l==1)printf("%se0",s);
    return 0;
}
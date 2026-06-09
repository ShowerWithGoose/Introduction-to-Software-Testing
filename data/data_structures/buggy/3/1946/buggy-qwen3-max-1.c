#include<stdio.h>
#include<string.h>
char s[200];
int main(){
    gets(s); // @@ [Use of unsafe function 'gets' which may cause buffer overflow; also, in modern C standards, 'gets' is removed. However, the immediate error causing compilation failure is likely missing #include <stdlib.h> or compiler not found, but based on provided info, the actual runtime logic errors are more relevant. But per problem statement, the error type is "Compilation Error" and output says "gcc: not found", which is environment issue. However, assuming we treat logical/syntax issues that would cause compilation in strict mode: 'gets' is deprecated/removed in C11+.]
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
            for(int i=0;i<l;i++){ // @@ [Declaration of 'i' inside for loop is C99 feature; if compiler uses older standard (like C89), this will cause compilation error.]
                if(s[i]!='.'){
                    op++;
                }
                if(s[i]=='.')break;
            }
            printf("%c.",s[0]);
            for(int zn=1;zn<op;zn++){ // @@ [Same issue: variable declaration inside for loop may not be supported in older C standards, leading to compilation error.]
                printf("%c",s[zn]);
            }
            for(int xc=op+1;xc<l;xc++){ // @@ [Same issue: C89 does not allow variable declarations inside for loops.]
                if(xc!=l-1)printf("%c",s[xc]);
                if(xc==l-1)printf("%ce%d",s[xc],op-1);
            }
        }
        
    }
    int jb=0;
    int nz=0;
if(s[0]=='0'){

for(int xy=0;xy<l;xy++){ // @@ [Same C99 vs C89 issue: declaring 'xy' inside for loop may cause compilation error in non-C99 mode.]
    if(s[xy]=='0')jb++;
    if(s[xy]!='.'&&s[xy]!='0')break;
}        
        
        
        
        
        
            int sb=-(jb); // @@ [This line is after a block of code without proper handling of cases where jb might lead to invalid index; but compilation-wise, variable declaration here is fine in C89 since it's at top of block? Actually, in C89, all variables must be declared at beginning of block. This 'sb' is declared after executable statements (the for loop), which violates C89 and causes compilation error.]
//printf("!%d!",jb);
    printf("%c.",s[jb+1]); // @@ [If input is "0.0", jb becomes 2 (index of first non-zero after '.'), but jb+1 = 3 which is beyond string length, causing undefined behavior. But this is runtime, not compilation. However, the declaration of 'sb' after code is a C89 compilation error.]
    for(int nmsl=jb+2;nmsl<l;nmsl++){ // @@ [Again, variable declaration inside for loop not allowed in C89, causing compilation error. Also, if jb+2 >= l, loop doesn't run, but that's logic.]
        if(nmsl!=l-1)printf("%c",s[nmsl]);
        if(nmsl==l-1)printf("%ce%d",s[nmsl],sb);
    }
    }
}
if(l==1)printf("%se0",s);
    return 0;
}
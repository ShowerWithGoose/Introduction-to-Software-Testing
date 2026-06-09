#include<stdio.h>
#include<string.h>
char s[200];
int main(){
    gets(s); // @@ gets() is removed in C11 standard and causes compilation error in modern compilers; use fgets() instead
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
            for(int i=0;i<l;i++){ // @@ Declaring loop variable inside for is a C99 feature, may cause compilation error in C89/C90 standard
                if(s[i]!='.'){
                    op++;
                }
                if(s[i]=='.')break;
            }
            printf("%c.",s[0]);
            for(int zn=1;zn<op;zn++){ // @@ Declaring loop variable inside for is a C99 feature, may cause compilation error in C89/C90 standard
                printf("%c",s[zn]);
            }
            for(int xc=op+1;xc<l;xc++){ // @@ Declaring loop variable inside for is a C99 feature, may cause compilation error in C89/C90 standard
                if(xc!=l-1)printf("%c",s[xc]);
                if(xc==l-1)printf("%ce%d",s[xc],op-1);
            }
        }
        
    }
    int jb=0;
    int nz=0;
if(s[0]=='0'){

for(int xy=0;xy<l;xy++){ // @@ Declaring loop variable inside for is a C99 feature, may cause compilation error in C89/C90 standard
    if(s[xy]=='0')jb++;
    if(s[xy]!='.'&&s[xy]!='0')break;
}        
        
        
        
        
        
            int sb=-(jb);
//printf("!%d!",jb);
    printf("%c.",s[jb+1]); // @@ Logical error: unconditionally prints a decimal point, but should omit it if no digits follow (e.g., 0.5 should output 5e-1, not 5.e-1)
    for(int nmsl=jb+2;nmsl<l;nmsl++){ // @@ Declaring loop variable inside for is a C99 feature, may cause compilation error in C89/C90 standard
        if(nmsl!=l-1)printf("%c",s[nmsl]);
        if(nmsl==l-1)printf("%ce%d",s[nmsl],sb);
    }
    }
}
if(l==1)printf("%se0",s);
    return 0;
}
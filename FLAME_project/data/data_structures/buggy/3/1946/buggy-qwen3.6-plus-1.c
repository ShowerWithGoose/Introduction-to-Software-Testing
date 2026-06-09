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
        
        
        
        
        
            int sb=-(jb); // @@ The exponent calculation is incorrect for numbers like 0.9. For "0.9", jb becomes 1 (counting '0'), so sb is -1. However, the logic for printing the base assumes the first non-zero digit is at s[jb+1]. For "0.9", s[0]='0', s[1]='.', s[2]='9'. The loop increments jb for s[0] ('0'), then checks s[1] ('.') which is not '0', so it doesn't increment jb? No, the condition is `if(s[xy]=='0') jb++`. For xy=0, s[0]=='0', jb=1. For xy=1, s[1]=='.', not '0', jb stays 1. Break condition `s[xy]!='.' && s[xy]!='0'` is false for '.'. So loop continues. For xy=2, s[2]=='9'. Not '0'. jb stays 1. Break condition true. Loop ends. jb=1. sb = -1. This part seems correct for exponent.
//printf("!%d!",jb);
    printf("%c.",s[jb+1]); // @@ For "0.9", jb=1, so s[jb+1] is s[2] which is '9'. Prints "9.". This matches the buggy output start.
    for(int nmsl=jb+2;nmsl<l;nmsl++){ // @@ For "0.9", jb=1, so nmsl starts at 3. l=3. The loop condition 3<3 is false. The loop body never executes.
        if(nmsl!=l-1)printf("%c",s[nmsl]);
        if(nmsl==l-1)printf("%ce%d",s[nmsl],sb); // @@ This line prints the exponent part "e-1". Since the loop doesn't run, this line is never reached. Thus, "e-1" is missing from the output.
    }
    }
}
if(l==1)printf("%se0",s);
    return 0;
}
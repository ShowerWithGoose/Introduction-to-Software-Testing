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
            printf("%se0",s); // @@ [This prints the entire input as-is followed by "e0", but for numbers like "5.3", it should output "5.3e0", which is correct per problem? However, the real issue is in the '0.x' branch. But this line fails for cases like "12.3" because it doesn't normalize to one digit before decimal. However, the test case is "0.9", so focus there.]
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
        
        
        
        
        
            int sb=-(jb); // @@ [The exponent calculation is wrong. For "0.9", jb becomes 1 (counts the leading '0'), then sb = -1. But the correct exponent should be -1, which seems right. However, the base printed is wrong: it prints "9." instead of "9". Also, the loop below prints a decimal point unconditionally.]
    printf("%c.",s[jb+1]); // @@ [This always prints a decimal point after the first significant digit, but according to the problem, if the base is an integer (only one significant digit), it should NOT have a decimal point. For "0.9", the normalized form is "9e-1", not "9.e-1" or "9.".]
    for(int nmsl=jb+2;nmsl<l;nmsl++){
        if(nmsl!=l-1)printf("%c",s[nmsl]);
        if(nmsl==l-1)printf("%ce%d",s[nmsl],sb); // @@ [This assumes there are digits after the first significant digit, but for "0.9", jb=1, so s[jb+1] = s[2] = '9', and jb+2 = 3 which is beyond the string length (l=3: '0','.','9'), so this loop doesn't run. Thus, only "9." is printed without the exponent part.]
    }
    }
}
if(l==1)printf("%se0",s);
    return 0;
}
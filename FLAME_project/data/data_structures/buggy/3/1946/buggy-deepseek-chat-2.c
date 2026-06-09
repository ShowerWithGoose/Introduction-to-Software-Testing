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
            printf("%se0",s); // @@ This prints the entire input string including the decimal point, but for numbers like "0.9" this branch is not taken. For numbers like "1.23", it prints "1.23e0" which is incorrect because the base should have only one digit before the decimal point. The correct output for "1.23" should be "1.23e0" only if the number is already in scientific notation form, but the problem requires converting to scientific notation with one digit before the decimal point. Actually, for "1.23", the output should be "1.23e0" which matches, but the issue is with numbers like "0.9" where this branch is not executed.
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
        
        
        
        
        
            int sb=-(jb);
//printf("!%d!",jb);
    printf("%c.",s[jb+1]); // @@ For input "0.9", jb becomes 1 (since s[0]='0', s[1]='.' is not '0', so loop breaks after jb=1). Then s[jb+1] = s[2] = '9', so it prints "9." but the exponent sb = -1 is not printed because the loop below prints the remaining digits and the exponent only at the last digit. However, after printing "9.", the loop for(int nmsl=jb+2;nmsl<l;nmsl++) starts at nmsl=3, but l=3, so the loop doesn't execute, and the exponent is never printed. The expected output is "9e-1", but the program outputs "9.".
    for(int nmsl=jb+2;nmsl<l;nmsl++){
        if(nmsl!=l-1)printf("%c",s[nmsl]);
        if(nmsl==l-1)printf("%ce%d",s[nmsl],sb);
    }
    }
}
if(l==1)printf("%se0",s);
    return 0;
}
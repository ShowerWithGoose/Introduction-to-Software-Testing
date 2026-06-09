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
            printf("%se0",s); // @@ [This prints the original number with "e0", but for numbers like "5.3", it should normalize to "5.3e0", which is acceptable, but the real issue is in the '0.x' branch. However, this line is not the cause of the failure for input "0.9".]
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
        
        
        
        
        
            int sb=-(jb); // @@ [The exponent calculation is wrong. For "0.9", jb becomes 2 (counts '0' and '.' as zeros due to flawed logic), leading to sb = -2, but even if jb were correct, the logic doesn't account for the position properly. Actually, jb counts the leading zeros including the '0' before '.', so for "0.9", jb=1 (only the first '0'), then s[jb+1] is s[2] which is '9', which is correct, but the exponent should be -1, not -jb. The correct exponent is -(jb) but only if jb counts the zeros before the first non-zero after decimal. However, the loop breaks at first non-zero/non-dot, so jb=1 for "0.9", so sb=-1, which is correct. But the output format is wrong: it prints "9.e-1" instead of "9e-1" because it always prints a decimal point.]
    printf("%c.",s[jb+1]); // @@ [This always prints a decimal point, but according to the problem, if the base is an integer (only one significant digit), it should not have a decimal point. For "0.9", the normalized form is "9e-1", not "9.e-1".]
    for(int nmsl=jb+2;nmsl<l;nmsl++){
        if(nmsl!=l-1)printf("%c",s[nmsl]);
        if(nmsl==l-1)printf("%ce%d",s[nmsl],sb); // @@ [Even if there are no extra digits after the first significant digit, this loop may not run (e.g., "0.9" has jb=1, so jb+2=3, but l=3, so nmsl starts at 3 and condition nmsl<l fails). Thus, the '9' is printed with a trailing ".", and the exponent part is never printed. Actually, for "0.9", l=3, jb=1, so jb+1=2 -> s[2]='9', then jb+2=3, which equals l, so the for loop doesn't execute. So only "9." is printed, and the exponent part (including 'e') is missing.]
    }
    }
}
if(l==1)printf("%se0",s);
    return 0;
}
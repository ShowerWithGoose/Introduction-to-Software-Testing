#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char s[200],ss[200];
bool dot(char *s){
    int l=strlen(s);
    for(int i=0;i<l;i++){
        if(s[i]=='.')return true;
    }
    return false;
}
void SciNo(){
    scanf("%s",s);
    int l=strlen(s);
    int e=-1;
    if(!dot(s)){
        if(l>=2){
            ss[0]=s[0];
            ss[1]='.';
            for(int i=2;i<l+1;i++){
                ss[i]=s[i-1];
            }
            e=l-1;
        }
        else{
            e=0;
            for(int i=0;i<l;i++)ss[i]=s[i];
        }
    }
    else if(dot(s)){
        if(s[0]!='0'){
            for(int i=0;i<l;i++){
                if(s[i]!='.')e++;
                else break;
            }
            ss[0]=s[0];
            ss[1]='.';
            int j=2;
            for(int i=1;i<l;i++){
                if(s[i]!='.'){
                    ss[j++]=s[i];
                }
            }
        }
        else{
            for(int i=2;i<l;i++){
                if(s[i]=='0'){
                    e--;
                }
            } @@ [This loop only decrements 'e' for zeros, but it should count leading zeros until the first non-zero digit to compute the correct exponent. It fails to break after finding the first non-zero digit, and doesn't handle the position correctly.]
            int j=2;
            ss[0]=s[-e+1]; @@ [Incorrect index calculation: '-e+1' assumes 'e' was properly computed as negative of (position - 1), but due to the flawed loop above, 'e' is not set correctly. Also, if all digits after decimal are zero (though problem says no trailing zeros), this could access invalid memory.]
            if(l>-e+2){
                ss[1]='.';
                for(int i=-e+3;i<l;i++){
                    ss[j++]=s[i];
            } @@ [Mismatched brace placement may cause compilation issues; also, the logic for copying remaining digits uses incorrect offset based on wrong 'e'.]
            }
        }
    }
    printf("%s",ss); @@ [The string 'ss' is not null-terminated, which leads to undefined behavior when printed.]
    printf("e%d\n",e);
}
int main(){
    SciNo();
    return 0;
}
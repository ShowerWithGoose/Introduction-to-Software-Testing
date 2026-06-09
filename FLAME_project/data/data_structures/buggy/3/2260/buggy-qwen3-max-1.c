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
            } // @@ [This loop only decrements 'e' for zeros, but it should count all leading zeros after "0." until the first non-zero digit. It ignores non-zero digits and doesn't stop at the first non-zero digit, leading to incorrect exponent calculation.]
            int j=2;
            ss[0]=s[-e+1]; // @@ [The index '-e+1' is based on an incorrectly computed 'e'. Since 'e' was only decremented for zeros and not properly counted, this accesses the wrong character. For input "0.00000009123...", it should pick '9' at position 8 (0-indexed), but due to wrong 'e', it picks the wrong digit.]
            if(l>-e+2){
                ss[1]='.';
                for(int i=-e+3;i<l;i++){
                    ss[j++]=s[i];
            } // @@ [The loop starts at '-e+3', which is also based on the incorrect 'e'. This causes the fractional part to start from the wrong position, skipping or including wrong digits.]
            }
        }
    }
    printf("%s",ss);
    printf("e%d\n",e);
}
int main(){
    SciNo();
    return 0;
}
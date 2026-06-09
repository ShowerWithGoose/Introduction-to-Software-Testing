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
            } // @@ [This loop only decrements 'e' for zeros, but it should count all leading zeros after "0." to determine exponent correctly. It ignores non-zero digits and stops counting too early.]
            int j=2;
            ss[0]=s[-e+1]; // @@ [The index -e+1 is incorrect because 'e' was initialized to -1 and only decremented for zeros, not for total leading zero count. This leads to wrong digit selection.]
            if(l>-e+2){
                ss[1]='.';
                for(int i=-e+3;i<l;i++){ // @@ [The starting index -e+3 is based on an incorrect exponent calculation, causing wrong fractional part extraction.]
                    ss[j++]=s[i];
            }
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
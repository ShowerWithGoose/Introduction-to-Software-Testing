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
            }
            int j=2;
            ss[0]=s[-e+1]; // @@ [When the input is like "0.001", the loop above decrements e for each '0' after the decimal, but it doesn't stop at the first non-zero digit. Thus, -e+1 may point to an incorrect or out-of-bound index. Also, if all digits after decimal are zero (though problem says no trailing zeros), this logic fails. Moreover, e starts at -1 and is only decremented for zeros, so for "0.1", e remains -1, then -e+1 = 2, which is beyond string length.]
            if(l>-e+2){
                ss[1]='.';
                for(int i=-e+3;i<l;i++){
                    ss[j++]=s[i];
            }
            }
        }
    }
    printf("%s",ss); // @@ [The ss array is not null-terminated, so printf may print garbage beyond intended digits.]
    printf("e%d\n",e);
}
int main(){
    SciNo();
    return 0;
}
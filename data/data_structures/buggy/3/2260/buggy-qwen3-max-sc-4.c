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
            ss[0]=s[-e+1]; // @@ [When the input is like "0.001", e becomes -3 after the loop, so -e+1 = 4, which accesses s[4]. But s only has length up to ~5 (e.g., "0.001" is length 5), and s[4] is '1', which is correct in this case. However, the logic for computing e is flawed: it decrements e once per leading zero after "0.", but should count position of first non-zero digit. Also, if all digits after decimal are zero (though problem says no trailing zeros, but leading zeros exist), this fails. More critically, if there are no non-zero digits after decimal (invalid per problem, but code doesn't handle), or if -e+1 exceeds string bounds, it causes undefined behavior. Additionally, ss is not null-terminated, leading to garbage output.]
            if(l>-e+2){
                ss[1]='.';
                for(int i=-e+3;i<l;i++){
                    ss[j++]=s[i];
            }
            }
        }
    }
    printf("%s",ss); // @@ [ss is not null-terminated anywhere in the code, so printf("%s", ss) reads beyond intended characters until it hits a random null byte, causing incorrect or garbage output.]
    printf("e%d\n",e);
}
int main(){
    SciNo();
    return 0;
}
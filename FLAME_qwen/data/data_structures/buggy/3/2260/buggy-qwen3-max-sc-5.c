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
            ss[0]=s[-e+1]; // @@ [When the input is like "0.001", e becomes -3 after the loop, so -e+1 = 4, which accesses s[4]. But s only has length up to ~5 (e.g., "0.001" is length 5), and s[4] is '1', which is correct in this case. However, the logic for computing e is flawed: it only decrements e for each '0' after the decimal, but doesn't stop at the first non-zero digit. So for "0.010", it would incorrectly count both zeros and set e = -2, then access s[3] which is '1' — but trailing zeros are not allowed per problem statement. More critically, if all digits after decimal are zero (which shouldn't happen per problem constraints), this would underflow. But the main issue is that e is initialized to -1, then decremented for every '0' starting from index 2, which does not correctly compute the exponent. The exponent should be -(position of first non-zero after decimal). This loop doesn't break after finding the first non-zero, so it over-decrements e.]
            if(l>-e+2){
                ss[1]='.';
                for(int i=-e+3;i<l;i++){
                    ss[j++]=s[i];
            }
            }
        }
    }
    printf("%s",ss); // @@ [ss is not null-terminated, so printf may print garbage beyond intended characters.]
    printf("e%d\n",e);
}
int main(){
    SciNo();
    return 0;
}
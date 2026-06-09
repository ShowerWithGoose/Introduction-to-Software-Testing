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
    int e=-1; // @@ The variable e is initialized to -1, but it should be initialized to 0 or calculated correctly based on the position of the first significant digit. For numbers like 0.00..., the exponent calculation logic below is flawed because it relies on this initial value and subsequent decrements/increments which don't align with standard scientific notation rules.
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
            } // @@ This loop incorrectly calculates the exponent. It decrements e for every '0' after the decimal point, but it should stop at the first non-zero digit. Also, e starts at -1, so for 0.0000000912..., it will count seven '0's and make e = -1 - 7 = -8. However, the index calculation for the significant digit is also wrong.
            int j=2;
            ss[0]=s[-e+1]; // @@ The index `-e+1` is incorrect for finding the first significant digit. If e is -8 (correct exponent for 9.12...e-8), -(-8)+1 = 9. s[9] is '9', which is correct by accident in this specific case due to the flawed e calculation matching the offset, but the logic is brittle. More importantly, the previous loop for calculating e is logically wrong for general cases (e.g., 0.105 would result in e=-1, index 2, s[2]='5', missing '1'). The correct approach is to find the first non-zero digit after '0.' and calculate exponent based on its position.
            if(l>-e+2){
                ss[1]='.';
                for(int i=-e+3;i<l;i++){
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
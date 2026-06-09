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
    int e=-1; // @@ The initial value of e is -1, but it should be 0 to correctly count the exponent or calculate offset. For numbers < 1, e is decremented from -1, leading to off-by-one errors. For numbers > 1, e is incremented from -1, also leading to off-by-one errors.
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
            } // @@ This loop only counts consecutive zeros immediately after "0.". If there are non-zero digits, it stops counting incorrectly because it doesn't break. More importantly, it doesn't identify the position of the first significant digit to set the base correctly. It just decrements e for every '0'.
            int j=2;
            ss[0]=s[-e+1]; // @@ The index calculation for the first significant digit is incorrect due to the wrong initialization and calculation of e. For input 0.0000000912..., the first sig digit is at index 9 ('9'). e becomes -8 (starting -1, minus seven 0s). -(-8)+1 = 9. This part might accidentally work for this specific case if e was calculated right, but the logic for finding the first non-zero digit is missing.
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
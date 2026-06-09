#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
char s[200];
int dot=0,flag=0,wa=0,sum=1;
int main(){
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.')dot=i;
        if(dot>0){
            if(s[i]!='0')flag=1;
            if(!flag&&s[i]=='0')sum++;
        }
    }
    if(dot==1&&s[0]!='0'){
        printf("%se0",s);
    }
    else{
        if(s[0]=='0'){
            for(int i=dot+sum;i<len;i++){
                if(s[i]!='.')
                printf("%c",s[i]);
                if(i==dot+sum&&i!=len-1)printf(".");
            }
            printf("e-%d",sum); // @@ The exponent calculation is incorrect. 'sum' counts leading zeros including the one before the decimal point (e.g., in "0.00..."), but the exponent should be -(number of zeros after decimal + 1). For "0.00000009...", sum becomes 8 (indices 0-7 are '0' or '.' logic is flawed). Actually, let's trace: s="0.00000009...". dot=1. i=0: dot=0 so skip. i=1: dot=1. s[1]='.' != '0', flag=1. sum unchanged. i=2: s[2]='0', flag=1, skip. The loop logic for calculating 'sum' (exponent magnitude) is fundamentally broken because it resets/depends on 'flag' which triggers at the decimal point itself if dot>0. It fails to count the zeros after the decimal point correctly before the first significant digit.
        }
        else{
            for(int i=0;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]); 
                }
                if(i==0)printf(".");
            }
            printf("e%d",dot-1);
        }
    }
    return 0;
}
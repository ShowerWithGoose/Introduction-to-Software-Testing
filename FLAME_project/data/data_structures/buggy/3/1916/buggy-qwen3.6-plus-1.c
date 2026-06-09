//JmmyWng
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX 109
int main(){
    char ori[MAX],ans[MAX];
    gets(ori);
    int cnt,cntn0=0; // @@ Variable 'cnt' is used uninitialized. In the case of "0.~", it is incremented but never initialized to 0, leading to undefined behavior (garbage value).
    int i,j;
    int lng=strlen(ori);
    if(ori[1]=='.'&&ori[0]>'0'&&ori[0]<='9'){  //already
        printf("%se0",ori);
    }
    else if(ori[1]=='.'&&ori[0]=='0'){   //0.~
        for(i=0;i<lng;i++){
            if(ori[i]=='0')cnt++;   //count the 0 before the number // @@ Logic error: This counts ALL zeros in the string (including those after the decimal point if any, though problem says significant digits, but specifically it counts the '0' before decimal AND potentially others). More importantly, for 0.9, it counts the first '0'. cnt becomes 1 (if initialized). But wait, if cnt is garbage, this is worse. Even if initialized, for 0.009, it would count two zeros. The exponent should be -(number of zeros after decimal before first non-zero + 1). For 0.9, exponent is -1. The code prints e-cnt. If cnt=1, e-1. This part might be logically okay IF cnt was initialized and only counted leading zeros. However, the loop continues.
            else if(ori[i]!='0'&&ori[i]!='.'&&cntn0==0){
                cntn0++;
                printf("%c",ori[i]);
                if(i<lng-1)printf("."); // @@ Logic error: This adds a decimal point after the first significant digit. For 0.9, it prints '9', then checks if i (index of '9') < lng-1. If input is "0.9", lng=3. i=2. 2 < 2 is false. So no dot. Output "9". Then later prints e-cnt. This seems okay for single digit. But what if input is 0.09? i for '9' is 3. lng=4. 3<3 false. No dot. Output "9". Correct base. What if 0.12? i for '1' is 2. lng=4. 2<3 true. Prints ".". Then loop continues, prints '2'. Base "1.2". Correct.
            }
            else if(cntn0!=0){
                printf("%c",ori[i]);
            }
        }
        printf("e-%d",cnt);
    }
    else{
        i=1;
        while(ori[i]!='.'){
            cnt++; // @@ Variable 'cnt' is used uninitialized here as well. It accumulates garbage + number of digits before decimal.
            i++;
        }
        i=0;
        printf("%c.",ori[0]);
        for(i=1;i<lng;i++){
            if(ori[i]=='.')continue;
            printf("%c",ori[i]);
        }
        printf("e%d",cnt);
    }
    return 0;
}
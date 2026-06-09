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
            if(ori[i]=='0')cnt++;   //count the 0 before the number // @@ Logic error: This counts ALL zeros in the string (including those after the decimal point if any, though problem says significant digits, but specifically it counts the '0' before decimal AND potentially others). More importantly, for 0.9, cnt becomes 1 (for the first 0). The exponent should be -1. The logic `printf("e-%d",cnt)` prints e-1. Wait, let's trace 0.9. i=0, ori[0]='0', cnt++ -> cnt=1. i=1, ori[1]='.', skip. i=2, ori[2]='9', cntn0==0, so cntn0=1, print '9', print '.'. End loop. Print e-1. Output: 9.e-1. Expected: 9e-1. The base format is wrong. It prints "9." instead of "9".
            else if(ori[i]!='0'&&ori[i]!='.'&&cntn0==0){
                cntn0++;
                printf("%c",ori[i]);
                if(i<lng-1)printf("."); // @@ Logic error: This adds a decimal point after the first significant digit if it's not the last character. For "0.9", '9' is at index 2, lng=3. 2 < 2 is false. So no dot printed? Wait. lng=3. i=2. i < lng-1 => 2 < 2 is false. So no dot. Output: 9e-1. This seems correct for 0.9? Let's re-read carefully.
                // If input is 0.09. lng=4. i=0 '0' cnt=1. i=1 '.' skip. i=2 '0' cnt=2. i=3 '9' cntn0=0. Print '9'. i=3 < 3 is false. No dot. Output 9e-2. Expected 9e-2. Base is integer 9. Correct.
                // If input is 0.12. lng=4. i=0 '0' cnt=1. i=1 '.' skip. i=2 '1' cntn0=0. Print '1'. i=2 < 3 is true. Print '.'. Output 1. . Next i=3 '2'. cntn0!=0. Print '2'. Output 1.2e-1. Expected 1.2e-1. Correct.
                // So the base formatting logic here actually handles "integer if only one sig digit" vs "decimal if more".
                // However, the variable `cnt` is still uninitialized at declaration.
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
            cnt++; // @@ Variable 'cnt' is used uninitialized here as well. It should be initialized to 0 before this block or at declaration.
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
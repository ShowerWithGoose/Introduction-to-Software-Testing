#include <stdio.h>
int main() {
    char num[105],num2[105];
    int i=0,b=0,d,num3,b1=0;
    while(~scanf("%c",&num[i])) { 
    i++;
    }//存
    for(int a=0;a<i;a++){
        if(num[a]!='.'){
            num2[b]=num[a];
            b++;
            b1++;
        }
    //把数字存在另一个数组里
    else{
        num3=a-1;
    }//科学计数法位数
    }
    if(i==b1){
        num3=i-1;
    }//没有小数点
    if(num2[0]=='0'){
        for(int a=1;a<i;a++){
            if(num2[a]!='0'){
                d=a; 
                num3=a;       
            break;
            }           
        }
        printf("%c",num2[d]);
        if(d!=i-4){ // @@ The condition `d!=i-4` is incorrect for determining if there are trailing digits to print after the decimal point. For input "0.9", `i` is likely 4 (0, ., 9, \n or similar), `d` is 2. `i-4` is 0. `2!=0` is true, so it prints ".". It should check if there are any significant digits remaining after the first non-zero digit.
        printf(".");
        for(int a=d+1;a<i-3;a++){ // @@ The loop bound `i-3` is incorrect. It assumes a fixed length or specific formatting of the input buffer including newline/null, which leads to printing extra characters or missing logic for stripping trailing zeros/non-digits. For "0.9", it might try to print nothing or garbage depending on `i`.
            printf("%c",num2[a]);
        }
        }
        else 
        {for(int a=d+1;a<i-2;a++){ // @@ This branch handles the case where it thinks there are no decimals to print, but the bounds `i-2` are also magic numbers dependent on input parsing artifacts (like newlines).
            printf("%c",num2[a]);
        }
        }
        printf("e-%d",num3);
    }//首位是0
    else if(i==b1){
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-2;a++){ // @@ Similar issue with magic number `i-2` for loop bound, assuming input format includes newline etc.
            printf("%c",num2[a]);
        }
      printf("e%d",num3);
    }/*没有小数点*/
    else{
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-3;a++){ // @@ Similar issue with magic number `i-3` for loop bound.
            printf("%c",num2[a]);
        }
        printf("e%d",num3);
    }//首位不是0
   
    return 0;
}
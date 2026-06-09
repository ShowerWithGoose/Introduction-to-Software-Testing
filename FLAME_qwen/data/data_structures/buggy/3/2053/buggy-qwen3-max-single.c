#include <stdio.h>
int main() {
    char num[105],num2[105];
    int i=0,b=0,d,num3,b1=0;
    while(~scanf("%c",&num[i])) { 
    i++;
    }//存 @@ [Using ~scanf is undefined behavior; scanf returns EOF on failure, which is negative, but bitwise NOT on negative values leads to unpredictable loop termination. Also, this loop doesn't stop at newline, causing buffer overflow and incorrect parsing.]
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
        if(d!=i-4){
        printf(".");
        for(int a=d+1;a<i-3;a++){
            printf("%c",num2[a]);
        }
        }
        else 
        {for(int a=d+1;a<i-2;a++){
            printf("%c",num2[a]);
        }
        }
        printf("e-%d",num3);
    }//首位是0 @@ [The logic for determining where to stop printing digits (e.g., i-3, i-4) is arbitrary and not based on actual input length or decimal position, leading to incorrect output or missing digits.]
    else if(i==b1){
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-2;a++){
            printf("%c",num2[a]);
        }
      printf("e%d",num3);
    }/*没有小数点*/ @@ [When there's no decimal point, the exponent should be (number of digits - 1), but the code uses i-1 as num3, then prints digits up to i-2, which may omit last digit or cause out-of-bound access.]
    else{
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-3;a++){
            printf("%c",num2[a]);
        }
        printf("e%d",num3);
    }//首位不是0 @@ [The loop bound i-3 is incorrect; it doesn't account for the actual position of the decimal point, leading to truncated output. The exponent calculation (num3 = a-1 from decimal location) is correct, but digit extraction ignores original structure.]
   
    return 0;
}
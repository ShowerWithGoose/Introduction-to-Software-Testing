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
        if(d!=i-4){ @@ [The condition `d != i-4` is arbitrary and incorrect. It leads to printing a decimal point even when there are no digits after the first non-zero digit, as in "0.9" → "9." instead of "9".]
        printf(".");
        for(int a=d+1;a<i-3;a++){ @@ [Loop bound `i-3` is incorrect and based on flawed assumptions about input length and newline handling. For input "0.9\n", `i` includes '\n', so `i-3` may exclude valid digits or include garbage.]
            printf("%c",num2[a]);
        }
        }
        else 
        {for(int a=d+1;a<i-2;a++){ @@ [Similarly, `i-2` is an arbitrary offset that doesn't correctly handle the actual digit positions after removing the decimal point.]
            printf("%c",num2[a]);
        }
        }
        printf("e-%d",num3);
    }//首位是0
    else if(i==b1){
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-2;a++){ @@ [Again, using `i-2` assumes fixed input structure including newline, which causes incorrect output when there's only one digit (e.g., would print "9." instead of "9" if applicable).]
            printf("%c",num2[a]);
        }
      printf("e%d",num3);
    }/*没有小数点*/
    else{
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-3;a++){ @@ [Same issue: `i-3` is not a reliable way to determine where significant digits end; it depends on newline inclusion and input length, leading to missing or extra characters.]
            printf("%c",num2[a]);
        }
        printf("e%d",num3);
    }//首位不是0
   
    return 0;
}
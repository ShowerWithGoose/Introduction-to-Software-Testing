#include <stdio.h>
int main() {
    char num[105],num2[105];
    int i=0,b=0,d,num3,b1=0;
    while(~scanf("%c",&num[i])) { // @@ Reads until EOF including newline, causing length mismatch and potential hang; should read until newline.
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
        for(int a=1;a<i;a++){ // @@ Uses i (length of num with newline) as bound for num2, should use b (actual length of num2).
            if(num2[a]!='0'){
                d=a; 
                num3=a;       
            break;
            }           
        }
        printf("%c",num2[d]);
        if(d!=i-4){ // @@ Incorrect magic number i-4 for checking remaining digits; should compare d with b-1.
        printf(".");
        for(int a=d+1;a<i-3;a++){ // @@ Incorrect loop bound i-3; should be a < b-1 to avoid printing newline and missing digits.
            printf("%c",num2[a]);
        }
        }
        else 
        {for(int a=d+1;a<i-2;a++){ // @@ Incorrect loop bound i-2; should be a < b-1.
            printf("%c",num2[a]);
        }
        }
        printf("e-%d",num3);
    }//首位是0
    else if(i==b1){
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-2;a++){ // @@ Incorrect loop bound i-2; should be a < b-1.
            printf("%c",num2[a]);
        }
      printf("e%d",num3);
    }/*没有小数点*/
    else{
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-3;a++){ // @@ Incorrect loop bound i-3; should be a < b-1.
            printf("%c",num2[a]);
        }
        printf("e%d",num3);
    }//首位不是0
   
    return 0;
}
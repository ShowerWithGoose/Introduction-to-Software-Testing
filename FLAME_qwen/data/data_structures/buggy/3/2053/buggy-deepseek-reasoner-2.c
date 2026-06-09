#include <stdio.h>
int main() {
    char num[105],num2[105];
    int i=0,b=0,d,num3,b1=0;
    while(~scanf("%c",&num[i])) { // @@ [Error: This loop reads until EOF, but input ends with newline. Should stop after reading newline. Also, using ~ of scanf is non-standard and will cause indefinite wait for more input.] 
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
        for(int a=1;a<i;a++){ // @@ [Error: Loop bound should be based on number of digits (b), not total characters i. i includes dot and newline, causing out-of-bounds access of num2.]
            if(num2[a]!='0'){
                d=a; 
                num3=a;       
            break;
            }           
        }
        printf("%c",num2[d]);
        if(d!=i-4){ // @@ [Error: Condition uses i-4, which is based on total characters, not number of digits. Incorrectly determines whether to print decimal point.]
        printf(".");
        for(int a=d+1;a<i-3;a++){ // @@ [Error: Loop bound uses i-3, incorrect. Should be based on number of digits (b) to print all remaining digits after first non-zero.]
            printf("%c",num2[a]);
        }
        }
        else 
        {for(int a=d+1;a<i-2;a++){ // @@ [Error: Loop bound uses i-2, incorrect. Same issue as above.]
            printf("%c",num2[a]);
        }
        }
        printf("e-%d",num3);
    }//首位是0
    else if(i==b1){
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-2;a++){ // @@ [Error: Loop bound uses i-2, incorrect. Should be based on number of digits (b) to print all digits after the first.]
            printf("%c",num2[a]);
        }
      printf("e%d",num3);
    }/*没有小数点*/
    else{
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-3;a++){ // @@ [Error: Loop bound uses i-3, incorrect. Should be based on number of digits (b) to print all digits after the first.]
            printf("%c",num2[a]);
        }
        printf("e%d",num3);
    }//首位不是0
   
    return 0;
}
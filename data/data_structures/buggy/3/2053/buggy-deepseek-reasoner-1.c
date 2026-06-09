#include <stdio.h>
int main() {
    char num[105],num2[105];
    int i=0,b=0,d,num3,b1=0;
    while(~scanf("%c",&num[i])) { 
    i++;
    }//存
    for(int a=0;a<i;a++){ // @@ [Error: Variable declaration inside for loop is not allowed in C89; may cause compilation error]
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
        for(int a=1;a<i;a++){ // @@ [Error: Variable declaration inside for loop is not allowed in C89; may cause compilation error]
            if(num2[a]!='0'){
                d=a; 
                num3=a;       
            break;
            }           
        }
        printf("%c",num2[d]);
        if(d!=i-4){
        printf(".");
        for(int a=d+1;a<i-3;a++){ // @@ [Error: Variable declaration inside for loop is not allowed in C89; may cause compilation error]
            printf("%c",num2[a]);
        }
        }
        else 
        {for(int a=d+1;a<i-2;a++){ // @@ [Error: Variable declaration inside for loop is not allowed in C89; may cause compilation error]
            printf("%c",num2[a]);
        }
        }
        printf("e-%d",num3);
    }//首位是0
    else if(i==b1){
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-2;a++){ // @@ [Error: Variable declaration inside for loop is not allowed in C89; may cause compilation error]
            printf("%c",num2[a]);
        }
      printf("e%d",num3);
    }/*没有小数点*/
    else{
        printf("%c",num2[0]);
        printf(".");
        for(int a=1;a<i-3;a++){ // @@ [Error: Variable declaration inside for loop is not allowed in C89; may cause compilation error]
            printf("%c",num2[a]);
        }
        printf("e%d",num3);
    }//首位不是0
   
    return 0;
}
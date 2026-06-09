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
        printf("%c",num2[d]); @@ // When the significant part has only one digit (like '9' in "0.9"), no decimal point should be printed, but this code may still print '.' due to incorrect condition below.
        if(d!=i-4){ @@ // The condition `d!=i-4` is arbitrary and incorrect. For input "0.9", i=3 ('\n' included?), d=1, so i-4 = -1, making condition true, leading to printing '.' unnecessarily.
        printf(".");
        for(int a=d+1;a<i-3;a++){ @@ // Loop bounds like `i-3` are based on wrong assumptions about input length including newline; this causes either missing digits or printing extra/invalid characters.
            printf("%c",num2[a]);
        }
        }
        else 
        {for(int a=d+1;a<i-2;a++){ @@ // Same issue: hardcoded offsets like `i-2` don't correctly reflect where actual digits end.
            printf("%c",num2[a]);
        }
        }
        printf("e-%d",num3);
    }//首位是0
    else if(i==b1){
        printf("%c",num2[0]);
        printf("."); @@ // If the original number has more than one digit before '.', e.g., "123", then output should be "1.23e2", which is correct here. But if input is single-digit integer like "5", it should output "5e0", not "5.e0". This always prints '.', causing wrong format when only one digit exists.
        for(int a=1;a<i-2;a++){ @@ // Again, using `i-2` assumes newline is at end and fixed offset, which is unreliable.
            printf("%c",num2[a]);
        }
      printf("e%d",num3);
    }/*没有小数点*/
    else{
        printf("%c",num2[0]);
        printf("."); @@ // Same as above: always prints decimal point even when only one significant digit exists (e.g., input "5.0" → should be "5e0", not "5.e0").
        for(int a=1;a<i-3;a++){ @@ // Incorrect loop bound due to hardcoded offset.
            printf("%c",num2[a]);
        }
        printf("e%d",num3);
    }//首位不是0
   
    return 0;
}
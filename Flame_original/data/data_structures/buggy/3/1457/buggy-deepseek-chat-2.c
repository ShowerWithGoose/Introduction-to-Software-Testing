#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0)
#include <ctype.h>
#include <stdlib.h>

int main(){
    char a[150];
    char str1[100],str2[100],str3[100];
    gets(a);
    int len=strlen(a);
    int cnt=0;
    int pos=0; 
    int s=0; 
    for(int i=0;i<len;i++){
        if(a[i]=='.'){
            s=i;//前面数字个数 
            pos=i+1;//下一数字位置 
            break;}
    }
    
    //前有0 带负号 
    if(a[s-1]=='0'){ // @@ [Error: If the input is "0.xxx", s is 0, then a[s-1] accesses a[-1] which is out-of-bounds, causing undefined behavior. Also, the logic for handling numbers like "0.001" is incorrect because it doesn't account for the case where the first non-zero digit is after the decimal point correctly.]
    for(int i=pos;i<len;i++){
        if(a[i]=='0')
            cnt++; 
        else break;
    }
    for(int i=pos+cnt+1,j=0;i<len;i++,j++){ // @@ [Error: If cnt counts all zeros after the decimal point and there is no non-zero digit (e.g., input "0.0"), then pos+cnt+1 may exceed len, leading to out-of-bounds access. Also, the loop condition i<len is correct, but if cnt is the number of zeros before the first non-zero digit, then pos+cnt is the index of the first non-zero digit, so pos+cnt+1 skips it incorrectly.]
        str1[j]=a[i];
    }
    int r=a[pos+cnt]-'0';//首位数字 // @@ [Error: If cnt is the number of zeros after the decimal point, then a[pos+cnt] is the first non-zero digit. However, if all digits after the decimal point are zero (e.g., "0.0"), then pos+cnt may be out-of-bounds or point to a non-digit character, causing undefined behavior.]
    if(a[pos+1]=='\0'){ // @@ [Error: This condition checks if the character after the decimal point is the null terminator, which would only be true for input like "0." which is invalid per problem description. The logic for handling the case where there is only one significant digit after the decimal point is flawed.]
        printf("%d",r);
        printf("e-%d",cnt+1);
    }
    else{
    
        printf("%d.",r);
        printf("%s",str1);
        printf("e-%d",cnt+1);}
    }
    else if(a[s-1]!='0'&&s==1){ // @@ [Error: This condition assumes that if the digit before the decimal point is non-zero and s==1, the number is like "1.23" and should be printed as "1.23e0". However, it does not handle cases where there are multiple digits before the decimal point (e.g., "12.34") or where the number is an integer (e.g., "5"). Also, it prints the entire input string including the decimal point, which is incorrect for scientific notation.]
        printf("%se0",a);
    }
    else{
        printf("%d.",a[0]-'0'); // @@ [Error: This assumes the first digit is the significant digit before the decimal point, but for numbers like "12.34", a[0] is '1', but the exponent should be 1, not 0. The logic for constructing the base and exponent is incorrect for numbers with more than one digit before the decimal point.]
        for(int i=1,j=0;i<pos-1;i++,j++){ // @@ [Error: This loop copies digits between the first digit and the decimal point, but for "12.34", pos=2, so i goes from 1 to 0, which is incorrect. It should copy digits from index 1 to pos-1, but the loop condition i<pos-1 is wrong when pos>1.]
            str2[j]=a[i];
        }
        for(int i=pos,j=0;i<len;i++,j++){ // @@ [Error: This loop copies digits after the decimal point, but it does not handle trailing zeros or the case where there are no digits after the decimal point (e.g., "5"). Also, it does not account for the fact that the base should have only one digit after the decimal point if it's a decimal.]
            str3[j]=a[i];
        }
        printf("%s",str2);
        printf("%s",str3);
        printf("e%d",s-1); // @@ [Error: The exponent should be the number of digits before the decimal point minus one, but for "12.34", s=2, so s-1=1, which is correct. However, for numbers like "1.23", s=1, so s-1=0, which is correct. But the base construction is wrong, so the overall output is incorrect.]
    }


return 0;
}
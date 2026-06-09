#include<stdio.h>
#include<string.h>
#include<ctype.h>
  int main(){
      char s[200];
      gets(s);
      char *p1=strchr(s,'.');//找出字符串中小数点的位置 
      int x=(p1-&s[0])/sizeof(char);//x是小数点的位置 
      int y=0;
      for(;y<strlen(s);y++){
          if(isdigit(s[y])&&s[y]!='0'){
              break;
          }
      }//循环结束后y的值就是第一个不为零的数的位置
      int a;
      if(x<y) a=x-y;
      else a=x-y-1; // @@ [Incorrect exponent calculation: when the first non-zero digit is after the decimal point (x < y), the exponent should be x - y + 1, not x - y. Also, when x > y (non-zero digit before decimal), it should be x - y - 1 only if y is before x, but logic fails for cases like "123.45". However, in this specific failing test case (0.0000000912...), x=1, y=9, so a = 1 - 9 = -8, which matches expected exponent, so exponent logic here accidentally works for this case. The real bug is elsewhere.]
    if((y+1)==x){ // @@ [This condition checks if the first non-zero digit is immediately before the decimal point (e.g., "5.0"), but in the test input "0.0000000912...", y=9 (pointing to '9'), x=1, so (y+1)==x is false. So this branch is skipped correctly. Not the main error.]
        
        printf("%s",s);
        printf("e0");
    }  
    else{
    if(s[0]=='-') printf("-");    // @@ [Problem states input has no sign, so this is unnecessary but harmless. Not the error.]
    printf("%c",s[y]);
    
    y++;
    if(isdigit(s[y])&&s[y]!='0'){ // @@ [This condition skips printing the decimal part if the next digit is '0' or not a digit. In the test input, after '9' comes '1', so it enters. But the real issue is in the while loop below.]
        printf(".");
    
    while(1){
        if(isdigit(s[y])&&s[y]!='0'){ // @@ [This loop stops as soon as it encounters a '0' digit, but the problem states "all digits are significant (i.e., there are no trailing zeros after the decimal point)". However, zeros *in the middle* (like in "9012") are significant and must be printed. The condition `s[y]!='0'` incorrectly omits any zero that appears after the first non-zero digit, even if it's not trailing. In the test input "0.00000009123456789012", after "9123456789" comes '0', which is significant (not trailing because followed by '12'), but this loop breaks at '0', truncating output to "9.123456789", missing "012". This is the primary error.]
            printf("%c",s[y]);
            y++;
        }else{
            break;
        }
    }
}
    printf("e");
    printf("%d",a);
}
      return 0;
  }
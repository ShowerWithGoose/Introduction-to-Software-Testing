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
      else a=x-y-1; // @@ [This calculation of exponent 'a' is incorrect. When the first non-zero digit is after the decimal point (as in 0.000...), x < y, and the correct exponent should be x - y + 1, not x - y. For example, in "0.00000009", x=1, y=8, exponent should be -7, but this gives -7 instead of -8 because it misses the adjustment needed for scientific notation normalization. However, the bigger issue is in output truncation below.]
    if((y+1)==x){
        
        printf("%s",s);
        printf("e0");
    }  
    else{
    if(s[0]=='-') printf("-");    
    printf("%c",s[y]);
    
    y++;
    if(isdigit(s[y])&&s[y]!='0'){
        printf(".");
    
    while(1){
        if(isdigit(s[y])&&s[y]!='0'){ // @@ [This loop stops at the first zero or non-digit, which incorrectly truncates significant trailing digits that are zero in the middle or end of the significant part. The problem states all digits are significant and there are no trailing zeros after the decimal point in input, but zeros between non-zero digits must be preserved. For input "0.00000009123456789012", this loop stops at the '0' in "9012", producing "9.123456789" instead of "9.123456789012".]
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
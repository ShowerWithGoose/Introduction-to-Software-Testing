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
      else a=x-y-1;
    if((y+1)==x){ // @@ This condition incorrectly handles the case when the first non‑zero digit is immediately after the decimal point. For example, "0.1" would incorrectly print the entire string and "e0" instead of "1e-1".
        
        printf("%s",s);
        printf("e0");
    }  
    else{
    if(s[0]=='-') printf("-");    
    printf("%c",s[y]);
    
    y++;
    if(isdigit(s[y])&&s[y]!='0'){ // @@ This condition incorrectly requires the next digit to be non‑zero before printing a decimal point. It will miss the decimal point and subsequent digits if the next digit is zero (e.g., for numbers like "0.001" the next digit is '0' but there are no further digits, but for numbers like "0.010" (if input allowed) it would be wrong). More importantly, it does not handle the case where the first non‑zero digit is before the decimal point (e.g., "1.23") because the next character is '.' which is not a digit, so no decimal point is printed.
        printf(".");
    
    while(1){
        if(isdigit(s[y])&&s[y]!='0'){ // @@ This condition incorrectly excludes zero digits. It breaks when a zero is encountered, causing significant zeros to be omitted. For the test input "0.00000009123456789012", it stops at the first zero after the non‑zero digits, printing only "9.123456789" instead of "9.123456789012".
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
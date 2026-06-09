#include<stdio.h>
#include<string.h>
#include<ctype.h>
  int main(){
      char s[200];
      gets(s); // @@ gets is deprecated/removed in C11, causing compilation errors in strict environments; use fgets instead.
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
    if((y+1)==x){
        
        printf("%s",s);
        printf("e0");
    }  
    else{
    if(s[0]=='-') printf("-");    
    printf("%c",s[y]);
    
    y++;
    if(isdigit(s[y])&&s[y]!='0'){ // @@ Incorrectly checks for non-zero before printing '.', causing missing decimal point and wrong output when fractional part starts with '0'.
        printf(".");
    
    while(1){
        if(isdigit(s[y])&&s[y]!='0'){ // @@ Incorrectly skips '0' digits in the fractional part, violating the requirement that all digits are significant.
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
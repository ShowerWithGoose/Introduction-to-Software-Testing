#include<stdio.h>
#include<string.h>
#include<ctype.h>
  int main(){
      char s[200];
      gets(s); // @@ [gets() is removed in the C11 standard and will cause a compilation error on modern compilers; use fgets() instead.]
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
    if(isdigit(s[y])&&s[y]!='0'){ // @@ [The condition incorrectly checks for non-zero digits, causing the decimal point to be omitted if the next character is '0' or '.', and fails to handle significant zeros in the middle of the number.]
        printf("."); // @@ [The decimal point should be printed whenever there are remaining digits after the first significant digit, not conditionally based on the next character being a non-zero digit.]
    
    while(1){ // @@ [Using an infinite loop with a break condition on non-digit or '0' is incorrect; it should iterate until the end of the string, skipping only the decimal point.]
        if(isdigit(s[y])&&s[y]!='0'){ // @@ [Same logical flaw as the previous condition; the loop breaks prematurely on '0' or '.', causing missing digits in the output.]
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
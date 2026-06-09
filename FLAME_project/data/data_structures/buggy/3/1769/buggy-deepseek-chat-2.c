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
    if((y+1)==x){
        
        printf("%s",s);
        printf("e0");
    }  
    else{
    if(s[0]=='-') printf("-");    
    printf("%c",s[y]);
    
    y++;
    if(isdigit(s[y])&&s[y]!='0'){ // @@ This condition incorrectly skips printing the decimal point and subsequent digits when the next digit after the first non-zero is '0', causing loss of trailing digits. For input "0.00000009123456789012", after printing '9', y points to '1', but the condition checks if s[y] is non-zero, which is true, so it prints '.' and then enters the while loop. However, the while loop condition also checks for non-zero digits, so it will stop at '0' digits, but the expected output includes all digits including zeros. The real issue is that the while loop should print all remaining digits after the decimal point, not just non-zero ones.
        printf(".");
    
    while(1){
        if(isdigit(s[y])&&s[y]!='0'){ // @@ This condition only prints non-zero digits, but the expected output requires printing all digits after the decimal point, including zeros. For the test case, after printing '9', the next digits are '1','2','3','4','5','6','7','8','9','0','1','2', but this loop will stop at the first '0' (the '0' after '9'), missing the rest.
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
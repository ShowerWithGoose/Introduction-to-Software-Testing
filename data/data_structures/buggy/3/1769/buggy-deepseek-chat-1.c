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
    if(isdigit(s[y])&&s[y]!='0'){ // @@ This condition is incorrect; it should check if there are more digits after the first non-zero digit to decide whether to print a decimal point, but the logic is flawed and may miss cases where the next digit is '0' but there are non-zero digits later.
        printf(".");
    
    while(1){
        if(isdigit(s[y])&&s[y]!='0'){ // @@ This loop only prints non-zero digits, but scientific notation requires printing all significant digits including zeros after the decimal point (except trailing zeros which are not present per problem description). The condition should be isdigit(s[y]) without the '!='0' check.
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
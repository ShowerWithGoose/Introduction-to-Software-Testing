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
    if(isdigit(s[y])&&s[y]!='0'){ // @@ The condition `s[y]!='0'` incorrectly stops printing significant digits if a '0' is encountered in the fractional part (e.g., in 9.123456789012, it stops after 9 because the next digit sequence eventually hits a 0 or logic breaks). It should print all remaining digits until the end of the string or null terminator, excluding the original decimal point position if necessary, but primarily it fails to include trailing significant zeros or digits following a zero. The loop structure itself is also flawed as it breaks on any non-digit or '0', whereas scientific notation requires preserving all significant digits from the first non-zero digit onwards.
        printf(".");
    
    while(1){
        if(isdigit(s[y])&&s[y]!='0'){ // @@ Same error as above: this condition causes the loop to terminate prematurely when it encounters a '0' digit which is significant (between other non-zero digits or at the end if specified as significant by input constraints). It should simply check `isdigit(s[y])` or ensure we haven't passed the end of the number string.
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
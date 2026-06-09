#include <stdio.h>
#include <string.h>
int main(){
   int i=0,c=0,d=0,mi=0,k=0,j=0,p=0,lenth=0;
   char str[1000];
   gets(str);
   lenth=strlen(str);
   for(i=lenth;i>0;i--){
      if(str[i]=='-'){                //判断字符串中有没有-
        if(('0'<=str[i-1]&&str[i-1]<str[i+1]&&str[i+1]<='9')||('A'<=str[i-1]&&str[i-1]<str[i+1]&&str[i+1]<='Z')||('a'<=str[i-1]&&str[i-1]<str[i+1]&&str[i+1]<='z')){   //判断-前后是否符合展开条件，如果符合
           c=(int)str[i-1];
           d=(int)str[i+1];      //记录前后两字符的ASCII码
           mi=d-c;             //记录ASCII码的差
           lenth=strlen(str);
           for(k=lenth;k>=i+1;k--){
             str[k+mi-2]=str[k];            //将i+1位上的字符统一往后移，保持不变
           }
           for(p=i,j=c+1;p<i+mi,j<d;p++,j++){
             str[p]=(char)j;                  //插入补充字符
           }
        }
      }
      else
        continue;
      }
    for(int q=0;q<strlen(str);q++){
       printf("%c",str[q]);
    }
   return 0;
}




